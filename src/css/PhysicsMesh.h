
#ifndef PHYSICS_MESH_H
#defin PHYSICS_MESH_H

#include "../Includer.h"

class PhysicsMesh
{
private:
	
	Game * game;
	
	std::string name;
	
	Octree < int > octree;
	std::vector < Triangle > triangle;
	AABB aabb;
	
	Collider < int > collider;	// contains triangles id
	
public:
	
	friend class CollisionManager;
	
	int LoadFromFile( const std::string& name, const std::string& type, const std::string& fileName, const int typeVersion = -1 /*newest*/ );
	inline bool AccessTriangle( const int id, Triangle& dst );
	inline bool AccessTriangle( const AABB& aabb, const Quat& aabbRotation, std::map<Triangle>& dst );
	
	PhysicsMesh();
	~PhysicsMesh();
};

#endif

