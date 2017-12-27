
#ifndef GAME_CPP
#define GAME_CPP

#include "../css/Game.h"

void Game::SetTimeScale( const float value )
{
	if( value > 0.0001f && value < 1000.0f )
		timeScale = value;;
}

float Game::GetDeltaTime() const
{
	return deltaTime;
}


inline void Game::GetActorDynamic( const AABB& aabb, std::vector < ActorDynamic* >& objects ) const
{
	colliderActorDynamic.GetObject( aabb, objects );
}

inline void Game::GetActorStatic( const AABB& aabb, std::vector < ActorStatic* >& objects ) const
{
	colliderActorStatic.GetObject( aabb, objects );
}


ActorDynamic * Game::SpawnActorDynamic( const std::string& name )
{
	auto it = actorDynamic.find( name );
	if( it == actorDynamic.end() )
	{
		ActorDynamic * temp = new ActorDynamic;
		if( temp )
		{
			actorDynamic[name] = temp;
			temp->SetGame( this );
			temp->SetName( name );
			return temp;
		}
		return NULL;
	}
	return it->second;
}

PhysicsMesh * Game::SpawnPhysicsMesh( const std::string& name )
{
	auto it = physicsMesh.find( name );
	if( it == physicsMesh.end() )
	{
		PhysicsMesh * temp = new PhysicsMesh;
		if( temp )
		{
			physicsMesh[name] = temp;
			temp->SetGame( this );
			temp->SetName( name );
			return temp;
		}
		return NULL;
	}
	return it->second;
}

ActorStatic * Game::SpawnActorStatic( const std::string& name )
{
	auto it = actorStatic.find( name );
	if( it == actorStatic.end() )
	{
		ActorStatic * temp = new ActorStatic;
		if( temp )
		{
			actorStatic[name] = temp;
			temp->SetGame( this );
			temp->SetName( name );
			return temp;
		}
		return NULL;
	}
	return it->second;
}


ActorDynamic * Game::GetActorDynamic( const std::string& name ) const
{
	auto it = actorDynamic.find( name );
	if( it != actorDynamic.end() )
		return it->second;
	return NULL;
}

PhysicsMesh * Game::GetPhysicsMesh( const std::string& name ) const
{
	auto it = physicsMesh.find( name );
	if( it != physicsMesh.end() )
		return it->second;
	return NULL;
}

ActorStatic * Game::GetActorStatic( const std::string& name ) const
{
	auto it = actorStatic.find( name );
	if( it != actorStatic.end() )
		return it->second;
	return NULL;
}


void Game::DestroyActorDynamic( const std::string& name )
{
	auto it = actorDynamic.find( name );
	if( it != actorDynamic.end() )
	{
		colliderActorDynamic.RemoveObject( it->second );
		delete it->second;
		actorDynamic.erase( it );
	}
}

void Game::DestroyPhysicsMesh( const std::string& name )
{
	auto it = physicsMesh.find( name );
	if( it != physicsMesh.end() )
	{
		delete it->second;
		physicsMesh.erase( it );
	}
}

void Game::DestroyActorStatic( const std::string& name )
{
	auto it = actorStatic.find( name );
	if( it != actorStatic.end() )
	{
		colliderActorStatic.RemoveObject( it->second );
		delete it->second;
		actorStatic.erase( it );
	}
}





void Game::UpdateColliderActorStatic( ActorStatic * actor )
{
	colliderActorStatic.AddObject( actor, actor->GetAABB() );
}

void Game::UpdateColliderActorDynamic()
{
	Vector vtemp;
	float ftemp;
	for( auto it = actorDynamic.begin(); it != actorDynamic.end(); *it++ )
	{
		vtemp = it->second->pos-it->second->bpos;
		ftemp = vtemp.Dot( vtemp );
		vtemp = it->second->size-it->second->bsize;
		if( ftemp + vtemp.Dot( vtemp ) >= 0.000001f )
			colliderActorDynamic.AddObject( it->second, it->second->GetAABB() );
	}
}





#endif

