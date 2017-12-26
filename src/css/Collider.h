
#pragma once

template < class T >
class Collider
{
private:
	
	Game * game;
	
	Octtree < std::map < T*, bool > > octtree;
	std::map < T*, bool > outsideObject;
	std::map < T*, AABBint > objectAABB;
	
	AABB aabb;
	
public:
	
	void AddObject( const T * object, const AABB& aabbObject );
	void RemoveObject( const T * object );
	void GetObject( const AABB& aabb, std::map < T *, bool >& objects ) const;		// std::map objects - must be empty
	void GetObject( const AABB& aabb, std::map < T *, AABB >& objects ) const;		// std::map objects - must be empty
	void GetObject( const AABB& aabb, std::string < T* >& objects ) const;
	
	void Clear();
	
	AABB GetAABB() const;
	Vector GetSize() const;
	void Init( const AABB& aabb, const int levels, const Game * game );
	
	void Destroy();
	
	Collider();
	~Collider();
};



