
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef ACTOR_OBB_CPP
#define ACTOR_OBB_CPP

#include "../css/ActorOBB.h"

inline String ActorOBB::GetClassName()
{
	return String( "ActorOBB" );
}

void ActorOBB::DrawDebug() const
{
	printf( "\n Error: ActorOBB::DrawDebug() is missing. " );
}

void ActorOBB::UpdateAABB()
{
	Vector x, y, z;
	GetAxes( x, y, z );
	aabb = AABB( position, position );
	aabb.AddPoint( position - x - y - z );
	aabb.AddPoint( position - x - y + z );
	aabb.AddPoint( position - x + y - z );
	aabb.AddPoint( position - x + y + z );
	aabb.AddPoint( position + x - y - z );
	aabb.AddPoint( position + x - y + z );
	aabb.AddPoint( position + x + y - z );
	aabb.AddPoint( position + x + y + z );
}

void ActorOBB::Update( const float deltaTime )
{
	ActorDynamic::Update( deltaTime );
}


#endif

