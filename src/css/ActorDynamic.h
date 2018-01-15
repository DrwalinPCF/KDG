
#ifndef ACTOR_DYNAMIC_H
#define ACTOR_DYNAMIC_H

#include "../Includer.h"

#include "Actor.h"

class ActorDynamic : public Actor
{
private:
	
	Vector bpos;
	Vector bsize;
	
	Vector vel;
	Vector force;
	
	Vector bvel;
	Vector bforce;
	
	bool movability;
	bool rotationability;
	
public:
	
	virtual void UpdateAABB() override;
	
	void SetMovability( const bool val );
	void SetRotationability( const bool val );
	
	bool GetMovability() const;
	bool GetRotationability() const;
	
	
	virtual void Update( const float deltaTime )=0;
	
	ActorDynamic();
	~ActorDyanmic();
};

#endif

