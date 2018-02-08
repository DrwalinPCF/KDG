
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef ACTOR_DYNAMIC_H
#define ACTOR_DYNAMIC_H

#include "../lib/MZ/SourceHeader/Vector.h"
#include "../lib/MZ/SourceHeader/VMatrix.h"
#include "../lib/MZ/SourceHeader/Quat.h"
#include "../lib/MZ/SourceHeader/AABB.h"
#include "Actor.h"

class ActorDynamic : public Actor
{
protected:
	
	Vector linearVelocity;
	Quat angularVelocity;
	Vector force;
	
	Vector bPosition;
	Vector bSize;
	Quat bRotation;
	
	Vector bLinearVelocity;
	Quat bAngularVelocity;
	Vector bForce;
	
	float angularDamping;
	float linearDamping;
	
	float mass;
	
	bool movability;
	bool rotationAbility;
	
public:
	
	virtual inline String GetClassName() override;
	
	
	inline void SetLinearVelocity( const Vector& val );
	inline void SetAngularVelocity( const Quat& val );
	inline void SetForce( const Vector& val );
	
	inline void AddLinearVelocity( const Vector& val );
	inline void AddAngularVelocity( const Quat& val );
	inline void AddForce( const Vector& val );
	
	inline Vector GetSetLinearVelocity() const;
	inline Quat GetAngularVelocity() const;
	inline Vector GetForce() const;
	
	inline Vector GetPointFromPreviousFrame( const Vector& src ) const;
	
	inline void GetAxes( Vector& x, Vector& y, Vector& z ) const;
	
	inline void SetMovability( const bool val );
	inline void SetRotationAbility( const bool val );
	inline void SetMass( const float val );
	inline void SetLinearDamping( const float val );
	inline void SetAngularDamping( const float val );
	
	inline bool GetMovability() const;
	inline bool GetRotationAbility() const;
	inline float GetMass() const;
	inline float GetLinearDamping() const;
	inline float GetAngularDamping() const;
	
	void AddForce( const Vector& point, const Vector& force );
	
	virtual void Update( const float deltaTime ) override;
	
	ActorDynamic();
	virtual ~ActorDynamic();
};

#endif

