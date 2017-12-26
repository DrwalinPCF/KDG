
#ifndef DEBUG_CPP
#define DEBUG_CPP

#include "Debug.h"

void Debug( const char * str )
{
	static unsigned long long int counter = 1;
	printf( "\n Debug(%18.18llu): %s", counter, str );
	++counter;
}

#endif

