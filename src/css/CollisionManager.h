
#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "../Includer.h"

class CollisionManager
{
private:
	
	static Engine * engine = NULL;
	
	static void Collision( ActorDynamic * actorA, ActorDynamic * actorB );
	static void Collision( ActorDynamic * actor, ActorStatic * terrain );
	static inline void Collision( Actor * actorA, Actor * actorB );
	
public:
	
	static inline void SetEngine( Engine * Engine );
	static inline void Collision( Actor * actor );
};

#endif

