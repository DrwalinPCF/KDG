
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "../lib/MZ/SourceHeader/Vector.h"
#include "../lib/MZ/SourceHeader/VMatrix.h"
#include "../lib/MZ/SourceHeader/Quat.h"
#include "../lib/MZ/SourceHeader/Triangle.h"
#include "../lib/MZ/SourceHeader/AABB.h"
#include "../lib/MZ/SourceCode/Map.cpp"
#include "../lib/MZ/SourceCode/Array.cpp"

#include "Actor.h"
#include "PhysicsMesh.h"
#include "Engine.h"

namespace CollisionManager
{
	float pushingOutFactor = 10.0f;					//////////////////////
	
	// ActorOBB:
	void CollisionOBBOBB( ActorOBB * actorA, ActorOBB * actorB );
	void CollisionOBBStatic( ActorOBB * actorA, ActorStatic * actorB );
	
	
	
	inline void CollisionOBBActor( ActorOBB * actorA, Actor * actorB );
	
	inline void CollisionDynamicActor( ActorDynamic * actorA, Actor * actorB );
	
	inline void CollisionDynamic( ActorDynamic * actor );
	
	inline void CollisionActor( Actor * actor );
};

#endif

