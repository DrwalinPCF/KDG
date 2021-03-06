
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef ACTOR_STATIC_CPP
#define ACTOR_STATIC_CPP

#include "../css/ActorStatic.h"

inline String ActorStatic::GetClassName()
{
	return String( "ActorStatic" );
}

void ActorStatic::DrawDebug() const
{
	printf( "\n Error: ActorStatic::DrawDebug() is missing. " );
}

void ActorStatic::UpdateAABB()
{
	if( physicsMesh )
	{
		aabb = ( (physicsMesh->GetAABB()*size).GetRotated( rotation )) + position;
	}
}

inline void ActorStatic::ColliderUpdated()
{
	colliderUpdateIsNeeded = false;
	if( physicsMesh )
	{
		physicsMesh->GetVertices( vertices );
		for( int i = 0; i < vertices.size(); ++i )
		{
			vertices[i] = ( rotation * ( vertices[i] * size ) ) + position;
		}
	}
}

inline void ActorStatic::GetTriangle( const int id, Triangle& triangle ) const
{
	if( physicsMesh )
	{
		Int3 temp;
		physicsMesh->GetTriangle( id, temp );
		triangle.Set( vertices[temp[0]], vertices[temp[1]], vertices[temp[2]] );
	}
}

inline bool ActorStatic::DoesColliderNeedUpdate() const
{
	return colliderUpdateIsNeeded;
}

inline void ActorStatic::SetPhysicsMesh( const PhysicsMesh * mesh )
{
	physicsMesh = (PhysicsMesh*)mesh;
}

inline PhysicsMesh * ActorStatic::GetPhysicsMesh() const
{
	return physicsMesh;
}

inline void ActorStatic::GetTriangles( const AABB& aabb, Array < int >& triangles ) const
{
	if( physicsMesh )
	{
		physicsMesh->AccessTriangle( (aabb-position).GetRotated( rotation.Inversed() ) / size, triangles );
	}
}

void ActorStatic::Update( const float deltaTime )
{
	printf( "\n Error: ActorStatic::Update() is not done yet. " );
	if( bPosition != position || bSize != size || bRotation != rotation )
	{
		UpdateAABB();
		colliderUpdateIsNeeded = true;
		bPosition = position;
		bSize = size;
		bRotation = rotation;
	}
}

ActorStatic::ActorStatic()
{
	physicsMesh = NULL;
	colliderUpdateIsNeeded = true;
}

ActorStatic::~ActorStatic()
{
	physicsMesh = NULL;
	colliderUpdateIsNeeded = false;
}

#endif

