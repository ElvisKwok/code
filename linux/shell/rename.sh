#!/bin/bash

for var in `ls`
do
    mv $var `echo $var | awk -F '_' '{if(length($1)==2) print "0"$1"_"$2}'`
    mv $var `echo $var | awk -F '_' '{if(length($1)==1) print "00"$1"_"$2}'`
done
