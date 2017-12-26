
#ifndef GAME_H
#define GAME_H

#include "../Includer.h"

class Game
{
private:
	
	std::string name;
	
	std::map < std::string, PhysicsMesh* > physicsMesh;
	std::map < std::string, ActorStatic* > actorStatic;
	std::map < std::string, ActorDynamic* > actorDynamic;
	
	Collider < ActorStatic* > colliderStatic;
	Collider < ActorDynamic* > colliderDynamic;
	
	float deltaTime;
	
	bool debug;
	
	Vector gravity;
	
public:
	
	
	void DrawMapDebug() const;
	void DrawCharactersDebug() const;
	void DrawDebug() const;
	
	void DrawLight();
	void DrawParticle();
	void DrawMap();
	void DrawCharacters();
	void Draw();
	
	void Renderer();
	
	
	//void UpdateLight();
	void UpdateNavMesh();
	void UpdateColliders();
	void UpdatePhysics();		// collision and physics
	
	
	void Update();
	
	
	void Init( int * argc, char *** argv );
	void MainLoop();
	
	Game();
	~Game();
};

#endif

