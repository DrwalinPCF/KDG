
#ifndef PHYSICS_MESH_H
#define PHYSICS_MESH_H

#include "../Includer.h"

class PhysicsMesh
{
private:
	
	std::string name;
	
	std::vector < Triangle > triangles;
	AABB aabb;
	Collider < int > collider;
	
public:
	
	inline AABB GetAABB() const;
	
	void SetName( const std::string& name );
	
	int LoadFromFile( const std::string& fileName, const int fileFormatVersion );		// update collider
	inline bool AccessTriangle( const int id, Triangle& dst );
	inline void AccessTriangle( const AABB& aabb, std::vector < Triangle >& dst ) const;
	inline void AccessAllTriangle( std::vector < Triangle >& dst ) const;
	
	PhysicsMesh();
	~PhysicsMesh();
};

#endif

