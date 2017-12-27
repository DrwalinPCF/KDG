
#ifndef GAME_H
#define GAME_H

#include "../Includer.h"

class Game
{
private:
	
	std::string name;
	
	std::map < std::string, ActorDynamic* > actorDynamic;
	std::map < std::string, PhysicsMesh* > physicsMesh;
	std::map < std::string, ActorStatic* > actorStatic;
	
	Collider < ActorStatic* > colliderActorStatic;
	Collider < ActorDynamic* > colliderActorDynamic;
	
	float timeScale;
	float deltaTime;	// deltaTime = real_deltaTime * timeScale
	
	bool debug;
	
	float gravityAcceleration;	// in y-axis
	
	float averageFPS;
	int framesCounter;
	int timeFromLastResetFrameCounter;
	
public:
	
	void SetTimeScale( const float value );
	float GetDeltaTime() const;
	
	
	void DrawMapDebug() const;
	void DrawCharactersDebug() const;
	void DrawDebug() const;
	
	void Renderer();
	
	
	
	inline void GetActorDynamic( const AABB& aabb, std::vector < ActorDynamic* >& objects ) const;
	inline void GetActorStatic( const AABB& aabb, std::vector < ActorStatic* >& objects ) const;
	
	ActorDynamic * SpawnActorDynamic( const std::string& name );
	PhysicsMesh * SpawnPhysicsMesh( const std::string& name );
	ActorStatic * SpawnActorStatic( const std::string& name );
	
	ActorDynamic * GetActorDynamic( const std::string& name ) const;
	PhysicsMesh * GetPhysicsMesh( const std::string& name ) const;
	ActorStatic * GetActorStatic( const std::string& name ) const;
	
	void DestroyActorDynamic( const std::string& name );
	void DestroyPhysicsMesh( const std::string& name );
	void DestroyActorStatic( const std::string& name );
	
	
	
	
	bool RayTrace( const Vector& begin, const Vector& end, const int rayTraceChannel, ActorDynamic** dstDynamic, ActorStatic** dstStatic, Vector& point, float& distance ) const;		// dstDynamic = NULL || dstStatic = NULL
	
	
	
	void UpdateColliderActorStatic( ActorStatic * actor );
	void UpdateNavMesh();
	void UpdateColliderActorDynamic();
	void UpdatePhysics();		// collision and physics
	
	
	void Update();
	
	
	void Init( int * argc, char *** argv );
	void MainLoop();
	
	Game();
	~Game();
};

#endif

