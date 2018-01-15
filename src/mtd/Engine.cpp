
#ifndef ENGINE_CPP
#define ENGINE_CPP

#include "../css/Engine.h"
#include "Collider.cpp"
#include "../lib/MZ/SourceCode/Octtree.cpp"

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


int Engine::SpawnActor( const Actor* object, const std::string& name )
{
	if( object )
	{
		auto it = actor.find( name );
		if( it == actor.end() )
		{
			object->Init( this, name );
			actor[name] = object;
			return 0;
		}
		return 1;	// object with this name already exist
	}
	return -1;		// given object does not exist
}

PhysicsMesh * Engine::LoadPhysicsMesh( const std::string& name, const std::string& fileName, const int fileFormatVersion = -1 )
{
	auto it = physicsMesh.find( name );
	if( it == physicsMesh.end() )
	{
		PhysicsMesh * temp = new PhysicsMesh;
		if( temp )
		{
			temp->SetGame( this );
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
	auto it = actor.find( name );
	if( it != actor.end() )
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
	auto it = actor.find( name );
	if( it != actor.end() )
	{
		colliderActor.RemoveObject( it->second );
		delete it->second;
		actor.erase( it );
	}
}





void Engine::UpdateColliderActorStatic( ActorStatic * object )
{
	colliderActorStatic.AddObject( object, object->GetAABB() );
}

void Engine::UpdateColliderActorDynamic()
{
	Vector vtemp;
	float ftemp;
	ActorDynamic * object;
	for( auto it = actor.begin(); it != actor.end(); *it++ )
	{
		object = dynamic_cast < ActorDynamic* >( it->second );
		if( object )
		{
			colliderActor.AddObject( it->second, it->second->GetAABB() );
		}
	}
}





#endif

