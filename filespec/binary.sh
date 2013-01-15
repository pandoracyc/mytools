#!/bin/bash
##########################################################################
# binary.sh
##########################################################################
#=========================================================================
# INITIALIZE
#=========================================================================
#. template.conf
#. common_func.sh

#=========================================================================
# MAIN
#=========================================================================
echo read file : sample.dat
xxd sample.dat
echo 

echo run read.rb
./read.rb >sample.log
echo result is $?
echo


echo sample_head.csv
echo "---------------------------------------------------"
cat > test.html <<EOF
<H2>HEAD</H2>
<table border=1>
EOF
while read line
do 
	echo -en '<tr>\n<td>' >>test.html
	echo $line|sed 's%,%</td>\n<td>%g' >>test.html
	echo -e '</td>\n</tr>' >>test.html
	echo >>test.html
	echo >>test.html
done <sample_head.csv
echo 
cat >> test.html <<EOF
</table>



EOF
echo "---------------------------------------------------"




echo sample_body.csv
echo "---------------------------------------------------"
cat >> test.html <<EOF
<H2>BODY</H2>
<table border=1>
EOF
while read line
do 
	echo -en '<tr>\n<td>' >>test.html
	echo $line|sed 's%,%</td>\n<td>%g' >>test.html
	echo -e '</td>\n</tr>' >>test.html
	echo >>test.html
	echo >>test.html
done <sample_body.csv
cat >> test.html <<EOF
</table>
EOF
echo "---------------------------------------------------"
#echo run write.rb
#./write.rb >>sample.log
#echo result is $?
#echo
#
#echo read file : sample_out.dat
#xxd sample_out.dat
#echo 
#
#diff -s sample.dat sample_out.dat

#=========================================================================
# FINALIZE
#=========================================================================
#rm -f tmp.txt

exit 0
