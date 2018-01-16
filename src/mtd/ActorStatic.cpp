
#ifndef ACTOR_STATIC_CPP
#define ACTOR_STATIC_CPP

#include "../css/ActorStatic.h"

void ActorStatic::DrawDebug() const
{
	printf( "\n Error: ActorStatic::DrawDebug() is missing. " );
}

void ActorStatic::UpdateAABB()
{
	if( physicsMesh )
	{
		aabb = (physicsMesh->GetAABB().GetRotated( rotation )*size) + possition;
	}
}

inline void ActorStatic::ColliderUpdated()
{
	if( physicsMesh )
	{
		colliderUpdateIsNeeded = false;
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

inline void ActorStatic::GetTriangles( const AABB& aabb, std::vector < Triangle >& triangles ) const
{
	if( physicsMesh )
	{
		physicsMesh->AccessTriangle( ((aabb-possition)/size).GetRotated( rotation.Inversed() ), triangles );
	}
}

void ActorStatic::Update( const float deltaTime )
{
	printf( "\n Error: ActorStatic::Update(float) is not done. " );
	if( bPossition != possition || bSize != size || bRotation != rotation )
	{
		UpdateAABB();
		colliderUpdateIsNeeded = true;
		bPossition = possition;
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

