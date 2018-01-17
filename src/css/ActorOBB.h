
#ifndef ACTOR_OBB_H
#define ACTOR_OBB_H

#include "ActorDynamic.h"
#include "../Includer.h"

class ActorOBB : public ActorDynamic
{
private:
	
	
	
public:
	
	virtual inline std::string GetClassName() override;
	
	virtual void DrawDebug() const override;
	virtual void UpdateAABB() override;
	
	
	
	
	virtual void Update( const float deltaTime ) override;
	
	ActorOBB();
	virtual ~ActorOBB();
};

#endif
