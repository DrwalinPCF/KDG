
#ifndef ACTOR_DYNAMIC_H
#define ACTOR_DYNAMIC_H

#include "../Includer.h"

class ActorDynamic : public Actor
{
private:
	
	Vector pos;
	Vector size;	// half size from pos to all sides
	
	Vector bpos;
	Vector bsize;
	
	Vector vel;
	Vector force;
	
	Vector bvel;
	Vector bforce;
	
	bool movability;
	
public:
	
	inline AABB GetAABB() const;
	
	
	
	
	
	virtual void Update( const float deltaTime )=0;
	
	ActorDynamic();
	~ActorDyanmic();
};

#endif

