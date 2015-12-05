#!/bin/bash

#----------------------------------------------------------------------------
# expr - evaluate expressions
# 
# surrounded by ` `, note the space,"2 + 2" "2+2" is wrong
#                                    ~^~^~                     
# 1) 算术运算符: +, -, *, /, %, =, ==, != (* should be escaped as \*)
# 2) 关系运算符:(only for numbers) -eq, -ne, -gt, -lt, -ge, -le
# 3) 布尔运算符: !(not), -o(or), -a(and)
# 4) 字符串运算符: =, !=, -z(Zero-length), -n(Not empty), str(same as "-n str")
# 5) 文件测试运算符
# condition test should put in [ ], note the space, like [ $a == $b ]
#                                                         ^~~~~~~~~^   
#----------------------------------------------------------------------------

a=10
b=20

#----------------------------------------------------------------------------
# 1) 算术运算符
#----------------------------------------------------------------------------
val=`expr $a + $b`
echo "a + b: $val"

if [ $a == $b ]
then
    echo "a == b"
fi

if [ $a != $b ]
then
    echo "a != b"
fi

echo

#----------------------------------------------------------------------------
# 2) 关系运算符
#----------------------------------------------------------------------------
if [ $a -eq $b ]
then
    echo "$a -eq $b"
else
    echo "$a -ne $b"
fi

echo

#----------------------------------------------------------------------------
# 3) 布尔运算符
#----------------------------------------------------------------------------
if [ $a -lt 100 -a $b -gt 15 ]
then 
    echo "$a -lt 100 -a $b -gt 15: return true"
else
    echo "$a -lt 100 -a $b -gt 15: return false"
fi

echo

#----------------------------------------------------------------------------
# 4) 字符串运算符
#----------------------------------------------------------------------------
a="abc"
b="efg"

if [ -z $a ]
then
    echo "-z $a: return true"
else
    echo "-z $a: return false"
fi

if [ -n $a ]
then
    echo "-n $a: return true"
else
    echo "-n $a: return false"
fi

if [ $a ]
then
    echo "$a: return true"
else
    echo "$a: return false"
fi

echo

#----------------------------------------------------------------------------
# 5) 文件测试运算符
#   * -b file: block device file?
#   * -c file: char device file?
#   * -f file: ordinary file(not dir or device file)
#   * -g file: SGID Bit is set?
#   * -k file: Sticky Bit is set?
#   * -p file: pipeline?
#   * -u file: SUID Bit is set?
#   * -r file: file readable?
#   * -w file: file writable?
#   * -x file: file excutable?
#   * -s file: Non-empty file?(size>0?)
#   * -e file: file exist?
#----------------------------------------------------------------------------
file=$1
echo "file name is ${file}"
if [ -r $file ]
then
    echo "readable"
else
    echo "not readable"
fi

if [ -w $file ]
then
    echo "writable"
else
    echo "not writable"
fi

if [ -x $file ]
then
    echo "excutable"
else
    echo "not excutadable"
fi

if [ -f $file ]
then
    echo "ordinary"
else
    echo "not ordinary"
fi

if [ -d $file ]
then
    echo "dir"
else
    echo "not dir"
fi

if [ -s $file ]
then
    echo "Non-empty"
else
    echo "empty"
fi

if [ -e $file ]
then
    echo "exist"
else
    echo "not exist"
fi

echo

#----------------------------------------------------------------------------
# NAME
#        test - check file types and compare values
# 
# SYNOPSIS
#        test EXPRESSION
#        test
# 
#        [ EXPRESSION ]
#        [ ]
#        [ OPTION
# 
# DESCRIPTION
#        Exit with the status determined by EXPRESSION.
# 
#        --help display this help and exit
# 
#        --version
#               output version information and exit
# 
#        An  omitted  EXPRESSION  defaults  to false.  Otherwise, EXPRESSION is true or false and sets
#        exit status.  It is one of:
# 
#        ( EXPRESSION )
#               EXPRESSION is true
# 
#        ! EXPRESSION
#               EXPRESSION is false
# 
#        EXPRESSION1 -a EXPRESSION2
#               both EXPRESSION1 and EXPRESSION2 are true
# 
#        EXPRESSION1 -o EXPRESSION2
#               either EXPRESSION1 or EXPRESSION2 is true
# 
#        -n STRING
#               the length of STRING is nonzero
# 
#        STRING equivalent to -n STRING
# 
#        -z STRING
#               the length of STRING is zero
# 
#        STRING1 = STRING2
#               the strings are equal
# 
#        STRING1 != STRING2
#               the strings are not equal
# 
#        INTEGER1 -eq INTEGER2
#               INTEGER1 is equal to INTEGER2
# 
#        INTEGER1 -ge INTEGER2
#               INTEGER1 is greater than or equal to INTEGER2
# 
#        INTEGER1 -gt INTEGER2
#               INTEGER1 is greater than INTEGER2
# 
#        INTEGER1 -le INTEGER2
#               INTEGER1 is less than or equal to INTEGER2
# 
#        INTEGER1 -lt INTEGER2
#               INTEGER1 is less than INTEGER2
# 
#        INTEGER1 -ne INTEGER2
#               INTEGER1 is not equal to INTEGER2
# 
#        FILE1 -ef FILE2
#               FILE1 and FILE2 have the same device and inode numbers
# 
#        FILE1 -nt FILE2
#               FILE1 is newer (modification date) than FILE2
# 
#        FILE1 -ot FILE2
#               FILE1 is older than FILE2
# 
#        -b FILE
#               FILE exists and is block special
# 
#        -c FILE
#               FILE exists and is character special
# 
#        -d FILE
#               FILE exists and is a directory
# 
#        -e FILE
#               FILE exists
# 
#        -f FILE
#               FILE exists and is a regular file
# 
#        -g FILE
#               FILE exists and is set-group-ID
# 
#        -G FILE
#               FILE exists and is owned by the effective group ID
# 
#        -h FILE
#               FILE exists and is a symbolic link (same as -L)
# 
#        -k FILE
#               FILE exists and has its sticky bit set
# 
#        -L FILE
#               FILE exists and is a symbolic link (same as -h)
# 
#        -O FILE
#               FILE exists and is owned by the effective user ID
# 
#        -p FILE
#               FILE exists and is a named pipe
# 
#        -r FILE
#               FILE exists and read permission is granted
# 
#        -s FILE
#               FILE exists and has a size greater than zero
# 
#        -S FILE
#               FILE exists and is a socket
# 
#        -t FD  file descriptor FD is opened on a terminal
# 
#        -u FILE
#               FILE exists and its set-user-ID bit is set
# 
#        -w FILE
#               FILE exists and write permission is granted
# 
#        -x FILE
#               FILE exists and execute (or search) permission is granted
#----------------------------------------------------------------------------

num1=100
num2=100
if test ${num1} -eq ${num2}
then
    echo "equal"
else
    echo "not equal"
fi
