# !/bin/bash
echo -n 'The Time and date are: '
d=`date`
echo $d
who
today=$(date +%y%m%d)
#ls /usr/bin -al > log.$today
echo -n 'exit status: '
echo $?
