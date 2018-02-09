#define inline
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef COLLISION_MANAGER_CPP
#define COLLISION_MANAGER_CPP

#include "../css/CollisionManager.h"
#include "../css/ActorStatic.h"
#include "../css/ActorDynamic.h"
#include "../css/ActorOBB.h"
#include "../css/Actor.h"

namespace CollisionManager
{
	
	
	void CollisionOBBOBB( ActorOBB * actorA, ActorOBB * actorB );
	
	void CollisionOBBStatic( ActorOBB * actorA, ActorStatic * actorB )
	{
		int i, j;
		float temp;
		
		{
			Array < Vector > axes(4);
			Array < float > min(4);
			Array < float > max(4);
			axes.resize( 15 );
			min.resize( 15 );
			max.resize( 15 );
			Array < int > triangles;
			actorB->GetTriangles( actorA->GetAABB(), triangles );
			for( i = 0; i < triangles.size(); ++i )
			{
				Vector point;			// any point in shared space
				Triangle triangle;
				Vector normal = triangle.GetNormal();
				Vector ab, bc, ca;
				triangle.EdgesDirection( ab, bc, ca );
				
				actorB->GetTriangle( triangles[i], triangle );
				triangle.Move( actorA->GetPosition()*(-1.0f) );
				triangle.Rotate( actorA->GetRotation().Inversed() );
				triangle.Scale( Vector(1.0f) / actorA->GetSize() );
				
				{	// collision actorA with triangle
					axes[0] = normal;
					axes[1].Set( 1.0f, 0.0f, 0.0f );
					axes[2].Set( 0.0f, 1.0f, 0.0f );
					axes[3].Set( 0.0f, 0.0f, 1.0f );
					axes[4] = (ab&&axes[1]).Versor();
					axes[5] = (ab&&axes[2]).Versor();
					axes[6] = (ab&&axes[3]).Versor();
					axes[7] = (bc&&axes[1]).Versor();
					axes[8] = (bc&&axes[2]).Versor();
					axes[9] = (bc&&axes[3]).Versor();
					axes[10] = (ca&&axes[1]).Versor();
					axes[11] = (ca&&axes[2]).Versor();
					axes[12] = (ca&&axes[3]).Versor();
					axes[13] = (normal&&axes[1]).Versor();
					axes[14] = (normal&&axes[2]).Versor();
					axes[15] = (normal&&axes[3]).Versor();
					
					for( j = 0; j < axes.size(); ++j )
					{
						triangle.GetMaxMinWithVector( axes[j], min[j], max[j] );
						temp = abs(axes[j][0]) + abs(axes[j][1]) + abs(axes[j][2]);
						
						if( temp < min[j] || (-temp) > max[j] )
						{
							// next triangle
						}
						
						if( min[j] < temp )
							min[j] = temp;
						if( max[j] > temp )
							max[j] = temp;
						temp = -temp;
						if( min[j] < temp )
							min[j] = temp;
						if( max[j] > temp )
							max[j] = temp;
						
						if( j == 0 )
						{
							point = axes[j] * min[j];
						}
						else
						{
							temp = point.Dot( axes[j] );
							if( temp > max[j] )
							{
								point -= axes[j] * ( temp - max[j] );
							}
							else if( temp < min[j] )
							{
								point += axes[j] * ( min[j] - temp );
							}
						}
					}
					
					/*
						TO DEBUG:
							CHECK IF point IS INSIDE BOTH OBJECTS
					*/
				}
				
				// apply force
				{
					Vector pointMove = actorA->GetPointFromPreviousFrame(point) - point;
					float force = ( actorA->GetPointFromPreviousFrame(point) - point ).dot(normal) * pushingOutFactor * actorA->GetMass();
					
					actorA->AddForce( normal * force );
				}
			}
		}
	}
	
	
	
	inline void CollisionOBBActor( ActorOBB * actorA, Actor * actorB )
	{
		if( dynamic_cast < ActorStatic* > ( actorB ) )
		{
			CollisionOBBStatic( actorA, (ActorStatic*)actorB );
			return;
		}
		if( dynamic_cast < ActorOBB* > ( actorB ) )
		{
			CollisionOBBOBB( actorA, (ActorOBB*)actorB );
			return;
		}
	}
	
	inline void CollisionDynamicActor( ActorDynamic * actorA, Actor * actorB )
	{
		if( dynamic_cast < ActorOBB* > ( actorA ) )
		{
			CollisionOBBActor( (ActorOBB*)actorA, actorB );
			return;
		}
	}
	
	inline void CollisionDynamic( ActorDynamic * actor )
	{
		Array < Actor* > objects;
		actor->GetEngine()->GetActor( actor->GetAABB(), objects );
		int i;
		for( i = 0; i < objects.size(); ++i )
		{
			if( objects[i] > actor )
			{
				if( Actor::IsCollisionChannelsOverlap( actor, objects[i] ) )
				{
					if( actor->GetAABB().IsSharedPart( objects[i]->GetAABB() ) )
					{
						CollisionDynamicActor( actor, objects[i] );
					}
				}
			}
		}
	}
	
	inline void CollisionActor( Actor * actor )
	{
		if( dynamic_cast < ActorDynamic* > ( actor ) )
		{
			CollisionDynamic( (ActorDynamic*)actor );
		}
	}
};

#endif

