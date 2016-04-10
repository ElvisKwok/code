#!/bin/bash

echo "Shell 传递参数实例！"
echo "[\$1]1st argument: $1"
echo "2nd argument: $2"
echo "3rd argument: $3"

echo "[\$#]参数个数: $#"
echo "[\$*]all argument as a string: $*"
echo "[\$@] is similar to [\$*]: $@"
echo "[\$\$]current pid of this script: $$"
echo "[\$!]last pid in background: $!"
echo "[\$-]what option applied in Shell(silimar to command set): $-"
echo "[\$?]exit status(0 for not error): $?"

shift 1
echo "the all parameter now is: $@"
echo "[\$#]参数个数: $#"

shift 1
echo "the all parameter now is: $@"
echo "[\$#]参数个数: $#"

shift 1
echo "the all parameter now is: $@"
echo "[\$#]参数个数: $#"
