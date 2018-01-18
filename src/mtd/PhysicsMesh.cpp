
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef PHYSICS_MESH_CPP
#define PHYSICS_MESH_CPP

#include "../css/PhysicsMesh.h"

inline std::string PhysicsMesh::GetClassName()
{
	return std::string( "PhysicsMesh" );
}

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

inline void PhysicsMesh::AccessTriangle( const AABB& aabb, std::vector < int >& dst ) const
{
	if( triangles->size() )
	{
		collider.GetObject( aabb, dst );
	}
}

inline void PhysicsMesh::GetVertices( std::vector < Vector >& dst ) const
{
	dst.resize( vertices.size() );
	if( vertices.size() )
	{
		memcpy( &(dst.front()), &(vertices.front()), sizeof(Vector) * vertices.size() );
	}
}

inline void PhysicsMesh::GetTriangle( const int id, Int3& dst ) const
{
	dst = triangles->at(id);
}

void PhysicsMesh::Clear()
{
	name = "";
	vertices.clear();
	triangles->clear();
	collider.Clear();
	aabb = AABB( Vector(), Vector() );
}

PhysicsMesh::PhysicsMesh()
{
	triangles = new std::vector < Int3 >;
}

PhysicsMesh::~PhysicsMesh()
{
	Clear();
	delete triangles;
}

#endif

