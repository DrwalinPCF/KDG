
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef ACTOR_H
#define ACTOR_H

class Engine;

#include "../lib/MZ/SourceHeader/String.h"

#include "Engine.h"
#include "../lib/MZ/SourceHeader/Vector.h"
#include "../lib/MZ/SourceHeader/VMatrix.h"
#include "../lib/MZ/SourceHeader/Quat.h"
#include "../lib/MZ/SourceHeader/AABB.h"

class Actor
{
protected:
	
	Engine * engine;
	String name;
	
	Vector position;
	Quat rotation;
	Vector size;
	
	AABB aabb;
	
	bool visibility;
	int rayTraceChannel;
	int collisionChannel;
	
public:
	
	virtual inline String GetClassName()=0;
	
	virtual void DrawDebug() const=0;
	virtual void UpdateAABB()=0;
	
	inline String GetName() const;
	inline Engine * GetEngine() const;
	
	inline AABB GetAABB() const;
	
	
	inline Vector GetPosition() const;
	inline Vector GetSize() const;
	inline Quat GetRotation() const;
	
	inline void Move( const Vector& val );
	inline void Rotate( const Quat& val );
	
	inline void SetPosition( const Vector& val );
	inline void SetSize( const Vector& val );
	inline void SetRotation( const Quat& val );
	
	
	inline bool IsVisible() const;
	inline void SetVisibility( const bool val );
	
	inline int GetRayTraceChannel() const;
	inline int GetCollisionChannel() const;
	
	inline void SetRayTraceChannel( const int val );
	inline void SetCollisionChannel( const int val );
	
	static inline bool IsChannelsOverlapping( const int channelA, const int channelB );
	static inline bool IsRayTraceChannelsOverlap( const Actor * actorA, const Actor * actorB );
	static inline bool IsCollisionChannelsOverlap( const Actor * actorA, const Actor * actorB );
	
	
	virtual void Update( const float deltaTime )=0;
	
	inline void Init( const Engine * engine, const String& name );
	
	Actor();
	virtual ~Actor();
};

#endif

