
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef DEBUG_H
#define DEBUG_H

#include <cstdio>
#include "../lib/MZ/SourceHeader/File.h"

class Debug
{
private:
	
	static File file;
	static String fileName;
	
public:
	
	inline void Send( const String& msg );
	static void InitFile( const String& fileName );
};

#endif

