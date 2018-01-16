
#ifndef ACTOR_OBB_CPP
#define ACTOR_OBB_CPP

#include "../css/ActorOBB.h"

void ActorOBB::DrawDebug() const
{
	printf( "\n Error: ActorOBB::DrawDebug() is missing. " );
}

void ActorOBB::UpdateAABB()
{
	Vector x, y, z;
	GetAxes( x, y, z );
	aabb = AABB( possition, possition );
	aabb.AddPoint( possition - x - y - z );
	aabb.AddPoint( possition - x - y + z );
	aabb.AddPoint( possition - x + y - z );
	aabb.AddPoint( possition - x + y + z );
	aabb.AddPoint( possition + x - y - z );
	aabb.AddPoint( possition + x - y + z );
	aabb.AddPoint( possition + x + y - z );
	aabb.AddPoint( possition + x + y + z );
}

void ActorOBB::Update( const float deltaTime )
{
	ActorDynamic::Update( deltaTime );
}


#endif

