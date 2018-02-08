
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef PHYSICS_MESH_H
#define PHYSICS_MESH_H


#include "../lib/MZ/SourceCode/Array.cpp"
#include "../lib/MZ/SourceHeader/String.h"
#include "../lib/MZ/SourceHeader/File.h"

#include "Types.h"
#include "../lib/MZ/SourceHeader/Vector.h"
#include "../mtd/Collider.cpp"

class PhysicsMesh
{
private:
	
	String name;
	
	Array < Vector > vertices;
	Array < Int3 > * triangles;
	
	AABB aabb;
	Collider < int > collider;
	
public:
	
	static inline String GetClassName();
	
	inline AABB GetAABB() const;
	
	void SetName( const String& name );
	
	int LoadFromFile( const String& fileName, const int fileFormatVersion );		// update collider
	
	inline void AccessTriangle( const AABB& aabb, Map < int, bool >& dst  ) const;
	inline void GetVertices( Array < Vector >& dst ) const;
	
	inline void GetTriangle( const int id, Int3& dst ) const;
	
	void Clear();
	
	PhysicsMesh();
	~PhysicsMesh();
};

#endif

