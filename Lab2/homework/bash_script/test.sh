#!/bin/bash

#variable
myname="Tai"

#expression
expresion=`expr 10 + 30`

#array string
myArr=("Nguyen" "Huy" "Tai")
numsize=${#myArr[@]}

echo $numsize
index=2

#read index = 2
string=${myArr[${index}]}
echo $string

#loop for through arr
for str in ${myArr[@]}; do
    echo $str
done

#loop for not through arr
for i in ${!myArr[@]}; do
    echo "element $i is ${myArr[${i}]}"
done

#read 2 integer
read -p "Enter" x

echo "Enter x: "
read x
echo "Enter y: "
read y

multiple=`expr $x \* $y`

echo "Hello $myname"
echo $expresion
echo "res: $multiple"

#assign to another variable
moved=$multiple
echo $moved