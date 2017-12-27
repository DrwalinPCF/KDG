
#ifndef ACTOR_STATIC_H
#define ACTOR_STATIC_H

#include "../Includer.h"

class ActorStatic
{
private:
	
	Game * game;
	
	std::string name;
	
	PhysicsMesh * physicsMesh;
	
	Vector pos;
	Vector scale;
	Quat rotation;
	
	bool visible;
	int rayTraceChannel;
	int collisionChannel;
	
	AABB aabb;
	
public:
	
	friend class CollisionManager;
	
	void SetGame( const Game * game );
	void SetName( const std::string& name );
	
	void DrawDebug() const;
	
	inline void UpdateColliderAndAABB();
	
	inline void SetPhysicsMesh( const PhysicsMesh * mesh );
	inline PhysicsMesh * GetPhysicsMesh() const;
	
	inline AABB ConvertAABBIntoPhysicsMeshAABB( const AABB& aabb );
	
	inline Vector GetPos() const;
	inline Vector GetScale() const;
	inline Quat GetRotation() const;
	
	inline Move( const Vector& move );
	inline Rotate( const Quat& rotator );
	inline Rotate( const Vector& rotator );
	
	inline void SetPos( const Vector& pos );
	inline void SetScale( const Vector& scale );
	inline void SetRotation( const Vector& rotation );
	
	inline AABB GetAABB() const;
	
	inline bool GetVisible() const;
	inline void SetVisible( const bool src );
	
	inline int GetRayTraceChannel() const;
	inline int GetCollisionChannel() const;
	
	inline void SetRayTraceChannel( const int src );
	inline void SetCollisionChannel( const int src );
	
	inline bool AvailableOnRayTraceChannel( const int other ) const;
	inline bool AvailableOnCollisionChannel( const int other ) const;
	
	ActorStatic();
	~ActorStatic();
};

#endif

