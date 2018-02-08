
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef ACTOR_DYNAMIC_CPP
#define ACTOR_DYNAMIC_CPP

#include "../css/ActorDynamic.h"

inline String ActorDynamic::GetClassName()
{
	return String( "ActorDynamic" );
}

inline void ActorDynamic::SetLinearVelocity( const Vector& val )
{
	linearVelocity = val;
}

inline void ActorDynamic::SetAngularVelocity( const Quat& val )
{
	float angle_velocity = angularVelocity.GetAngle();
	if( angle_velocity > 85.0f )
		angle_velocity = 85.0f;
	else
	{
		angularVelocity = val;
		return;
	}
	angularVelocity = Quat( angularVelocity.GetAxis(), angle_velocity );
}

inline void ActorDynamic::SetForce( const Vector& val )
{
	force = val;
}

inline void ActorDynamic::AddLinearVelocity( const Vector& val )
{
	linearVelocity += val;
}

inline void ActorDynamic::AddAngularVelocity( const Quat& val )
{
	float angle_val = val.GetAngle();
	if( angle_val > 85.0f )
		angle_val = 85.0f;
	SetAngularVelocity( angularVelocity * Quat( val.GetAxis(), angle_val ) );
}

inline void ActorDynamic::AddForce( const Vector& val )
{
	force += val;
}

inline Vector ActorDynamic::GetSetLinearVelocity() const
{
	return linearVelocity;
}

inline Quat ActorDynamic::GetAngularVelocity() const
{
	return angularVelocity;
}

inline Vector ActorDynamic::GetForce() const
{
	return force;
}


inline void ActorDynamic::GetAxes( Vector& x, Vector& y, Vector& z ) const
{
	x = rotation * Vector( size.x, 0.0f, 0.0f );
	y = rotation * Vector( 0.0f, size.y, 0.0f );
	z = rotation * Vector( 0.0f, 0.0f, size.z );
}


inline void ActorDynamic::SetMovability( const bool val )
{
	movability = val;
}

inline void ActorDynamic::SetRotationAbility( const bool val )
{
	rotationAbility = val;
}

inline void ActorDynamic::SetMass( const float val )
{
	if( val == 0.0f )
		mass = 1.0f;
	else if( val < 0.0f )
		mass = -val;
	else
		mass = val;
}

inline void ActorDynamic::SetLinearDamping( const float val )
{
	if( val == 0.0f )
		linearDamping = 1.0f;
	else if( val < 0.0f )
		linearDamping = -val;
	else
		linearDamping = val;
}

inline void ActorDynamic::SetAngularDamping( const float val )
{
	if( val == 0.0f )
		angularDamping = 1.0f;
	else if( val < 0.0f )
		angularDamping = -val;
	else
		angularDamping = val;
}

inline bool ActorDynamic::GetMovability() const
{
	return movability;
}

inline bool ActorDynamic::GetRotationAbility() const
{
	return rotationAbility;
}

inline float ActorDynamic::GetMass() const
{
	return mass;
}

inline float ActorDynamic::GetLinearDamping() const
{
	return linearDamping;
}

inline float ActorDynamic::GetAngularDamping() const
{
	return angularDamping;
}

void ActorDynamic::AddForce( const Vector& point, const Vector& force )
{
	Vector r = point - this->position;
	float r_length = r.Length();
	if( r_length <= 0.01f )
	{
		this->force += force;
		return;
	}
	
	r /= r_length;
	Vector parallel = r * r.Dot( force );
	
	this->force += parallel;
	float angle = (force - parallel).Length() * engine->GetDeltaTime() / this->mass;
	AddAngularVelocity( Quat( r && force, angle > 85.0f ? 85.0f : angle ) );
}

inline Vector ActorDynamic::GetPointFromPreviousFrame( const Vector& src ) const
{
	return (bRotation * (rotation.Inversed() * (src-position))) + bPosition;
}

void ActorDynamic::Update( const float deltaTime )
{
	bPosition = position;
	bSize = size;
	bRotation = rotation;
	bLinearVelocity = linearVelocity;
	bAngularVelocity = angularVelocity;
	bForce = force;
	
	if( movability )
	{
		linearVelocity += force * deltaTime / mass;
		{
			float linear_damping_vel = linearDamping * deltaTime;
			float linear_velocity_length = Math::Sqrt( linearVelocity.Dot( linearVelocity ) );
			if( linearVelocity.Dot( bLinearVelocity ) <= 0.0f )
				linearVelocity.Set( 0.0f, 0.0f, 0.0f );
			if( linear_velocity_length <= linear_damping_vel )
				linearVelocity.Set( 0.0f, 0.0f, 0.0f );
			else
				linearVelocity = linearVelocity * ( ( linear_velocity_length - linear_damping_vel ) / linear_velocity_length );
		}
		
		position += linearVelocity * deltaTime;
		if( rotationAbility )
		{
			float angle_velocity = angularVelocity.GetAngle();
			{
				float angular_damping_vel = angularDamping * deltaTime;
				if( abs(angle_velocity) <= angular_damping_vel )
					angle_velocity = 0.0f;
				else if( angle_velocity > angular_damping_vel )
					angle_velocity -= angular_damping_vel;
			}
			
			Vector velocity_axis = angularVelocity.GetAxis();
			angularVelocity = Quat( velocity_axis, angle_velocity );
			rotation *= Quat( velocity_axis, angle_velocity * deltaTime );
		}
		
		force.Set( 0.0f, 0.0f, 0.0f );
		
		this->UpdateAABB();
	}
}

ActorDynamic::ActorDynamic()
{
	movability = true;
	rotationAbility = true;
	mass = 1.0f;
	angularDamping = 0.1f;
	linearDamping = 0.1f;
}

ActorDynamic::~ActorDynamic()
{
	movability = false;
	rotationAbility = false;
	mass = 0.0f;
	angularDamping = 0.0f;
	linearDamping = 0.0f;
}

#endif


