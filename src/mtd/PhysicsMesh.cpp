
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

inline void PhysicsMesh::AccessTriangle( const AABB& aabb, std::vector < Triangle >& dst ) const
{
	if( triangles.size() )
	{
		std::vector < Triangle* > temp;
		collider.GetObject( aabb, temp );
		
		if( temp.size() )
		{
			dst.resize( temp.size() );
			Triangle* dstp = &(dst[0]);
			Triangle** srcp = &(temp[0]);
			for( ; dstp <= (temp.back()); ++dstp, ++srcp )
			{
				memcpy( dstp, *srcp, sizeof(Triangle) );
			}
		}
	}
}

inline void PhysicsMesh::AccessAllTriangle( std::vector < Triangle >& dst ) const
{
	if( triangles.size() )
	{
		dst.resize( triangles.size() );
		Triangle* dstp = &(dst[0]);
		Triangle** srcp = (Triangle**)(&(triangles[0]));
		for( ; dstp <= (triangles.back()); ++dstp, ++srcp )
		{
			memcpy( dstp, *srcp, sizeof(Triangle) );
		}
	}
}

PhysicsMesh::~PhysicsMesh()
{
	collider.Clear();
	for( int i = 0; i < triangles.size(); ++i )
	{
		delete triangles[i];
	}
	triangles.clear();
}

#endif

