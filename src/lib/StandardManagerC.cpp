
#pragma once

#include <vector>
#include <map>



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




