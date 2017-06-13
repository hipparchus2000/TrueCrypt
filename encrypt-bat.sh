cp $1/* .
./encryptor
mkdir ./messages/keys
mv random.txt ./messages/$1
rm $1/*
rmdir $1

