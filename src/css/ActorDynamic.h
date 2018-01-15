
#ifndef ACTOR_DYNAMIC_H
#define ACTOR_DYNAMIC_H

#include "../Includer.h"

class ActorDynamic : public Actor
{
private:
	
	Vector linearVelocity;
	Quat angularVelocity;
	Vector force;
	
	Vector bPossition;
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
	
	void SetMovability( const bool val );
	void SetRotationAbility( const bool val );
	void SetMass( const float val );
	void SetLinearDamping( const float val );
	void SetAngularDamping( const float val );
	
	bool GetMovability() const;
	bool GetRotationAbility() const;
	float GetMass() const;
	float GetLinearDamping() const;
	float GetAngularDamping() const;
	
	void AddForce( const Vector& point, const Vector& force );
	
	virtual void Update( const float deltaTime ) override;
	
	ActorDynamic();
	~ActorDynamic();
};

#endif

