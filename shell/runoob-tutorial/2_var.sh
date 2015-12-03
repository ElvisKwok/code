#!/bin/bash

# to define and assign the var, do not use '$'
your_name="Elvis"
# to get the value of the var, use '$'
echo $your_name
echo ${your_name}   # {} indicates the boundary of the var 

for skill in Ada Coffe Action Java
do
    echo "I am good at ${skill}Script"
done

#----------------------------------------------------------------------------
# STRING
# 
# why prefer using “” instead of ''
# "" allow using $var, and "\" as a escape character like "\n"
#----------------------------------------------------------------------------

# concatenation
greeting="Hello, "${your_name}" !"
greeting_1="Hello, ${your_name} !"
echo ${greeting}
echo ${greeting_1}
# slice
echo ${greeting_1:1:4}
# string length
echo ${#greeting}

#----------------------------------------------------------------------------
# ARRAY
#
# array_name=(val1 val2 val3)
# elements are splited by space ' '
# ${array_name[index]}
# array size & index are not limited
# index is not requred to be continuous
#----------------------------------------------------------------------------
#array_name=("str0" "str1" "str2")
#array_name=(str0 str1 str2)
array_name=(0 1 20)
# get all elements
echo ${array_name[@]}
echo ${array_name[*]}
# amount of elements(length of array)
echo ${#array_name[@]}
echo ${#array_name[*]}
# length of a given element
echo ${#array_name[2]}
