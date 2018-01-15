
#ifndef ACTOR_CPP
#define ACTOR_CPP

#include "../css/Actor.h"

AABB Actor::GetAABB() const
{
	return AABB;
}


inline Vector Actor::GetPos() const
{
	return pos;
}

inline Vector Actor::GetScale() const
{
	return scale;
}

inline Quat Actor::GetRotation() const
{
	return rotation;
}

inline void Actor::Move( const Vector& val )
{
	pos += val;
}

inline void Actor::Rotate( const Quat& val )
{
	rotation *= val;
}

inline void Actor::SetPos( const Vector& val )
{
	pos = val;
}

inline void Actor::SetScale( const Vector& val )
{
	scale = val;
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

inline static bool Actor::IsChannelsOverlapping( const int channelA, const int channelB )
{
	return bool( channelA & channelB );
}

inline static bool Actor::IsRayTraceChannelsOverlap( const Actor * actorA, const Actor * actorB )
{
	return bool( actorA->rayTraceChannel & actorB->rayTraceChannel );
}

inline static bool Actor::IsCollisionChannelsOverlap( const Actor * actorA, const Actor * actorB )
{
	return bool( actorA->collisionChannel & actorB->collisionChannel );
}


void Actor::Init( const Engine * engine, const std::string & name )
{
	this->engine = engine;
	this->name = name;
}

#endif

