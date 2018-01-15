
#ifndef ACTOR_DYNAMIC_CPP
#define ACTOR_DYNAMIC_CPP

#include "../css/ActorDynamic.h"

void ActorDynamic::SetMovability( const bool val )
{
	movability = val;
}

void ActorDynamic::SetRotationAbility( const bool val )
{
	rotationAbility = val;
}

void ActorDynamic::SetMass( const float val )
{
	if( val == 0.0f )
		mass = 1.0f;
	else if( val < 0.0f )
		mass = -val;
	else
		mass = val;
}

void ActorDynamic::SetLinearDamping( const float val )
{
	if( val == 0.0f )
		linearDamping = 1.0f;
	else if( val < 0.0f )
		linearDamping = -val;
	else
		linearDamping = val;
}

void ActorDynamic::SetAngularDamping( const float val )
{
	if( val == 0.0f )
		angularDamping = 1.0f;
	else if( val < 0.0f )
		angularDamping = -val;
	else
		angularDamping = val;
}

bool ActorDynamic::GetMovability() const
{
	return movability;
}

bool ActorDynamic::GetRotationAbility() const
{
	return rotationAbility;
}

float ActorDynamic::GetMass() const
{
	return mass;
}

float ActorDynamic::GetLinearDamping() const
{
	return linearDamping;
}

float ActorDynamic::GetAngularDamping() const
{
	return angularDamping;
}

void ActorDynamic::AddForce( const Vector& point, const Vector& force )
{
	Vector r = point - this->possition;
	float r_length = r.Length();
	if( r_length <= 0.01f )
	{
		this->force += force;
		return;
	}
	
	r /= r_length;
	Vector parallel = r * r.Dot( force );
	
	this->force += parallel;
	float angle = (force - parralel).Length() * engine->GetDeltaTime() / this->mass;
	angularVelocity *= Quat( r && force, angle > 90.0f ? 90.0f : angle );
}

virtual void ActorDynamic::Update( const float deltaTime ) override
{
	bPossition = possition;
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
		
		possition += linearVelocity * deltaTime;
		if( rotationAbility )
		{
			float angle_velocity = angularVelocity.GetAngle();
			{
				float angular_damping_vel = angularDamping * deltaTime;
				if( abs(angle_velocity) <= angular_damping_vel )
					angle_velocity = 0.0f;
				else if( angle_velocity > angular_damping_vel )
					angle_velocity -= angular_damping_vel;
				else
					angle_velocity += angular_damping_vel;
				if( angle_velocity > 90.0f )
					angle_velocity = 90.0f;
				else if( angle_velocity < -90.0f )
					angle_velocity = -90.0f;
			}
			
			Vector velocity_axis = angularVelocity.GetAxis();
			rotation *= Quat( velocity_axis, angle_velocity * deltaTime );
			angularVelocity = Quat( velocity_axis, angle_velocity );
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

ActorDynamic::~ActorDyanmic()
{
	movability = false;
	rotationAbility = false;
	mass = 0.0f;
	angularDamping = 0.0f;
	linearDamping = 0.0f;
}

#endif


