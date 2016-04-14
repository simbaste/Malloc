GREEN="\033[33;32m"
RED="\033[33;31m"
YEL="\033[33;33m"
RES="\e[0m"

echo -e $YEL"Test ls"; echo -e $RES
ls > /tmp/test; cat /tmp/test | (grep "Error" || grep "seg" ) && echo -e $RED"FAIL" || echo -e $GREEN"OK"

echo -e $YEL"Test ls -lah"; echo -e $RES
ls -lah  > /tmp/test 2>&1; cat /tmp/test | (grep "Error" || grep "seg" ) && echo -e $RED"FAIL" || echo -e $GREEN"OK"

echo  -e $YEL"Test ls /"; echo -e $RES
ls /  > /tmp/test 2>&1; cat /tmp/test | (grep "Error" || grep "seg" ) && echo -e $RED"FAIL" || echo -e $GREEN"OK"

echo -e $YEL"Test ls ~/"; echo -e $RES
ls ~/  > /tmp/test 2>&1; cat /tmp/test | (grep "Error" || grep "seg" )  && echo -e $RED"FAIL" || echo -e $GREEN"OK"

echo  -e $YEL"Test ls -R ../"; echo -e $RES
ls -R ../  > /tmp/test 2>&1; cat /tmp/test | (grep "Error" || grep "seg" )  && echo -e $RED"FAIL" || echo -e $GREEN"OK"

echo -e $YEL"Test ls -R ../../" ; echo -e $RES
ls -R ../../  > /tmp/test 2>&1; cat /tmp/test | (grep "Error" || grep "seg" ) && echo -e $RED"FAIL" || echo -e $GREEN"OK"

echo  -e $YEL"Test ls -R ../../../" ; echo -e $RES
 ls -R ../../../  > /tmp/test 2>&1 | (grep "Error" || grep "seg")  && echo -e $RED"FAIL" || echo -e $GREEN"OK"

 echo  -e $YEL"Test ls -R ../../../../"; echo -e $RES
 ls -R ../../../../  > /tmp/test 2>&1 | (grep "Error" || grep "seg")  && echo -e $RED"FAIL" || echo -e $GREEN"OK"

 echo -e $YEL"Test ls -R ../../../../../"; echo -e $RES
 ls -R ../../../../../ > /tmp/test 2>&1 | (grep "Error" || grep "seg")  && echo -e $RED"FAIL" || echo -e $GREEN"OK"

 echo -e $YEL"Test ls -lah / -R"; echo -e $RES
 ls -lah / -R > /tmp/test 2>&1 | (grep "Error" || grep "seg")  && echo -e $RED"FAIL" || echo -e $GREEN"OK"


#echo -e $YEL"Test vlc"; echo -e $RES
#vlc 2> /tmp/test ; cat /tmp/test | (grep "Error" || grep "seg" ) && echo -e $RED"FAIL" || echo -e $GREEN"OK"

#echo -e $YEL"Test wpa_gui"; echo -e $RES
#wpa_gui 2> /tmp/test ; cat /tmp/test | (grep "Error" || grep "seg" ) && echo -e $RED"FAIL" || echo -e $GREEN"OK"

echo -e $RES
