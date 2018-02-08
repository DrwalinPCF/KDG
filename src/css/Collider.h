/*
	Copyright (C) 2017 Marek Zalewski
	
	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.
	
	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1.	The origin of this software must not be misrepresented; you must not
		claim that you wrote the original software. If you use this software
		in a product, an acknowledgment in the product documentation is required.
	2.	Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.
	3.	This notice may not be removed or altered from any source distribution.
*/

#ifndef COLLIDER_H
#define COLLIDER_H

#include "../lib/MZ/SourceCode/Map.cpp"
#include "../lib/MZ/SourceCode/Array.cpp"
#include "../lib/MZ/SourceHeader/String.h"

#include "../lib/MZ/SourceCode/Octtree.cpp"
#include "../lib/MZ/SourceHeader/AABB.h"

template < class T >
class Collider
{
private:
	
	Octtree < Map < T, bool > > octtree;
	Map < T, bool > outsideObject;
	Map < T, AABBint > objectAABB;
	
	AABB aabb;
	
public:
	
	static inline std::string GetClassName();
	
	void AddObject( const T object, const AABB& aabbObject );
	void RemoveObject( const T object );
	void GetObject( const AABB& aabb, Map < T, bool >& objects ) const;		// std::map objects - must be empty
	void GetObject( const AABB& aabb, Map < T, AABB >& objects ) const;		// std::map objects - must be empty
	void GetObject( const AABB& aabb, Array < T >& objects ) const;
	void GetAllObject( Array < T >& objects ) const;
	
	void Clear();
	
	AABB GetAABB() const;
	Vector GetSize() const;
	void Init( const AABB& aabb, const int levels );
	
	void Destroy();
	
	Collider();
	~Collider();
};

#endif

