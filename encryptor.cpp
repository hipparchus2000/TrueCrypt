// Copyright (c) 2004, Jeff Davies (editor@aliensarehere.com) 
//  
//You may distribute under the terms of the GNU General Public License as
//specified in the licence file that comes with the TRUSTKEY source 
//distribution.
 
#include <fstream>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "ran.cpp"
using namespace std;

int main()
{
int dict_max, msg_max, block_size;
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
  { dict >> word; dictionary[count]=word ; count++; };
dict.close();

ifstream mo ("message_offsets.txt");
ifstream mp ("message_positions.txt");
for(i=0;i<(msg_max);i++) {
  mo >>	message_offsets[i];
  mp >> message_positions[i];
};
mo.close(); mp.close();

count=0;
ifstream msg ("message.txt");
while ((msg.eof()==false) && (count<(msg_max))) {
	msg >> word; find=0; found=-1 ;

 	do {	
	  found=(word.compare(dictionary[dictionary_index[find]]));
	  find++; 
	} while ((found!=0) && (find<dict_max));
	if (found!=0) { 
	   cout << "word " << word << " not found in dictionary, retry\r\n";
 	   return (1);
	} else {
  	   message[count]=find-1;
	};
	count++;
} 
int length_of_message=count;
msg.close();

// fill random block
for(i=0;i<block_size;i++) random_block[i]=int(ran()*(dict_max*2));

// feed augmented array of message into random block
for(i=0;i<length_of_message;i++) 
    random_block[message_positions[i]]=message[i]+message_offsets[i];

// save block to disk
char *crlf="\r\n"; 
std::ofstream rndm ("random.txt");
for(i=0;i<block_size;i++) rndm << random_block[i] << crlf;
rndm.close();

}; //end of large var context

} //end of main context
