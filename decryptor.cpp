// Copyright (c) 2004, Jeff Davies (editor@aliensarehere.com) 
//  
//You may distribute under the terms of the GNU General Public License as
//specified in the licence file that comes with the TRUSTKEY source 
//distribution.
 
#include <fstream>
#include <stdlib.h>
#include <string>
   
# include <iostream>
using namespace std;

int main()
{

int dict_max=100, msg_max=50, block_size=10000;
ifstream fkey ("key.txt");
fkey >> dict_max;
fkey >> msg_max;
fkey >> block_size;
fkey.close();   

{

string dictionary[dict_max];
int dictionary_index[dict_max];
int dictionary_flag[dict_max];
int message[msg_max];
int message_positions[msg_max];
int message_offsets[msg_max];
int random_block[block_size];
int count,i,find,found;
string word;


ifstream dictidx ("dictionary_index.txt");
count=0;
while ((dictidx.eof()==false) && (count < dict_max)) 
  { dictidx >> dictionary_index[count] ; count++; };
dictidx.close();


ifstream dict ("dictionary.txt");
count=0;
while ((dict.eof()==false) && (count < dict_max))  
  { dict >> dictionary[count] ; count++; };
dict.close();

ifstream mo ("message_offsets.txt");
ifstream mp ("message_positions.txt");
for(i=0;i<(msg_max);i++) {
  mo >>	message_offsets[i];
  mp >> message_positions[i];
};
mo.close(); mp.close();

ifstream rb ("random.txt"); int rbd;
for(i=0;i<block_size;i++) rb >> random_block[i];
rb.close();

for(i=0;i<msg_max;i++) 
	message[i]=random_block[message_positions[i]]-message_offsets[i];

char *crlf="\r\n";
ofstream msgo ("message-out.txt");
for(i=0;i<msg_max;i++) msgo << dictionary[dictionary_index[message[i]]] << crlf;
msgo.close();

};

} //end of main context
