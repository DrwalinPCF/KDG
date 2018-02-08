
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef ACTOR_OBB_H
#define ACTOR_OBB_H

class ActorDynamic;

#include "../lib/MZ/SourceHeader/Vector.h"
#include "../lib/MZ/SourceHeader/VMatrix.h"
#include "../lib/MZ/SourceHeader/Quat.h"
#include "../lib/MZ/SourceHeader/AABB.h"
#include "ActorDynamic.h"

class ActorOBB : public ActorDynamic
{
private:
	
	
	
public:
	
	virtual inline String GetClassName() override;
	
	virtual void DrawDebug() const override;
	virtual void UpdateAABB() override;
	
	void GetMaxMinWithVector( float& ta, float& tb );
	
	
	virtual void Update( const float deltaTime ) override;
	
	ActorOBB();
	virtual ~ActorOBB();
};

#endif
