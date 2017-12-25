
#ifndef GAME_H
#define GAME_H

#include "../Includer.h"

class Game
{
private:
	
	std::string name;
	
	std::map < std::string, PhysicsMesh* > physicsMesh;
	std::map < std::string, ActroStatic* > actorStatic;
	std::map < std::String, ActorDynamic* > actorDynamic;
	
	Collider < ActroStatic* > colliderStatic;
	Collider < ActroDynamic* > colliderDynamic;
	
public:
	
	
	
	World();
	~World();
};

#endif

