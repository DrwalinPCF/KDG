
#ifndef ACTOR_STATIC_H
#define ACTOR_STATIC_H

#include "../Includer.h"
#include "Actor.h"

class ActorStatic : public Actor
{
private:
	
	Vector bPossition;
	Vector bSize;
	Quat bRotation;
	
	bool colliderUpdateIsNeeded;
	
	std::vector < Vector > vertices;
	PhysicsMesh * physicsMesh;
	
public:
	
	virtual inline std::string GetClassName() override;
	
	virtual void DrawDebug() const override;
	virtual void UpdateAABB() override;
	
	inline void ColliderUpdated();
	inline bool DoesColliderNeedUpdate() const;
	
	inline void SetPhysicsMesh( const PhysicsMesh * mesh );
	inline PhysicsMesh * GetPhysicsMesh() const;
	
	inline void GetTriangles( const AABB& aabb, std::vector < int >& triangles ) const;
	inline void GetTriangle( const int id, Triangle& triangle ) const;
	
	virtual void Update( const float deltaTime ) override;
	
	ActorStatic();
	virtual ~ActorStatic();
};

#endif

