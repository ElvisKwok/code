#!/bin/bash

#----------------------------------------------------------------------------
# funcName (){
#     action
#     [return val]
# }
#----------------------------------------------------------------------------

func() {
    echo "hello"
}

func

func() {
    echo -n "a = "
    read a
    echo -n "b = "
    read b
    return $(($a+$b))
}
func
echo "last func return: $?"


# arguments
funcWithParam() {
    echo "argv[1]: $1"
    echo "argv[2]: $2"
    echo "argv[3]: $3"
    echo "argc: $#"
    echo "print all arg as a string: $*"
}

funcWithParam 1 2 3 4 5 6 7
