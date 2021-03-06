
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef ACTOR_STATIC_H
#define ACTOR_STATIC_H

#include "../lib/MZ/SourceCode/Array.cpp"
#include "../lib/MZ/SourceHeader/String.h"

#include "../lib/MZ/SourceHeader/Vector.h"
#include "../lib/MZ/SourceHeader/VMatrix.h"
#include "../lib/MZ/SourceHeader/Quat.h"
#include "../lib/MZ/SourceHeader/AABB.h"
#include "../lib/MZ/SourceHeader/Triangle.h"

#include "Actor.h"
#include "PhysicsMesh.h"

class ActorStatic : public Actor
{
private:
	
	Vector bPosition;
	Vector bSize;
	Quat bRotation;
	
	bool colliderUpdateIsNeeded;
	
	Array < Vector > vertices;
	PhysicsMesh * physicsMesh;
	
public:
	
	virtual inline String GetClassName() override;
	
	virtual void DrawDebug() const override;
	virtual void UpdateAABB() override;
	
	inline void ColliderUpdated();
	inline bool DoesColliderNeedUpdate() const;
	
	inline void SetPhysicsMesh( const PhysicsMesh * mesh );
	inline PhysicsMesh * GetPhysicsMesh() const;
	
	inline void GetTriangles( const AABB& aabb, Array < int >& triangles ) const;
	inline void GetTriangle( const int id, Triangle& triangle ) const;
	
	virtual void Update( const float deltaTime ) override;
	
	ActorStatic();
	virtual ~ActorStatic();
};

#endif

