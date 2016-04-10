#!/bin/bash

#----------------------------------------------------------------------------
#
#      if condition1
#      then
#          command1
#          command2
#          ...
#      elif condition2
#      then
#          commandX
#      else
#          commandN
#      fi
#
#----------------------------------------------------------------------------

# one-line command(usually for terminal)
if [ 1 -le 2 ]; then echo "1 -le 2"; fi


#----------------------------------------------------------------------------
#
#      for var in item1 item2 ... itemN
#      do
#          command1
#          command2
#          ...
#      done
#      
#      for var in item1 item2 ... itemN; do command1; command2 ...; done;
#
#----------------------------------------------------------------------------

for var in 1 2 3
do
    echo "The value is: $var"
done

for var in 4 5; do echo "The value is: $var"; done

for str in "hello" "world"
do
    echo "The str is: $str"
done

# omit list of "in" to using argument of command-line
for arg 
do
    echo "The argument is: $arg"
done

echo


#----------------------------------------------------------------------------
#
#      while condition
#      do
#          command
#      done
#      
# endless loop
#    1) while :
#    2) while true
#    3) for (( ; ; ))
#----------------------------------------------------------------------------

i=1
while (( $i <= 5 ))
do
    echo $i
    let "i++"
done

#echo 'press <CTRL-D> to quit'
#echo -n 'file name: '
#while read FILM
#do
#    echo "$FILM is a good film"
#    echo -n 'file name: '
#done

#while :
#do
#    echo "hello"
#done


#----------------------------------------------------------------------------
#
#      until condition
#      do
#          command
#      done
# 1) condition is false, enter loop
# 2) condition is true, quit loop
#----------------------------------------------------------------------------

declare -i i=10
declare -i sum=0
until ((i>10))
do
    let sum+=i
    let ++i
done
echo $sum


#----------------------------------------------------------------------------
#
#       case val in
#           pattern1)
#               command1
#               command2
#               ...
#               ;;          # means break in C
#           pattern2)
#               commandI
#               commandJ
#               ...
#               ;;
#           *)
#               default_case
#       esac
#----------------------------------------------------------------------------

echo -n "input num(1~4): "
read n
case $n in
    1) echo "you choose 1"
    ;;
    2) echo "you choose 2"
    ;;
    3) echo "you choose 3"
    ;;
    4) echo "you choose 4"
    ;;
    *) echo "Error"
    ;;
esac

#----------------------------------------------------------------------------
# break & continue
#----------------------------------------------------------------------------

#while true
#do
#    echo -n "input num(1~4): "
#    read n
#    case $n in
#        1|2|3|4) echo "you choose a num: $n"
#        ;;
#        *) echo "you didn't choose 1~4, over"
#            break
#        ;;
#    esac
#done
 

sum=0
i=0
while [ $i -ne 10 ]
do
    i=$(($i+1))
    #let i++
    sum=`expr $i + $sum`
done
echo $sum
