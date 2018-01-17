
#ifndef PHYSICS_MESH_CPP
#define PHYSICS_MESH_CPP

#include "../css/PhysicsMesh.h"

inline AABB PhysicsMesh::GetAABB() const
{
	return aabb;
}

void PhysicsMesh::SetName( const std::string& name )
{
	this->name = name;
}

int PhysicsMesh::LoadFromFile( const std::string& fileName, const int fileFormatVersion )
{
	printf( "\n Error: PhysicsMesh::LoadFromFile() is missing. " );
	/*
		Load from file to std::vector<Triangle*> triangles
		Update AABB aabb
		Update Collider<Triangle> collider
	*/
}

inline bool PhysicsMesh::AccessTriangle( const int id, Triangle& dst )
{
	if( id < 0 )
		return false;
	if( id < triangles.size() )
	{
		dst = triangles[id];
		return true;
	}
	return false;
	
}

inline void PhysicsMesh::AccessTriangle( const AABB& aabb, std::vector < Triangle >& dst ) const
{
	if( triangles.size() )
	{
		std::vector < int > temp;
		collider.GetObject( aabb, temp );
		
		if( temp.size() )
		{
			dst.resize( temp.size() );
			int i;
			for( i = 0; i < temp.size(); ++i )
				dst[i] = triangles[temp[i]];
		}
	}
}

inline void PhysicsMesh::AccessAllTriangle( std::vector < Triangle >& dst ) const
{
	dst.resize( triangles.size() );
	memcpy( &(dst.front()), &(triangles.front()), triangles.size() * sizeof(Triangle) );
	//dst = triangles;
}

PhysicsMesh::~PhysicsMesh()
{
	collider.Clear();
	triangles.clear();
}

#endif

