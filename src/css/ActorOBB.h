
#ifndef ACTOR_OBB_H
#define ACTOR_OBB_H

#include "../Includer.h"

class ActorOBB : public ActorDynamic
{
private:
	
	
	
public:
	
	virtual void DrawDebug() override;
	virtual void UpdateAABB() override;
	
	
	
	
	virtual void Update( const float deltaTime ) override;
	
	ActorOBB();
	~ActorOBB();
};

#endif
