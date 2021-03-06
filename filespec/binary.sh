#!/bin/bash
##########################################################################
# binary.sh
##########################################################################
#=========================================================================
# INITIALIZE
#=========================================================================
#. template.conf
#. common_func.sh
PREFIX=sample
EXTENSION=dat

#=========================================================================
# MAIN
#=========================================================================
LOG_FILE=${PREFIX}_${EXTENSION}.log
HEAD_CSV=${PREFIX}_head.csv
BODY_CSV=${PREFIX}_body.csv
OUTPUT_HTML=${PREFIX}_${EXTENSION}.html

echo read file : sample.dat
xxd sample.dat
echo 

echo "--------------------------------------------------------------------------------"
echo run read.rb ${PREFIX}_${EXTENSION}.conf
cat ${PREFIX}_${EXTENSION}.conf
./read.rb ${PREFIX} ${EXTENSION} >$LOG_FILE
echo result is $?
echo "--------------------------------------------------------------------------------"
echo

#--------------------------------------
# OUTPUT_HTML
#--------------------------------------
echo make $OUTPUT_HTML

#--------------------------------------
# read sample_head.csv
#--------------------------------------
cat > $OUTPUT_HTML <<EOF
<H2>HEAD</H2>
<table border=1>
EOF
while read line
do 
	echo -en '<tr>\n<td>' >>$OUTPUT_HTML
	echo $line|sed 's%,%</td>\n<td>%g' >>$OUTPUT_HTML
	echo -e '</td>\n</tr>' >>$OUTPUT_HTML
	echo >>$OUTPUT_HTML
done <$HEAD_CSV
echo 
cat >> $OUTPUT_HTML <<EOF
</table>



EOF


#--------------------------------------
# read sample_body.csv
#--------------------------------------
cat >> $OUTPUT_HTML <<EOF
<H2>BODY</H2>
<table border=1>
EOF
while read line
do 
	echo -en '<tr>\n<td>' >>$OUTPUT_HTML
	echo $line|sed 's%,%</td>\n<td>%g' >>$OUTPUT_HTML
	echo -e '</td>\n</tr>' >>$OUTPUT_HTML
	echo >>$OUTPUT_HTML
done <$BODY_CSV
cat >> $OUTPUT_HTML <<EOF
</table>
EOF



#echo run write.rb
#./write.rb >>#LOG_FILE
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
