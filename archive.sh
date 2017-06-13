#!/bin/tcsh
set cryptbackup=`pwd`
cd ..
set ARCFILE=crypt`date "+%Y%m%d%H%M%S"`.tar.gz
tar -zcf $ARCFILE crypt
mv $ARCFILE crypt.bak.d
cd $cryptbackup


