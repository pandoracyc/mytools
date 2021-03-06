#!/bin/bash
##########################################################################
# template1.sh [ARG1]
# ex.
# ./template1.sh A
##########################################################################
# 割り込み処理 SIGINT(2)
trap 'echo trapped.; rm -f tmp.txt; exit 1' 2

#=========================================================================
# PARAMETER CHECK
#=========================================================================
# 引数チェック $#
# 0:なし
if [ $# -eq 0 ]
then
	echo help
	exit 127
fi

# 第1引数チェック
PARAMETER1=$1
case $PARAMETER1 in
A)
	echo A
	;;
*)
	echo invalid parameter.
	exit 127
	;;
esac


#=========================================================================
# INITIALIZE
#=========================================================================
# Read conf file
if [ -f template.conf ];then
	. template.conf
fi
#. common_func.sh

#TEMP_DIR="/tmp/"
echo TEST>tmp.txt
if [ $? != 0 ];then
	echo command error.
	exit 127
fi

#=========================================================================
# MAIN
#=========================================================================
#ファイル読み込み
while read i
do
	echo $i
done <tmp.txt

#loop 処理
for i in `seq 1 10`
do
	echo $i
done

#file 処理
for file in `ls -1`
#for file in `grep -rl search ./`
do
	echo $file
done

#=========================================================================
# FINALIZE
#=========================================================================
rm -f tmp.txt

exit 0
