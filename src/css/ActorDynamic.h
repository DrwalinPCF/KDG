
#ifndef ACTOR_DYNAMIC_H
#define ACTOR_DYNAMIC_H

#include "../Includer.h"

class ActorDynamic
{
private:
	
	Game * game;
	
	std::string name;
	
	Vector pos;
	Vector size;	// half size from pos to all sides
	
	Vector bpos;
	Vector bsize;
	
	Vector vel;
	Vector force;
	
	Vector bvel;
	Vector bforce;
	
	bool movability;
	bool visible;
	int rayTraceChannel;
	int collisionChannel;
	
public:
	
	friend class CollisionManager;
	
	inline AABB GetAABB() const;
	
	
	
	
	
	void Update( const float deltaTime );
	
	inline bool GetMovability() const;
	inline void SetMovability( const bool src );
	
	inline bool GetVisible() const;
	inline void SetVisible( const bool src );
	
	inline int GetRayTraceChannel() const;
	inline int GetCollisionChannel() const;
	
	inline void SetRayTraceChannel( const int src );
	inline void SetCollisionChannel( const int src );
	
	inline bool AvailableOnRayTraceChannel( const int other ) const;
	inline bool AvailableOnCollisionChannel( const int other ) const;
	
	ActorDynamic();
	~ActorDyanmic();
};

#endif

