/*
	Copyright (C) 2017 Marek Zalewski
	
	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.
	
	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1.	The origin of this software must not be misrepresented; you must not
		claim that you wrote the original software. If you use this software
		in a product, an acknowledgment in the product documentation is required.
	2.	Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.
	3.	This notice may not be removed or altered from any source distribution.
*/

#ifndef NAV_MESH_H
#define NAV_MESH_H

class Engine;

#include "../lib/MZ/SourceCode/Map.cpp"
#include "../lib/MZ/SourceCode/Array.cpp"

#include "../lib/MZ/SourceHeader/Vector.h"

#include "Engine.h"

enum NavMeshLinkTypes
{
	WALK,
	SWIM,
	FLY,
	CLIMB,
	FALL,
	JUMP
};

class Node;
class BaseNode;
class NavMeshPath;
class NavMeshPathFinderVetrtex;
class NavMeshVertexToCheck;
class NavMeshParent;
class NavMesh;

bool NavMeshVertexToCheckCompare( NavMeshVertexToCheck a, NavMeshVertexToCheck b );

class Node
{
private:
	
	Vector pos;				// real pos
	
	Map < Node*, NavMeshLinkTypes > nodesByPointer;
	Map < NavMeshLinkTypes, Map < Node*, bool > > nodesByType;
	
	Map < Node*, NavMeshLinkTypes > cameFrom;
	
public:
	
	friend class NavMesh;
	friend class NavMeshParent;
	
	void RemoveNode( Node * src );
	void Destroy();
	
	void AddNode( Node * src, const NavMeshLinkTypes type );
	
	Node();
	~Node();
};

class BaseNode
{
private:
	
	long long int x, y, z;
	
public:
	
	friend class NavMesh;
	friend class NavMeshParent;
	
	bool operator < ( const BaseNode& src ) const;
	bool operator > ( const BaseNode& src ) const;
	bool operator == ( const BaseNode& src ) const;
	
	BaseNode();
	BaseNode( const Vector pos, const float scale );
};

class NavMeshPath
{
private:
	
	Vector begin, end;
	Array < Vector > path;
	int currentNode;
	float length;
	
public:
	
	friend class NavMesh;
	friend class NavMeshParent;
	
	inline Vector GetCurrentNode() const;
	inline Vector GetNextNode();		// return path[currentNode++];
	inline bool GetNextNodeExistement() const;
	inline void SetCurrentNode( const int id );
	inline int GetCurrentNodeId() const;
	inline bool DoesPathExist() const;
	inline float GetLength() const;
	
	void Clear( const Vector a, const Vector b );
	
	NavMeshPath();
	~NavMeshPath();
};

class NavMeshPathFinderVetrtex
{
private:
	float pathLength;		// from begin
	Node * cameFrom;
	
public:
	
	friend NavMesh;
	
	NavMeshPathFinderVetrtex();
	~NavMeshPathFinderVetrtex();
};

class NavMeshVertexToCheck
{
private:
	
	float pathLength;
	Node * node;
	Node * cameFrom;
	float distanceToDestiny;	// quadratic
	
public:
	
	friend class NavMesh;
	friend int NavMeshVertexToCheckCompare( const void * a, const void * b );
	
	NavMeshVertexToCheck();
	~NavMeshVertexToCheck();
};

class NavMeshParent
{
public:
	
	static Map < NavMeshLinkTypes, bool > connectionTypes;
	
private:
	
	String name;
	Engine * engine;
	
	Map < BaseNode, Node* > nodes;
	
	float scale;
	float maxConnectionLength;
	float maxConnectionLengthSquare;
	
	inline Node * GetNode( const BaseNode pos ) const;
	inline Node * GetNode( const Vector pos );				// create if not exist
	
public:
	
	static inline String GetClassName();
	
	friend class NavMesh;
	
	void DrawDebug() const;
	
	void AddNode( const Vector point );
	void Update( const int count );
	
	void Init( const float acceptableDistanceAsOneNode, const float maxConnectionLength, const Engine * engine, const String name );
	void Destroy();
	
	NavMeshParent();
	~NavMeshParent();
};

class NavMesh
{
private:
	
	String name;
	Engine * engine;
	NavMeshParent * parent;
	
	Map < NavMeshLinkTypes, bool > connectionAvailable;		// types
	
	Array < AABB > excludeSpace;
	//Array < AABB > lastResortSpace;									// can use graph node from these space only if there are no other path
	//Array < NavMeshVertexToCheck > lastResortVerticesToCheck;		// must be sorted before taking vertex, use only: if( verticesToCheck.size() == 0 ){...}
	Array < NavMeshVertexToCheck > verticesToCheck;					// must be sorted before taking vertex
	Map < Node *, NavMeshPathFinderVetrtex > checkedVertices;			// on the path
	
	Vector begin, end;
	Node * beginNode, * endNode;
	
	NavMeshPath path;
	
	inline void AddVertexToCheck( const Node * node, const Node * cameFrom, const float pathLength );
	inline bool GetNextNodeToCheck( NavMeshVertexToCheck & dst );
	
	inline int IsNodeDisable( const Node * node ) const;					// return 0 if enable; -1 if not enable; /* 1 if last resorted */
	
	int UpdateIteration();		// return: 0 - path not exist, 1 - exist any path (probably not the best), 2 - exist best path
	
public:
	
	static inline String GetClassName();
	
	void CombinePath();
	
	void DrawDebug() const;
	
	inline Node * GetClosestAvailableNode( const Vector pos ) const;
	inline Node * GetClosestLastResortNode( const Vector pos ) const;
	inline Node * GetClosestExcludedNode( const Vector pos ) const;
	
	void ExcludeSpace( const AABB aabb );
	//void IncludeSpace( const AABB aabb );		// very un optimal, slow, need a lot of memory
	
	void BeginNewPath( const Vector a, const Vector b );
	int UpdatePath( const int count, int & pathExistement );
	NavMeshPath FindBestPath();
	NavMeshPath FindAnyPath();
	
	void Init( const NavMeshParent * parent, Map < NavMeshLinkTypes, bool > & connectionAvailable, const Engine * engine );
	
	void Destroy();
	
	NavMeshPath GetPath( bool & exist ) const;		// argument - setted on true if path does exist
	
	NavMesh();
	~NavMesh();
};

#endif

