
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
	
	void SetGame( const Game * game );
	void SetName( const std::string& name );
	
	int LoadFromFile( const std::string& name, const std::string& type, const std::string& fileName, const int typeVersion = -1 /*newest*/ );		// update collider
	bool AccessTriangle( const int id, Triangle& dst );
	void AccessTriangle( const AABB& aabb, std::vector < Triangle >& dst );
	
	PhysicsMesh();
	~PhysicsMesh();
};

#endif

