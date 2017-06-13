
// Copyright (c) 2004, Jeff Davies (editor@aliensarehere.com) 
//  
//You may distribute under the terms of the GNU General Public License as
//specified in the licence file that comes with the TRUSTKEY source 
//distribution.
 

#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "ran.cpp"

int main()
{
int dict_max, msg_max, block_size;

std::ifstream fkey ("key.txt");
fkey >> dict_max;
fkey >> msg_max;
fkey >> block_size;
fkey.close();

//seed the std random number generator
srand((unsigned)time(NULL));

{
int dictionary_index[dict_max];
int dictionary_flag[dict_max];
int message[msg_max];
int i,count;
float pval;

for (i=0;i<(dict_max);i++) dictionary_flag[i]=-1;

for (i=0;i<(dict_max);i++) {
    do { 
       	pval=int(ran()*dict_max);
    } while (dictionary_flag[(int)pval]!=-1);
    dictionary_index[i]=(int)pval;
    dictionary_flag[(int)pval]=0;
};

char *crlf="\r\n";

std::ofstream fdictidx ("dictionary_index.txt");
for(i=0;i<(dict_max);i++) fdictidx << dictionary_index[i] << crlf;
fdictidx.close();

std::ofstream franoff ("message_offsets.txt");
for (i=0;i<(msg_max);i++) franoff << int(ran() * dict_max) << crlf;
franoff.close();

std::ofstream fmsgpos ("message_positions.txt");
for (i=0;i<(msg_max);i++) fmsgpos << int(ran() * block_size) << crlf;
fmsgpos.close();

}; //end of context for arrays

} //end of context for settings file


