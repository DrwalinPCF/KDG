
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef PHYSICS_MESH_CPP
#define PHYSICS_MESH_CPP

#include "../css/PhysicsMesh.h"

inline String PhysicsMesh::GetClassName()
{
	return String( "PhysicsMesh" );
}

inline AABB PhysicsMesh::GetAABB() const
{
	return aabb;
}

void PhysicsMesh::SetName( const String& name )
{
	this->name = name;
}

int PhysicsMesh::LoadFromFile( const String& fileName, const int fileFormatVersion )
{
	printf( "\n Error: PhysicsMesh::LoadFromFile() is missing. " );
	/*
		Load from file to Array<Triangle*> triangles
		Update AABB aabb
		Update Collider<Triangle> collider
	*/
}

inline void PhysicsMesh::AccessTriangle( const AABB& aabb, Map < int, bool >& dst ) const
{
	if( triangles->size() )
	{
		collider.GetObject( aabb, dst );
	}
}

inline void PhysicsMesh::GetVertices( Array < Vector >& dst ) const
{
	dst = vertices;
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
	triangles = new Array < Int3 >;
}

PhysicsMesh::~PhysicsMesh()
{
	Clear();
	delete triangles;
}

#endif

