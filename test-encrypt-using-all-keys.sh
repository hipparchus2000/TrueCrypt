#!/bin/tcsh
foreach file (keys/*)
./encrypt-bat.sh $file
end

