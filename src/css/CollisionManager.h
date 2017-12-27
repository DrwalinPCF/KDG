
#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "../Includer.h"

class CollisionManager
{
private:
	
	static Game * game = NULL;
	
	static void Collision( ActorDynamic * actorA, ActorDynamic * actorB );
	static void Collision( ActorDynamic * actor, ActorStatic * terrain );
	
public:
	
	static void SetGame( Game * game );
	static void Collision( ActorDynamic * actor );
};

#endif

