#!/bin/tcsh
./clean.sh
set keydir=`mktemp -d ./keys/XXXXXXXXXX`
echo "key $keydir made"
./keygen
cp key.txt $keydir
cp dictionary.txt $keydir
mv dictionary_index.txt $keydir
mv message_offsets.txt $keydir
mv message_positions.txt $keydir

cp -nR ./keys/* ./rxkeys

