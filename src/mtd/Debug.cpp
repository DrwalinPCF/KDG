
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef DEBUG_CPP
#define DEBUG_CPP

#include "../css/Debug.h"

inline void Debug::Send( const String& msg )
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

void Debug::InitFile( const String& fileName )
{
	file.open( fileName.c_str(), "w" );
	if( !file.good() )
	{
		printf( "\n Error: Debug can not open log file: \"%s\" ", fileName.c_str() );
	}
	Debug::fileName = fileName;
}

#endif

