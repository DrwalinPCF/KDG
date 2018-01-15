
#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "../Includer.h"

namespace CollisionManager
{
// private:
	
	Engine * engine = NULL;
	
	void Collision( ActorDynamic * actorA, ActorDynamic * actorB );
	void Collision( ActorDynamic * actor, ActorStatic * terrain );
	inline void Collision( Actor * actorA, Actor * actorB );
	
// public:
	
	inline void SetEngine( Engine * Engine );
	inline void Collision( Actor * actor );
	
};

#endif

