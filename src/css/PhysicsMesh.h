
#ifndef PHYSICS_MESH_H
#define PHYSICS_MESH_H

#include "../Includer.h"

class PhysicsMesh
{
private:
	
	std::string name;
	
	AABB aabb;
	Collider < Triangle > collider;	// contains triangles id
	
public:
	
	inline AABB GetAABB() const;
	
	void SetName( const std::string& name );
	
	int LoadFromFile( const std::string& fileName, const int fileFormatVersion = -1 /*newest*/ );		// update collider
	inline void AccessTriangle( const AABB& aabb, std::vector < Triangle >& dst ) const;
	
	PhysicsMesh();
	~PhysicsMesh();
};

#endif

