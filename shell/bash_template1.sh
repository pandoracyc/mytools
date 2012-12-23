#!/bin/bash
##########################################################################
# template1.sh [ARG1]
# ex.
# ./template1.sh A
##########################################################################


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
#. template.conf
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
while read i
do
	echo $i
done <tmp.txt



#=========================================================================
# FINALIZE
#=========================================================================
rm -f tmp.txt

exit 0
