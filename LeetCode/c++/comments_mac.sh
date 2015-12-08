#!/bin/bash
set -e

AUTHOR="Elvis Kwok"
LEETCODE_URL=https://leetcode.com/problems/
LEETCODE_NEW_URL=https://leetcode.com/problems/
LEETCODE_OLD_URL=https://oj.leetcode.com/problems/
COMMENT_TAG="//"
FILE_EXT=".cc"

function usage()
{

    echo -e "Usage: ${0} [url] [source_file]"
    echo -e ""
    echo -e "Example:"
    echo -e ""
    echo -e "   1) Create a file named largestNumber.cc, and add Copyright & Problem description"
    echo -e "   ${0} https://leetcode.com/problems/largest-number/"
    echo -e ""
    echo -e "   2) Add Copyright & Problem description into existed file"
    echo -e "   ${0} https://leetcode.com/problems/largest-number/ largestNumber.cc"
    echo -e ""
}

function install_xidel()
{
    echo "Install xidel ..."
    if [ ! -d ./xidel ]; then
        mkdir xidel
    fi
    cd xidel
    linux=`uname -m`
    xidel_tar=xidel-0.9.linux64.tar.gz
    case $linux in
        x86_64 )    xidel_tar=xidel-0.9.linux64.tar.gz
                    ;;
          i686 )    xidel_tar=xidel-0.9.linux32.tar.gz
                    ;;
             * )    echo "Cannot install xidel, please install it manually!"
                    exit 1;
    esac
    if [ ! -f ${xidel_tar} ]; then
        echo "Downloading xidel....."
        curl -L http://sourceforge.net/projects/videlibri/files/Xidel/Xidel%200.9/${xidel_tar}/download -o ${xidel_tar}
    fi
    tar -zxvf ${xidel_tar}
    ./install.sh
    cd ..
    echo "Install xidel successfullly !"
}

if [ $# -lt 1 ] || [[ "${1}" != ${LEETCODE_NEW_URL}* ]] && [[ "${1}" != ${LEETCODE_OLD_URL}* ]]; then
    usage
    exit 255
fi

if [[ "${1}" == ${LEETCODE_OLD_URL}* ]]; then
    LEETCODE_URL=${LEETCODE_OLD_URL}
fi

IS_SHELL=`curl ${1} 2>/dev/null | grep Bash |wc -l`
if [ ${IS_SHELL} -gt 0 ]; then
    COMMENT_TAG='#'
    FILE_EXT='.sh'
fi


leetcode_url=$1
current_time=`date +%Y-%m-%d`

if [ $# -gt 1 ] && [ -f $2 ]; then
    source_file=$2
    # mac differ from linux in comman "stat"
    # current_time=`stat -c %x ${source_file} | awk '{print \$1}'`
    current_time=`stat -f %Sa -t %Y-%m-%d\ %H:%M:%S ${source_file}`
else
    # delete the shortest matched pattern of ${LEETCODE_URL} from $1
    # e.g., gets "letter-combinations-of-a-phone-number/" of the following $1 and ${LEETCODE_URL}
    # https://leetcode.com/problems/letter-combinations-of-a-phone-number/
    # https://leetcode.com/problems/
    source_file=${1#${LEETCODE_URL}}
    # remove last char
    # gets "letter-combinations-of-a-phone-number"
    source_file=${source_file::${#source_file}-1}
    # seperated by '-', then capitalize each section
    # gets "LetterCombinationsOfAPhoneNumber"
    source_file=`echo $source_file | awk -F '-' '{for (i=1; i<=NF; i++) printf("%s", toupper(substr($i,1,1)) substr($i,2)) }'`${FILE_EXT}

    if [ ! -f ${source_file} ]; then
        echo "Create a new file - ${source_file}."
        echo -e "\n" > ${source_file}
        current_time=`date +%Y-%m-%d`
    else
        # current_time=`stat -c %x ${source_file} | awk '{print \$1}'`
        current_time=`stat -f %Sa -t %Y-%m-%d\ %H:%M:%S ${source_file}`
    fi
fi

# the source file is existed but it is empty, add a line, 
# otherwise it could casue the comments inserts failed.
if [ ! -s $source_file ]; then
    echo "" > $source_file 
fi

#adding the Copyright Comments
if  ! grep -Fq  "${COMMENT_TAG} Author :" $source_file ; then
    sed -i '1i\'"${COMMENT_TAG} Source : ${leetcode_url}" $source_file
    sed -i '2i\'"${COMMENT_TAG} Author : ${AUTHOR}" $source_file
    sed -i '3i\'"${COMMENT_TAG} Date   : ${current_time}\n" $source_file
fi

#grab the problem description and add the comments
xidel=`type -P xidel || /bin/true`
if [ -z "${xidel}" ]; then
    echo "xidel not found !"
    install_xidel
fi

# using xidel grab the problem description
# 1) the `fold` command is used to wrap the text at centain column
# 2) the last two `sed` commands are used to add the comments tags
case $FILE_EXT in
    .cc )      xidel ${leetcode_url} -q -e "css('div.question-content')"  | \
                    grep -v '                ' |sed '/^$/N;/^\n$/D'  | fold -w 85 -s |\
                    sed 's/^/ * /' | sed "1i/*$(printf '%.0s*' {0..80}) \n * " | \
                    sed "\$a \ $(printf '%.0s*' {0..80})*/\n" > /tmp/tmp.txt
                ;;
    .sh )      xidel ${leetcode_url} -q -e "css('div.question-content')"  | \
                    grep -v '                ' |sed '/^$/N;/^\n$/D'  | fold -w 85 -s| \
                    sed 's/^/# /' | sed "1i#$(printf '%.0s#' {0..80}) \n# " | \
                    sed "\$a \#$(printf '%.0s#' {0..80})\n" > /tmp/tmp.txt
                ;;
      * )       echo "Bad file extension!"
                exit 1;

esac

#insert the problem description into the source file, and remove it
sed -i '4 r /tmp/tmp.txt' ${source_file}
rm -f /tmp/tmp.txt

echo "${source_file} updated !"
