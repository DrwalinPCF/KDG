
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

#include "PhysicsBody.h"
#include "Engine.h"
#include "ActorStatic.h"
#include "ActorDynamic.h"
#include "ActorOBB.h"

namespace CollisionManager
{
	// ActorOBB:
	void CollisionOBBOBB( ActorOBB * actorA, ActorOBB * actorB );
	void CollisionOBBStatic( ActorOBB * actorA, ActorStatic * actorB );
	
	
	
	inline void CollisionOBBActor( ActorOBB * actorA, Actor * actorB );
	
	inline void CollisionDynamicActor( ActorDynamic * actorA, Actor * actorB );
	
	inline void CollisionDynamic( ActorDynamic * actor );
	
	inline void CollisionActor( Actor * actor );
};

#endif

