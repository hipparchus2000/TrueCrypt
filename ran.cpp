
// Copyright (c) 2004, Jeff Davies (editor@aliensarehere.com) 
//  
//You may distribute under the terms of the GNU General Public License as
//specified in the licence file that comes with the TRUSTKEY source 
//distribution.
 
#include <stdlib.h>
#include <time.h>

float ran() {
	float r=(float)rand();
	float s=(float)RAND_MAX;
	float t=r/s;
	return t ;
};



