
#ifndef ENGINE_H
#define ENGINE_H

class Actor;
class ActorStatic;
class ActorDynamic;
class ActorOBB;

#include <map>
#include <string>
#include <vector>

#include "Error.h"
#include "Collider.h"
#include "Actor.h"
#include "PhysicsMesh.h"

#include "../lib/MZ/SourceHeader/Vector.h"
#include "../lib/MZ/SourceHeader/AABB.h"

class Engine
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
	
	std::vector < Error > errors;
	
public:
	
	static inline std::string GetClassName();
	
	inline void SetTimeScale( const float value );
	inline float GetDeltaTime() const;
	
	
	void DrawCharactersDebug() const;
	void DrawMapDebug() const;
	void DrawDebug() const;
	
	void Draw();
	
	
	inline void GetActor( const AABB& aabb, std::vector < Actor* >& objects ) const;
	
	PhysicsMesh * LoadPhysicsMesh( const std::string& name, const std::string& fileName, const int fileFormatVersion );
	int SpawnActor( const Actor* object );
	
	inline PhysicsMesh * GetPhysicsMesh( const std::string& name ) const;
	inline Actor * GetActor( const std::string& name ) const;
	
	inline void DestroyPhysicsMesh( const std::string& name );
	inline void DestroyActor( const std::string& name );
	
	
	
	
	bool RayTrace( const Vector& begin, const Vector& end, const int rayTraceChannel, Actor** dst, Vector& point, float& distance, Vector& normal ) const;		// dstDynamic = NULL || dstStatic = NULL
	
	
	int GetNextError( Error & error );	// return number of errors
	void AddError( const Error error );
	
	
	void UpdateColliderActorStatic( ActorStatic * object );
	void UpdateNavMesh();
	void UpdateColliderActor();
	void UpdatePhysics();		// collision and physics
	
	
	void Update();
	void UpdateClock();
	
	
	void Init( int * argc, char *** argv );
	
	Engine();
	~Engine();
};

#endif

