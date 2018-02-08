
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef COLLISION_MANAGER_CPP
#define COLLISION_MANAGER_CPP

#include "../css/CollisionManager.h"

namespace CollisionManager
{
	void CollisionOBBOBB( ActorOBB * actorA, ActorOBB * actorB );
	
	void CollisionOBBStatic( ActorOBB * actorA, ActorStatic * actorB )
	{
		Array < Vector, 4 > intersections;
		int i;
		
		{
			Array < int > triangles;
			actorB->GetTriangles( actorA->GetAABB(), triangles );
			for( i = 0; i < triangles.size(); ++i )
			{
				Vector point;			// current point
				Triangle triangle;
				Vector ray;
				Vector normal = triangle.GetNormal();
				
				actorB->GetTriangle( triangles[i], triangle );
				triangle.Move( - actorA->GetPosition() );
				triangle.Rotate( actorA->GetRotation().Inversed() );
				triangle.Scale( 1.0f / actorA->GetSize() );
				
				{	// collision actorA with triangle
					for( ... )
					{
						
						
						
						if( #collide# )
						{
							intersections.push_back( ( actorA->GetRotation() * point ) * actorA->GetSize() );
						}
					}
				}
				
				if( intersections.size() > 0 )
				{
					Vector barycenter = intersections[0];
					for( i = 1; i < intersections.size(); ++i )
					{
						barycenter += intersections[i];
					}
					barycenter /= (float)intersections.size();
					
					Vector stepIn = actorA->GetPointFromPreviousFrame(barycenter) - barycenter;
					
					float force = stepIn.Length() * pushingOutFactor * actorA->GetMass();
					
					if( normal.Dot(stepIn) < 0.0f )
						actorA->AddForce( normal * -force );
					else
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
		std::vector < Actor * > objects;
		actor->GetEngine()->GetActor( actor->GetAABB(), objects );
		int i;
		for( i = 0; i < objects.size(); ++i )
		{
			if( objects[i] > actor )
			{
				if( IsCollisionChannelsOverlap( actor, objects[i] ) )
				{
					if( actor->GetAABB().IsSharedPart( object[i]->GetAABB() ) )
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

