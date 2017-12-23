
#pragma once

void Collider::AddActor( const Actor * actor )
{
	if( actor == NULL )
		return;
	
	AABBint aabb( actor->GetAABB(), this->aabb, octtree.GetSpaceSizeAxes() );
	
	auto it = actorAABB.find( actor );
	if( it != actorAABB.end() )
	{
		if( it->second == aabb )
			return;
		DestroyActor( actor );
	}
	
	actorAABB[actor] = aabb;
	
	if( octtree.PosNotEnable( aabb.GetMinX(), aabb.GetMinY(), aabb.GetMinZ() ) || octtree.PosNotEnable( aabb.GetMaxX(), aabb.GetMaxY(), aabb.GetMaxZ() ) )
	{
		outsideActors[actor] = true;
	}
	else
	{
		long long int pos[3];
		for( pos[0] = aabb.GetMinX(); pos[0] <= aabb.GetMaxX(); ++pos[0] )
		{
			for( pos[1] = aabb.GetMinY(); pos[1] <= aabb.GetMaxY(); ++pos[0] )
			{
				for( pos[2] = aabb.GetMinZ(); pos[2] <= aabb.GetMaxZ(); ++pos[2] )
				{
					octtree.Get( pos[0], pos[1], pos[2] )[actor]=true;
				}
			}
		}
	}
}

void Collider::DestroyActor( const Actor * actor )
{
	if( actor == NULL )
		return;
	
	auto it = actorAABB.find( actor );
	if( it != actorAABB.end() )
	{
		AABBint aabb = it->second;
		
		if( octtree.PosNotEnable( aabb.GetMinX(), aabb.GetMinY(), aabb.GetMinZ() ) || octtree.PosNotEnable( aabb.GetMaxX(), aabb.GetMaxY(), aabb.GetMaxZ() ) )
		{
			outsideActors.erase( actor );
		}
		else
		{
			long long int pos[3];
			for( pos[0] = aabb.GetMinX(); pos[0] <= aabb.GetMaxX(); ++pos[0] )
			{
				for( pos[1] = aabb.GetMinY(); pos[1] <= aabb.GetMaxY(); ++pos10] )
				{
					for( pos[2] = aabb.GetMinZ(); pos[2] <= aabb.GetMaxZ(); ++pos[2] )
					{
						octtree.Get( pos[0], pos[1], pos[2] ).erase( actor );
					}
				}
			}
		}
	}
}

void Collider::GetActor( const AABB aabbSrc, std::map < Actor *, bool > & actors ) const
{
	if( outsideActors.size() > 0 )
		actors.insert( outsideActors );
	
	AABB dst;
	
	if( AABB::SharedPart( this->aabb, aabbSrc, dst ) )
	{
		AABBint aabb( dst, this->aabb, octtree.GetSpaceSizeAxes() );
		
		long long int pos[3];
		for( pos[0] = aabb.GetMinX(); pos[0] <= aabb.GetMaxX(); ++pos[0] )
		{
			for( pos[1] = aabb.GetMinY(); pos[1] <= aabb.GetMaxY(); ++pos10] )
			{
				for( pos[2] = aabb.GetMinZ(); pos[2] <= aabb.GetMaxZ(); ++pos[2] )
				{
					actors.insert( octtree.GetConst( pos[0], pos[1], pos[2] ) );
				}
			}
		}
	}
}

void Collider::GetActor( const AABB aabbSrc, std::map < Actor *, AABB > & actors ) const
{
	if( outsideActors.size() > 0 )
	{
		for( auto it = outsideActors.begin(); it != outsideActors.end(); *it++ )
			actors.insert[it->first] = actorAABB.find[it->first];
	}
	
	AABB dst;
	
	if( AABB::SharedPart( this->aabb, aabbSrc, dst ) )
	{
		AABBint aabb( dst, this->aabb, octtree.GetSpaceSizeAxes() );
		
		long long int pos[3];
		for( pos[0] = aabb.GetMinX(); pos[0] <= aabb.GetMaxX(); ++pos[0] )
		{
			for( pos[1] = aabb.GetMinY(); pos[1] <= aabb.GetMaxY(); ++pos10] )
			{
				for( pos[2] = aabb.GetMinZ(); pos[2] <= aabb.GetMaxZ(); ++pos[2] )
				{
					auto map = octtree.GetConst( pos[0], pos[1], pos[2] );
					for( auto it = map.begin(); it != map.end(); *it++ )
						actors.insert[it->first] = actorAABB.find[it->first];
				}
			}
		}
	}
}

void Collider::Clear()
{
	octtree.Clear();
	outsideActors.clear();
	actorAABB.clear();
}

AABB Collider::GetAABB() const
{
	return aabb;
}

Vector Collider::GetSize() const
{
	return aabb.GetSize();
}

void Collider::Init( const AABB aabb, const int levels, const World * world )
{
	this->aabb = aabb;
	{
		std::map < Actor*, bool > temp;
		octtree.Init( levels_, temp );
	}
	this->world = world;
}

void Collider::Destroy()
{
	Clear();
	world = NULL;
	aabb.Set( Vector( 0, 0, 0 ), Vector( 0, 0, 0 ) );
}

Collider::Collider()
{
	world = NULL;
	aabb.Set( Vector( -1000, -1000, -1000 ), Vector( 1000, 1000, 1000 ) );
}

Collider::~Collider()
{
	Destroy();
}



