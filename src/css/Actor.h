
#ifndef ACTOR_H
#define ACTOR_H

#include "../Includer.h"

class Actor
{
private:
	
	Game * game;
	std::string name;
	
	Vector pos;
	Quat rotation;
	Vector scale;
	
	bool visibility;
	int rayTraceChannel;
	int collisionChannel;
	
public:
	
	virtual void DrawDebug()=0 const;
	virtual void GetAABB()=0 const;
	
	
	inline Vector GetPos() const;
	inline Vector GetScale() const;
	inline Quat GetRotation() const;
	
	inline void Move( const Vector& val );
	inline void Rotate( const Quat& val );
	
	inline void SetPos( const Vector& val );
	inline void SetScale( const Vector& val );
	inline void SetRotation( const Quat& val );
	
	
	inline bool IsVisible() const;
	inline void SetVisibility( const bool val );
	
	inline int GetRayTraceChannel() const;
	inline int GetCollisionChannel() const;
	
	inline void SetRayTraceChannel( const int val );
	inline void SetCollisionChannel( const int val );
	
	inline static bool IsChannelsOverlapping( const int channelA, const int channelB );
	inline static bool IsRayTraceChannelsOverlap( const Actor * actorA, const Actor * actorB );
	inline static bool IsCollisionChannelsOverlap( const Actor * actorA, const Actor * actorB );
	
	
	void Init( const Game * game, const std::string & name );
};

#endif

