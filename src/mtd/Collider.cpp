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

template < class T >
inline String Collider<T>::GetClassName()
{
	return String( "Collider" );
}

template < class T >
void Collider<T>::AddObject( const T object, const AABB& aabbObject )
{
	if( object == NULL )
		return;
	
	AABBint aabbi( aabbObject, this->aabb, octtree.GetSpaceSizeAxes() );
	
	auto it = objectAABB.find( (T)object );
	if( it != objectAABB.end() )
	{
		if( it->val == aabbi )
			return;
		RemoveObject( (T)object );
	}
	
	objectAABB[(T)object] = aabbi;
	
	if( octtree.PosNotEnable( aabbi.GetMinX(), aabbi.GetMinY(), aabbi.GetMinZ() ) || octtree.PosNotEnable( aabbi.GetMaxX(), aabbi.GetMaxY(), aabbi.GetMaxZ() ) )
	{
		outsideObject[(T)object] = true;
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
					octtree.Get( pos[0], pos[1], pos[2] )[(T)object] = true;
				}
			}
		}
	}
}

template < class T >
void Collider<T>::RemoveObject( const T object )
{
	if( object == NULL )
		return;
	
	auto it = objectAABB.find( (T)object );
	if( it != objectAABB.end() )
	{
		AABBint aabbi = it->val;
		
		if( octtree.PosNotEnable( aabbi.GetMinX(), aabbi.GetMinY(), aabbi.GetMinZ() ) || octtree.PosNotEnable( aabbi.GetMaxX(), aabbi.GetMaxY(), aabbi.GetMaxZ() ) )
		{
			outsideObject.erase( (T)object );
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
						octtree.Get( pos[0], pos[1], pos[2] ).erase( (T)object );
					}
				}
			}
		}
	}
}

template < class T >
void Collider<T>::GetObject( const AABB& aabbSrc, Map < T, bool >& objects ) const
{
	if( outsideObject.size() > 0 )
		objects.insert( outsideObject );
	
	Map < T, bool > temp;
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
					if( octtree.Get( pos[0], pos[1], pos[2], temp ) )
					{
						objects.insert( temp );
					}
				}
			}
		}
	}
}

template < class T >
void Collider<T>::GetObject( const AABB& aabbSrc, Map < T, AABB >& objects ) const
{
	if( outsideObject.size() > 0 )
	{
		for( auto it = outsideObject.begin(); it != outsideObject.end(); *it++ )
			objects.insert[it->key] = objectAABB.find[it->key];
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
						objects.insert[it->key] = objectAABB.find[it->key];
				}
			}
		}
	}
}

template < class T >
void Collider<T>::GetAllObject( Array < T >& objects ) const
{
	objects.resize( objectAABB.size() );
	int i = 0;
	auto it = objectAABB.begin();
	for( ; it != objectAABB.end(); *it++, ++i )
	{
		objects[i] = it->key;
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
	octtree.Init( levels, Map < T, bool >() );
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

