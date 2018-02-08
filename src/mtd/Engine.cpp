
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef ENGINE_CPP
#define ENGINE_CPP

#include "../css/Engine.h"
#include "../css/ActorStatic.h"
#include "../css/ActorDynamic.h"
#include "../css/ActorOBB.h"


inline String Engine::GetClassName()
{
	return String( "Engine" );
}

inline void Engine::SetTimeScale( const float value )
{
	if( value > 0.0001f && value < 1000.0f )
		timeScale = value;
	else
		timeScale = 1.0f;
}

inline float Engine::GetDeltaTime() const
{
	return deltaTime*timeScale;
}



int Engine::SpawnActor( const Actor* object )
{
	if( object )
	{
		auto it = actors.find( object->GetName() );
		if( it == actors.end() )
		{
			((Actor*)object)->Init( this, object->GetName() );
			actors[object->GetName()] = (Actor*)object;
			return 0;
		}
		MAKE_ERROR( this, ErrorMessages::pointerActorNotExist, GetClassName(), String("Object with name: \"") + object->GetName() + "\" already exist", "SpawnActor()" );
		return 1;	// object with this name already exist
	}
	MAKE_ERROR( this, ErrorMessages::pointerActorNotExist, GetClassName(), String("Object sourced do not exist"), "SpawnActor()" );
	return -1;		// given object does not exist
}

PhysicsMesh * Engine::LoadPhysicsMesh( const String& name, const String& fileName, const int fileFormatVersion )
{
	auto it = physicsMesh.find( name );
	if( it == physicsMesh.end() )
	{
		PhysicsMesh * temp = new PhysicsMesh;
		if( temp )
		{
			temp->SetName( name );
			if( temp->LoadFromFile( fileName, fileFormatVersion ) )
			{
				delete temp;
				return NULL;
			}
			
			physicsMesh[name] = temp;
			return temp;
		}
		return NULL;
	}
	return NULL;	// 	it->val;
}


inline PhysicsMesh * Engine::GetPhysicsMesh( const String& name ) const
{
	auto it = physicsMesh.find( name );
	if( it != physicsMesh.end() )
		return it->val;
	return NULL;
}

inline Actor * Engine::GetActor( const String& name ) const
{
	auto it = actors.find( name );
	if( it != actors.end() )
		return it->val;
	return NULL;
}


inline void Engine::DestroyPhysicsMesh( const String& name )
{
	auto it = physicsMesh.find( name );
	if( it != physicsMesh.end() )
	{
		delete it->val;
		physicsMesh.erase( it );
	}
}

inline void Engine::DestroyActor( const String& name )
{
	auto it = actors.find( name );
	if( it != actors.end() )
	{
		colliderActor.RemoveObject( it->val );
		delete it->val;
		actors.erase( it );
	}
}

inline void Engine::GetActor( const AABB& aabb, Map < Actor*, bool >& objects ) const
{
	colliderActor.GetObject( aabb, objects );
}

inline void Engine::GetActor( const AABB& aabb, Array < Actor* >& objects ) const
{
	Map < Actor*, bool > temp;
	colliderActor.GetObject( aabb, temp );
	objects.resize( temp.size() );
	unsigned long long int i = 0;
	for( auto it = temp.begin(); it < temp.end(); ++it, ++i )
	{
		objects[i] = it->key;
	}
}


int Engine::GetNextError( Error& error )
{
	if( errors.size() > 0 )
	{
		error = errors.front();
		errors.erase( errors.begin(), errors.begin() + 1 );
	}
	return errors.size();
}

void Engine::AddError( const Error error )
{
	errors.push_back( error );
}




void Engine::UpdateColliderActorStatic( ActorStatic * object )
{
	colliderActor.AddObject( object, object->GetAABB() );
}

void Engine::UpdateColliderActor()
{
	ActorStatic * object;
	for( auto it = actors.begin(); it != actors.end(); *it++ )
	{
		if( it->val )
		{
			if( dynamic_cast < ActorDynamic* >( it->val ) )
			{
				colliderActor.AddObject( it->val, it->val->GetAABB() );
			}
			else if( object = dynamic_cast < ActorStatic* >( it->val ) )
			{
				if( object->DoesColliderNeedUpdate() )
				{
					UpdateColliderActorStatic( object );
					object->ColliderUpdated();
				}
			}
			else
			{
				MAKE_ERROR( this, ErrorMessages::castingActorIsNotStaticOrDynamic, GetClassName(), it->key, "UpdateColliderActor()" );
			}
		}
		else
		{
			MAKE_ERROR( this, ErrorMessages::pointerActorNotExist, GetClassName(), it->key, "UpdateColliderActor()" );
		}
	}
}




void Engine::UpdatePhysics()
{
	for( auto it = actors.begin(); it != actors.end(); *it++ )
	{
		CollisionManager::CollisionActor( it->val );
	}
}






void Engine::Init( int * argc, char *** argv )
{
	Error::PrepareErrorLogFile( "error.log" );
	printf( "\n Error: Engine::Init() is missing. " );
}




#endif

