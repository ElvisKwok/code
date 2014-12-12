#!/bin/sh

echo "" > $1

for (( i=0; i<10; i++ ))
do
    ./a.out >> $1;
done

echo $i"次测试中"
echo "比遗传算法好的次数："
grep g $1 | wc -l
echo "比模拟退火好的次数："
grep s $1 | wc -l
