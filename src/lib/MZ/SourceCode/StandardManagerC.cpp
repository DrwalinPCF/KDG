/*
	Copyright (C) 2017 Marek Zalewski
	
	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.
	
	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1.	The origin of this software must not be misrepresented; you must not
		claim that you wrote the original software. If you use this software
		in a product, an acknowledgment is required.
	2.	Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.
	3.	This notice may not be removed or altered from any source distribution.
*/

#ifndef STANDARD_MANAGER_C_CPP
#define STANDARD_MANAGER_C_CPP

#include "../SourceHeader/StandardManagerC.h"

template < class T, class T2 >
void GetKeys( std::vector < T > & dst, std::map < T, T2 > & src )
{
	auto it = src.begin();
	
	int i, len = src.size();
	dst.resize( len );
	
	for( i = 0; i < len; ++i, *it++ )
	{
		dst[i] = it->first;
	}
}

template < class T, class T2 >
void GetValues( std::vector < T2 > & dst, std::map < T, T2 > & src )
{
	auto it = src.begin();
	
	int i, len = src.size();
	dst.resize( len );
	
	for( i = 0; i < len; ++i, *it++ )
	{
		dst[i] = it->second;
	}
}

template < class T >
void PushVectorBack( std::vector < T > & dst, std::vector < T > & src )
{
	int i, l = dst.size();
	dst.resize( l + src.size() );
	for( i = 0; i < l; ++l )
	{
		dst[l+i] = src[i];
	}
}

template < class T, class T2 >
bool HaveEqualPart( std::map < T, T2 > & src_a, std::map < T, T2 > & src_b )
{
	auto it = src_a.begin();
	//std::map < T, T2 > ::iterator elem;
	
	int i, len = src_a.size();
	
	for( i = 0; i < len; ++i, *it++ )
	{
		auto elem = src_b.find( it->first );
		if( elem != src_b.end() )
		{
			return true;
		}
	}
	
	return false;
}

template < class T, class T2 >
void GetEqualPart( std::vector < T > & dst, std::map < T, T2 > & src_a, std::map < T, T2 > & src_b )
{
	dst.clear();
	
	auto it = src_a.begin();
	//std::map < T, T2 > ::iterator elem;
	
	int i, len = src_a.size();
	
	for( i = 0; i < len; ++i, *it++ )
	{
		auto elem = src_b.find( it->first );
		if( elem != src_b.end() )
		{
			dst.push_back( it->first );
		}
	}
}

template < class T, class T2 >
void GetEqualPart( std::map < T, T2 > & dst, std::map < T, T2 > & src_a, std::map < T, T2 > & src_b )
{
	dst.clear();
	
	auto it = src_a.begin();
	//std::map < T, T2 > ::iterator elem;
	
	int i, len = src_a.size();
	
	for( i = 0; i < len; ++i, *it++ )
	{
		auto elem = src_b.find( it->first );
		if( elem != src_b.end() )
		{
			dst[ it->first ] = it->second;
		}
	}
}

template < class T, class T2 >
void MapPushBack( std::map < T, T2 > & dst, std::map < T, T2 > & src )
{
	for( auto it = src.begin(); it != src.end(); *it++ )
		dst[it->first] = it->second;
}

#endif

