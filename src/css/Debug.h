
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
	
	static std::ifstream file;
	
public:
	
	inline void Send( const std::string& msg );
	static InitFile( const std::string& fileName );
};

#endif

