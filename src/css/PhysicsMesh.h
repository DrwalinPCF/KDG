
#ifndef PHYSICS_MESH_H
#defin PHYSICS_MESH_H

#include "../Includer.h"

class PhysicsMesh
{
private:
	
	std::string name;
	
	Octree < int > octree;
	std::vector < Triangle > triangle;
	AABB aabb;
	
	Collider < int > collider;	// contains triangles id
	
public:
	
	friend class CollisionManager;
	
	void SetName( const std::string& name );
	
	int LoadFromFile( const std::string& fileName, const int fileFormatVersion = -1 /*newest*/ );		// update collider
	bool AccessTriangle( const int id, Triangle& dst );
	void AccessTriangle( const AABB& aabb, std::vector < Triangle >& dst );
	
	PhysicsMesh();
	~PhysicsMesh();
};

#endif

