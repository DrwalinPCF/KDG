
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef DEBUG_CPP
#define DEBUG_CPP

#include "../css/Debug.h"

inline void Debug::Send( const std::string& msg )
{
	if( file.good() )
	{
		printf( "\n Debug: \"%s\" ", msg.c_str() );
	}
	else
	{
		printf( "\n Error: Debug can not open log file: \"%s\" ", fileName.c_str() );
	}
}

static Debug::InitFile( const std::string& fileName )
{
	file.open( fileName.c_str() );
	if( !file.good() )
	{
		printf( "\n Error: Debug can not open log file: \"%s\" ", fileName.c_str() );
	}
}

#endif

