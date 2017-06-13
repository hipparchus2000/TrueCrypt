cp ./keys/$1/* .
./encryptor
mv random.txt ./messages/$1
rm ./keys/$1/*
rmdir ./keys/$1

