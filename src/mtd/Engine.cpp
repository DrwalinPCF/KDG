
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef ENGINE_CPP
#define ENGINE_CPP

#include "../css/Engine.h"
#include "../css/ActorStatic.h"
#include "../css/ActorDynamic.h"
#include "../css/ActorOBB.h"


inline std::string Engine::GetClassName()
{
	return std::string( "Engine" );
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


inline void Engine::GetActor( const AABB& aabb, std::vector < Actor* >& objects ) const
{
	colliderActor.GetObject( aabb, objects );
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
		MAKE_ERROR( this, ErrorMessages::pointerActorNotExist, GetClassName(), std::string("Object with name: \"") + object->GetName() + "\" already exist", "SpawnActor()" );
		return 1;	// object with this name already exist
	}
	MAKE_ERROR( this, ErrorMessages::pointerActorNotExist, GetClassName(), std::string("Object sourced do not exist"), "SpawnActor()" );
	return -1;		// given object does not exist
}

PhysicsMesh * Engine::LoadPhysicsMesh( const std::string& name, const std::string& fileName, const int fileFormatVersion )
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
	return NULL;	// 	it->second;
}


inline PhysicsMesh * Engine::GetPhysicsMesh( const std::string& name ) const
{
	auto it = physicsMesh.find( name );
	if( it != physicsMesh.end() )
		return it->second;
	return NULL;
}

inline Actor * Engine::GetActor( const std::string& name ) const
{
	auto it = actors.find( name );
	if( it != actors.end() )
		return it->second;
	return NULL;
}


inline void Engine::DestroyPhysicsMesh( const std::string& name )
{
	auto it = physicsMesh.find( name );
	if( it != physicsMesh.end() )
	{
		delete it->second;
		physicsMesh.erase( it );
	}
}

inline void Engine::DestroyActor( const std::string& name )
{
	auto it = actors.find( name );
	if( it != actors.end() )
	{
		colliderActor.RemoveObject( it->second );
		delete it->second;
		actors.erase( it );
	}
}




int Engine::GetNextError( Error & error )
{
	if( errors.size() )
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
		if( it->second )
		{
			if( dynamic_cast < ActorDynamic* >( it->second ) )
			{
				colliderActor.AddObject( it->second, it->second->GetAABB() );
			}
			else if( object = dynamic_cast < ActorStatic* >( it->second ) )
			{
				if( object->DoesColliderNeedUpdate() )
				{
					UpdateColliderActorStatic( object );
					object->ColliderUpdated();
				}
			}
			else
			{
				MAKE_ERROR( this, ErrorMessages::castingActorIsNotStaticOrDynamic, GetClassName(), it->first, "UpdateColliderActor()" );
			}
		}
		else
		{
			MAKE_ERROR( this, ErrorMessages::pointerActorNotExist, GetClassName(), it->first, "UpdateColliderActor()" );
		}
	}
}




void Engine::UpdatePhysics()
{
	for( auto it = actors.begin(); it != actors.end(); *it++ )
	{
		CollisionManager::CollisionActor( it->second );
	}
}






void Engine::Init( int * argc, char *** argv )
{
	Error::PrepareErrorLogFile( "error.log" );
	printf( "\n Error: Engine::Init() is missing. " );
}




#endif

