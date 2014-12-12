#!/bin/sh

echo "" > output.txt

for (( i=0; i<40; i++ ))
do
    ./a.out >> ./output.txt;
done

echo $i"次测试中"
echo "比遗传算法好的次数："
grep g output.txt | wc -l
echo "比模拟退火好的次数："
grep s output.txt | wc -l
