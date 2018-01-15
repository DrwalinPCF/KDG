
#ifndef GAME_H
#define GAME_H

#include "../Includer.h"

class Game
{
private:
	
	std::string name;
	
	std::map < std::string, PhysicsMesh* > physicsMesh;
	std::map < std::string, Actor* > actors;
	
	Collider < Actor* > colliderActor;
	
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
	
	
	void DrawCharactersDebug() const;
	void DrawMapDebug() const;
	void DrawDebug() const;
	
	void Renderer();
	
	
	inline void GetActor( const AABB& aabb, std::vector < Actor* >& objects ) const;
	
	PhysicsMesh * LoadPhysicsMesh( const std::string& name, const std::string& fileName, const int fileFormatVersion = -1 );
	int SpawnActor( const Actor* object );
	
	PhysicsMesh * GetPhysicsMesh( const std::string& name ) const;
	ActorStatic * GetActor( const std::string& name ) const;
	
	void DestroyPhysicsMesh( const std::string& name );
	void DestroyActor( const std::string& name );
	
	
	
	
	bool RayTrace( const Vector& begin, const Vector& end, const int rayTraceChannel, Actor** dst, Vector& point, float& distance, Vector& normal ) const;		// dstDynamic = NULL || dstStatic = NULL
	
	
	
	
	void UpdateColliderActorStatic( Actor * actor );
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

