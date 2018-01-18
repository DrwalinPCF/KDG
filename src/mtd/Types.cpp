
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef TYPES_CPP
#define TYPES_CPP

#include "../css/Types.h"

// Int3:

inline int& Int3::operator () ( const int id )
{
	return data[id];
}

inline int& Int3::operator [] ( const int id )
{
	return data[id];
}

Int3::Int3( const int a, const int b, const int c )
{
	data[0] = a;
	data[1] = b;
	data[2] = c;
}

Int3::Int3()
{
}

#endif

