
#ifndef ACTOR_STATIC_H
#define ACTOR_STATIC_H

#include "../Includer.h"
#include "Actor.h"

class ActorStatic : public Actor
{
private:
	
	PhysicsMesh * physicsMesh;
	
public:
	
	virtual void DrawDebug() const override;
	virtual void UpdateAABB() override;
	
	inline void SetPhysicsMesh( const PhysicsMesh * mesh );
	inline PhysicsMesh * GetPhysicsMesh() const;
	
	inline void GetTriangles( const AABB& aabb, std::vector < Triangle >& triangles ) const;
	
	virtual void Update( const float deltaTime ) override;
	
	ActorStatic();
	virtual ~ActorStatic();
};

#endif

