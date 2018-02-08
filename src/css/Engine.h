
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef ENGINE_H
#define ENGINE_H

class Actor;
class ActorStatic;
class ActorDynamic;
class ActorOBB;

#include "../lib/MZ/SourceCode/Map.cpp"
#include "../lib/MZ/SourceCode/Array.cpp"
#include "../lib/MZ/SourceHeader/String.h"

#include "CollisionManager.h"
#include "Error.h"
#include "Collider.h"
#include "Actor.h"
#include "PhysicsMesh.h"

#include "../lib/MZ/SourceHeader/Vector.h"
#include "../lib/MZ/SourceHeader/AABB.h"

class Engine
{
private:
	
	String name;
	
	Map < String, PhysicsMesh* > physicsMesh;
	Map < String, Actor* > actors;
	
	Collider < Actor* > colliderActor;
	
	float timeScale;
	float deltaTime;	// deltaTime = real_deltaTime * timeScale
	
	bool debug;
	
	float gravityAcceleration;	// in y-axis
	
	float averageFPS;
	int framesCounter;
	int timeFromLastResetFrameCounter;
	
	Array < Error > errors;
	
public:
	
	static inline String GetClassName();
	
	inline void SetTimeScale( const float value );
	inline float GetDeltaTime() const;
	
	
	void DrawCharactersDebug() const;
	void DrawMapDebug() const;
	void DrawDebug() const;
	
	void Draw();
	
	
	inline void GetActor( const AABB& aabb, Array < Actor* >& objects ) const;
	
	PhysicsMesh * LoadPhysicsMesh( const String& name, const String& fileName, const int fileFormatVersion );
	int SpawnActor( const Actor* object );
	
	inline PhysicsMesh * GetPhysicsMesh( const String& name ) const;
	inline Actor * GetActor( const String& name ) const;
	
	inline void DestroyPhysicsMesh( const String& name );
	inline void DestroyActor( const String& name );
	
	
	
	
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

