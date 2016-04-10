#! /bin/bash

echo hello

read -p "input dir: " dir
filelist=$(ls $dir)
#filelist=`ls $dir`
for file in $filelist
do
    echo $file
done
