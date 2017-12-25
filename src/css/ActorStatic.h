
#ifndef ACTOR_STATIC_H
#defien ACTOR_STATIC_H

#include "../Includer.h"

class ActorStatic
{
private:
	
	Game * game;
	
	std::string name;
	
	PhysicsMesh * physicsMesh;
	
	Vector pos;
	Quat rotation;
	
	bool visible;
	int rayTraceChannel;
	int collisionChannel;
	
	AABB aabb;
	
public:
	
	friend class CollisionManager;
	
	void DrawDebug() const;
	
	inline void SetPhysicsMesh( const PhysicsMesh * mesh );
	inline PhysicsMesh * GetPhysicsMesh() const;
	
	inline Vector GetPos() const;
	inline Quat GetRotation() const;
	
	inline Move( const Vector& move );
	inline Rotate( const Quat& rotation );
	
	inline void SetPos( const Vector& pos );
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

