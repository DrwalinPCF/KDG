
#ifndef PHYSICS_MESH_H
#define PHYSICS_MESH_H

#include "../Includer.h"

class PhysicsMesh
{
private:
	
	std::string name;
	
	Octtree < int > octree;
	std::vector < Triangle > triangle;
	AABB aabb;
	
	Collider < Triangle > collider;	// contains triangles id
	
public:
	
	void SetName( const std::string& name );
	
	int LoadFromFile( const std::string& fileName, const int fileFormatVersion = -1 /*newest*/ );		// update collider
	bool AccessTriangle( const int id, Triangle& dst );
	void AccessTriangle( const AABB& aabb, std::vector < Triangle >& dst );
	
	PhysicsMesh();
	~PhysicsMesh();
};

#endif

