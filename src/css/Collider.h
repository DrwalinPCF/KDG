
#pragma once

class Collider
{
private:
	
	World * world;
	
	Octtree < std::map < Actor*, bool > > octtree;
	std::map < Actor*, bool > outsideActors;
	std::map < Actor*, AABBint > actorAABB;
	
	AABB aabb;
	
public:
	
	void AddActor( const Actor * actor );
	void DestroyActor( const Actor * actor );
	void GetActor( const AABB aabb, std::map < Actor *, bool > & actors ) const;		// std::map actors - must be empty
	void GetActor( const AABB aabb, std::map < Actor *, AABB > & actors ) const;		// std::map actors - must be empty
	
	void Clear();
	
	AABB GetAABB() const;
	Vector GetSize() const;
	void Init( const AABB aabb, const int levels, const World * world );
	
	void Destroy();
	
	Collider();
	~Collider();
};



