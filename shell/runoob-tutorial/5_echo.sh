#!/bin/bash

#----------------------------------------------------------------------------
# echo - display a line of text
#    -n     do not output the trailing newline
#    -e     enable interpretation of backslash escapes (开启转义)
#    -E     disable interpretation of backslash escapes (default)
#    If -e is in effect, the following sequences are recognized:
#    \\     backslash
#    \a     alert (BEL)
#    \b     backspace
#    \c     produce no further output
#    \e     escape
#    \f     form feed
#    \n     new line
#    \r     carriage return
#    \t     horizontal tab
#    \v     vertical tab
#    \0NNN  byte with octal value NNN (1 to 3 digits)
#    \xHH   byte with hexadecimal value HH (1 to 2 digits)
# 
# NOTE: echo automatically append '\n' 
#----------------------------------------------------------------------------

echo -n "input your name: "
read name
echo "hello $name"

# -e enable '\', '\c' means continue printing
echo -e "1st part \c"
echo "2nd part"

# '' print everything inside it without change
echo '$name\"'

# display a command output
echo `date`


#----------------------------------------------------------------------------
# printf - format and print data
#
#   printf FORMAT [ARGUMENT]...
#
#   FORMAT controls the output as in C printf.  Interpreted sequences are:
#   \"     double quote
#   \\     backslash
#   \a     alert (BEL)
#   \b     backspace
#   \c     produce no further output
#   \e     escape
#   \f     form feed
#   \n     new line
#   \r     carriage return
#   \t     horizontal tab
#   \v     vertical tab
#   \NNN   byte with octal value NNN (1 to 3 digits)
#   \xHH   byte with hexadecimal value HH (1 to 2 digits)
#   %%     a single %
#
##----------------------------------------------------------------------------

printf "%-10s %-8s %-4s\n" 姓名 性别 体重kg  
printf "%-10s %-8s %-4.2f\n" 郭靖 男 66.1234 
printf "%-10s %-8s %-4.2f\n" 杨过 男 48.6543 
printf "%-10s %-8s %-4.2f\n" 郭芙 女 47.9876 

# 指定一个参数，但多出的参数将“重用”FORMAT
printf "%c\n" a b c
