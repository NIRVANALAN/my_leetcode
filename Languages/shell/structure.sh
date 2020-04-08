# !/bin/bash

testuser=yushi
if grep $testuser /etc/passwd
then
	echo "The bash files for user $testuser are:"
	ls -a /home/$testuser/.b*
	echo
else
	echo 'No such testuser: $testuser'
fi
