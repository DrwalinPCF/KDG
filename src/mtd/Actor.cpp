
#ifndef ACTOR_CPP
#define ACTOR_CPP

#include "../css/Actor.h"

AABB Actor::GetAABB() const
{
	return AABB;
}


inline Vector Actor::GetPossition() const
{
	return possition;
}

inline Vector Actor::GetSize() const
{
	return size;
}

inline Quat Actor::GetRotation() const
{
	return rotation;
}

inline void Actor::Move( const Vector& val )
{
	possition += val;
}

inline void Actor::Rotate( const Quat& val )
{
	rotation *= val;
}

inline void Actor::SetPossition( const Vector& val )
{
	possition = val;
}

inline void Actor::SetSize( const Vector& val )
{
	size = val;
}

inline void Actor::SetRotation( const Quat& val )
{
	rotation = val;
}


inline bool Actor::IsVisible() const
{
	return visibility;
}

inline void Actor::SetVisibility( const bool val )
{
	visibility = val;
}

inline int Actor::GetRayTraceChannel() const
{
	return rayTraceChannel;
}

inline int Actor::GetCollisionChannel() const
{
	return collisionChannel;
}

inline void Actor::SetRayTraceChannel( const int val )
{
	rayTraceChannel = val;
}

inline void Actor::SetCollisionChannel( const int val )
{
	collisionChannel = val;
}

inline bool Actor::IsChannelsOverlapping( const int channelA, const int channelB )
{
	return bool( channelA & channelB );
}

inline bool Actor::IsRayTraceChannelsOverlap( const Actor * actorA, const Actor * actorB )
{
	return bool( actorA->rayTraceChannel & actorB->rayTraceChannel );
}

inline bool Actor::IsCollisionChannelsOverlap( const Actor * actorA, const Actor * actorB )
{
	return bool( actorA->collisionChannel & actorB->collisionChannel );
}


void Actor::Init( const Engine * engine, const std::string & name )
{
	this->engine = engine;
	this->name = name;
}

Actor::Actor()
{
	size.Set( 1.0f, 1.0f, 1.0f );
	visibility = true;
	rayTraceChannel = 1;
	collisionChannel = 1;
}

Actor::~Actor()
{
	engine = NULL;
	name = "";
	
	visibility = false;
	rayTraceChannel = 0;
	collisionChannel = 0;
}

#endif

