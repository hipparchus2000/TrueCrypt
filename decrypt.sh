./clean.sh
mv ./rxkeys/$1/* .
mv ./messages/$1 ./random.txt
./decryptor
cat message-out.txt | grep -v "-"|more
rmdir ./rxkeys/$1

