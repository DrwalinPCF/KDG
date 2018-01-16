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
		in a product, an acknowledgment in the product documentation is required.
	2.	Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.
	3.	This notice may not be removed or altered from any source distribution.
*/

#ifndef COLLIDER_CPP
#define COLLIDER_CPP

#include "../css/Collider.h"
#include "../lib/MZ/SourceCode/StandardManagerC.cpp"

template < class T >
void Collider<T>::AddObject( const T * object, const AABB& aabbObject )
{
	if( object == NULL )
		return;
	
	AABBint aabbi( aabbObject, this->aabb, octtree.GetSpaceSizeAxes() );
	
	auto it = objectAABB.find( (T*)object );
	if( it != objectAABB.end() )
	{
		if( it->second == aabbi )
			return;
		RemoveObject( (T*)object );
	}
	
	objectAABB[(T*)object] = aabbi;
	
	if( octtree.PosNotEnable( aabbi.GetMinX(), aabbi.GetMinY(), aabbi.GetMinZ() ) || octtree.PosNotEnable( aabbi.GetMaxX(), aabbi.GetMaxY(), aabbi.GetMaxZ() ) )
	{
		outsideObject[(T*)object] = true;
	}
	else
	{
		long long int pos[3];
		for( pos[0] = aabbi.GetMinX(); pos[0] <= aabbi.GetMaxX(); ++pos[0] )
		{
			for( pos[1] = aabbi.GetMinY(); pos[1] <= aabbi.GetMaxY(); ++pos[1] )
			{
				for( pos[2] = aabbi.GetMinZ(); pos[2] <= aabbi.GetMaxZ(); ++pos[2] )
				{
					octtree.Get( pos[0], pos[1], pos[2] )[(T*)object] = true;
				}
			}
		}
	}
}

template < class T >
void Collider<T>::RemoveObject( const T * object )
{
	if( object == NULL )
		return;
	
	auto it = objectAABB.find( (T*)object );
	if( it != objectAABB.end() )
	{
		AABBint aabbi = it->second;
		
		if( octtree.PosNotEnable( aabbi.GetMinX(), aabbi.GetMinY(), aabbi.GetMinZ() ) || octtree.PosNotEnable( aabbi.GetMaxX(), aabbi.GetMaxY(), aabbi.GetMaxZ() ) )
		{
			outsideObject.erase( (T*)object );
		}
		else
		{
			long long int pos[3];
			for( pos[0] = aabbi.GetMinX(); pos[0] <= aabbi.GetMaxX(); ++pos[0] )
			{
				for( pos[1] = aabbi.GetMinY(); pos[1] <= aabbi.GetMaxY(); ++pos[1] )
				{
					for( pos[2] = aabbi.GetMinZ(); pos[2] <= aabbi.GetMaxZ(); ++pos[2] )
					{
						octtree.Get( pos[0], pos[1], pos[2] ).erase( (T*)object );
					}
				}
			}
		}
	}
}

template < class T >
void Collider<T>::GetObject( const AABB& aabbSrc, std::map < T *, bool >& objects ) const
{
	if( outsideObject.size() > 0 )
		objects.insert( outsideObject );
	
	AABB dst;
	if( AABB::SharedPart( this->aabb, aabbSrc, dst ) )
	{
		AABBint aabbi( dst, this->aabb, octtree.GetSpaceSizeAxes() );
		
		long long int pos[3];
		for( pos[0] = aabbi.GetMinX(); pos[0] <= aabbi.GetMaxX(); ++pos[0] )
		{
			for( pos[1] = aabbi.GetMinY(); pos[1] <= aabbi.GetMaxY(); ++pos[1] )
			{
				for( pos[2] = aabbi.GetMinZ(); pos[2] <= aabbi.GetMaxZ(); ++pos[2] )
				{
					objects.insert( octtree.GetConst( pos[0], pos[1], pos[2] ) );
				}
			}
		}
	}
}

template < class T >
void Collider<T>::GetObject( const AABB& aabbSrc, std::map < T *, AABB >& objects ) const
{
	if( outsideObject.size() > 0 )
	{
		for( auto it = outsideObject.begin(); it != outsideObject.end(); *it++ )
			objects.insert[it->first] = objectAABB.find[it->first];
	}
	
	AABB dst;
	
	if( AABB::SharedPart( this->aabb, aabbSrc, dst ) )
	{
		AABBint aabbi( dst, this->aabb, octtree.GetSpaceSizeAxes() );
		
		long long int pos[3];
		for( pos[0] = aabbi.GetMinX(); pos[0] <= aabbi.GetMaxX(); ++pos[0] )
		{
			for( pos[1] = aabbi.GetMinY(); pos[1] <= aabbi.GetMaxY(); ++pos[1] )
			{
				for( pos[2] = aabbi.GetMinZ(); pos[2] <= aabbi.GetMaxZ(); ++pos[2] )
				{
					auto map = octtree.GetConst( pos[0], pos[1], pos[2] );
					for( auto it = map.begin(); it != map.end(); *it++ )
						objects.insert[it->first] = objectAABB.find[it->first];
				}
			}
		}
	}
}

template < class T >
void Collider<T>::GetObject( const AABB& aabb, std::vector < T* >& objects ) const
{
	//std::vector<T*> &a = objects;
	//std::map<T*,bool> &b = outsideObject;
	if( outsideObject.size() > 0 )
		//SumSortedVectorWithMapKeys < T*, bool > ( a, b );
		SumSortedVectorWithMapKeys < T*, bool > ( objects, outsideObject );
	
	AABB dst;
	
	if( AABB::SharedPart( this->aabb, aabb, dst ) )
	{
		AABBint aabbi( dst, this->aabb, octtree.GetSpaceSizeAxes() );
		
		long long int pos[3];
		for( pos[0] = aabbi.GetMinX(); pos[0] <= aabbi.GetMaxX(); ++pos[0] )
			for( pos[1] = aabbi.GetMinY(); pos[1] <= aabbi.GetMaxY(); ++pos[1] )
				for( pos[2] = aabbi.GetMinZ(); pos[2] <= aabbi.GetMaxZ(); ++pos[2] )
					SumSortedVectorWithMapKeys < T*, bool > ( objects, octtree.GetConst( pos[0], pos[1], pos[2] ) );
	}
}

template < class T >
void Collider<T>::Clear()
{
	octtree.Clear();
	outsideObject.clear();
	objectAABB.clear();
}

template < class T >
AABB Collider<T>::GetAABB() const
{
	return aabb;
}

template < class T >
Vector Collider<T>::GetSize() const
{
	return aabb.GetSize();
}

template < class T >
void Collider<T>::Init( const AABB& aabb, const int levels )
{
	this->aabb = aabb;
	octtree.Init( levels, std::map < T*, bool >() );
}

template < class T >
void Collider<T>::Destroy()
{
	Clear();
	aabb.Set( Vector( 0, 0, 0 ), Vector( 0, 0, 0 ) );
}

template < class T >
Collider<T>::Collider()
{
	aabb.Set( Vector( -1000, -1000, -1000 ), Vector( 1000, 1000, 1000 ) );
}

template < class T >
Collider<T>::~Collider()
{
	Destroy();
}

#endif

