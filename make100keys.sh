#!/bin/tcsh
set i=0
while ($i <= 100) 
  ./makekey.sh
  set i=`expr $i + 1`
  echo $i
end
