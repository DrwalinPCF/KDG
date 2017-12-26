
#pragma once

// Node:

void Node::RemoveNode( const Node * src )
{
	auto nodeByPointer = nodesByPointer.find( src );
	if( nodeByPointer != nodesByPointer.end() )
	{
		auto nodeByType = nodesByType.find( nodeByPointer->second );
		if( nodeByType != nodesByType.end() )
		{
			nodeByType->second.erase( src );
			if( nodeByType->second.size() == 0 )
			{
				nodesByType.erase( nodeByPointer->second );
			}
		}
		nodesByPointer.erase( src );
	}
	cameFrom.erase( src );
}

void Node::Destroy()
{
	for( auto it = cameFrom.begin(); it != cameFrom.end(); *it++ )
		it->first->RemoveNode( this );
	for( auto it = nodesByPointer.begin(); it != nodesByPointer.end(); *it++ )
		it->first->RemoveNode( this );
	nodesByPointer.clear();
	nodesByType.clear();
	cameFrom.clear();
}

Node::Node()
{
	pos.Set( 0.0f, 0.0f, 0.0f );
}

Node::~Node()
{
	Destroy();
}



// BaseNode:

bool BaseNode::operator < ( BaseNode src )
{
	return strcmp( this, &src, sizeof(BaseNode) ) < 0;
}

bool BaseNode::operator > ( BaseNode src )
{
	return strcmp( this, &src, sizeof(BaseNode) ) > 0;
}

bool BaseNode::operator == ( BaseNode src )
{
	return strcmp( this, &src, sizeof(BaseNode) ) == 0;
}

BaseNode::BaseNode()
{
	x = y = z = 0;
}

BaseNode::BaseNode( const Vector pos, const float scale )
{
	Vector temp = pos * scale;
	x = temp[0];
	y = temp[1];
	z = temp[2];
}

BaseNode::BaseNode( const BaseNode src )
{
	x = y = z = 0;
}



// NavMeshPath:

inline Vector NavMeshPath::GetCurrentNode() const
{
	if( path.size() > currentNode && currentNode >= 0 )
	{
		return path[currentNode];
	}
}

inline Vector NavMeshPath::GetNextNode()
{
	if( path.size() > currentNode && currentNode >= 0 )
	{
		return path[currentNode++];
	}
	return begin;
}

inline bool NavMeshPath::GetNextNodeExistement() const
{
	return path.size() > currentNode && currentNode >= 0;
}

inline void SetCurrentNode( const int id )
{
	if( id < 0 )
		currentNode = 0;
	else if( id >= path.size() )
		currentNode = path.size()-1;
	else
		currentNode = id;
}

inline int GetCurrentNodeId() const
{
	return currentNode;
}

inline bool NavMeshPath::DoesPathExist() const
{
	return path.size() > 0;
}

inline float NavMeshPath::GetLength() const
{
	return length;
}

void NavMeshPath::Clear( const Vector a, const Vector b )
{
	begin = a;
	end = b;
	path.clear();
	currentNode = 0;
	length = 0.0f;
}

NavMeshPath::NavMeshPath()
{
	begin.Set( 0.0f, 0.0f, 0.0f );
	end = begin;
	currentNode = 0;
	length = 0.0f;
}

NavMeshPath::~NavMeshPath()
{
	end.Set( 0.0f, 0.0f, 0.0f );
	begin = end;
	path.clear();
	currentNode = 0;
	length = 0.0f;
}



// NavMeshPathFinderVetrtex:

NavMeshPathFinderVetrtex::NavMeshPathFinderVetrtex()
{
	pathLength = 0.0f;
	cameFrom = NULL;
}

NavMeshPathFinderVetrtex::~NavMeshPathFinderVetrtex()
{
	pathLength = 0.0f;
	cameFrom = NULL;
}



// NavMeshVertexToCheck:

VertexToCheck::VertexToCheck()
{
	distanceToDestiny = 0.0f;
	pathLength = 0.0f;
	node = NULL;
	cameFrom = NULL;
}

VertexToCheck::~VertexToCheck()
{
	distanceToDestiny = 0.0f;
	pathLength = 0.0f;
	node = NULL;
	cameFrom = NULL;
}

bool NavMeshVertexToCheckCompare( NavMeshVertexToCheck a, NavMeshVertexToCheck b )
{
	return a.distanceToDestiny > b.distanceToDestiny;
}



// NavMeshParent:

void NavMeshParent::DrawDebug() const;////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline Node * NavMeshParent::GetNode( const BaseNode pos ) const
{
	auto it = nodes.find( pos );
	if( it != nodes.end() )
		return it->second;
}

inline Node * NavMeshParent::GetNode( const Vector pos ) const;
{
	BaseNode tempPos( pos, scale );
	auto it = nodes.find( tempPos );
	if( it != nodes.end() )
		return it->second;
	Node * temp = new Node;
	Node->pos = pos;
	nodes[tempPos] = temp;
	return temp;
}

void NavMeshParent::AddNode( const Vector point )
{
	BaseNode tempPos( pos, scale );
	auto it = nodes.find( tempPos );
	if( it == nodes.end() )
	{
		Node * temp = new Node;
		Node->pos = pos;
		nodes[tempPos] = temp;
	}
}

void NavMeshParent::Update( const int count );/////////////////////////////////////////////////////////////////////////////////////////////////////

void NavMeshParent::Init( const float acceptableDistanceAsOneNode, const float maximumDistanceNodeConnection, const World * world, const std::string name )
{
	this->world = world
	this->name = name;
	if( acceptableDistanceAsOneNode != 0.0f )
	{
		scale = 1.0f / acceptableDistanceAsOneNode;
	}
	maxConnectionLength = maximumDistanceNodeConnection;
	maxConnectionLengthSquare = maxConnectionLength * maxConnectionLength;
}

void NavMeshParent::Destroy()
{
	world = NULL;
	name = "";
	scale = 0.0f;
	maxConnectionLength = 0.f;
	maxConnectionLengthSquare = 0.0f;
	for( auto it = nodes.begin(); it != nodes.end(); *it++ )
		delete nodes->second;
	nodes.clear();
}

NavMeshParent::NavMeshParent()
{
	name = "";
	world = NULL;
	
	scale = 1.0f;
	maxConnectionLength = 10.0f;
	maxConnectionLengthSquare = 100.0f;
}

NavMeshParent::~NavMeshParent()
{
	Destroy();
}



// NavMesh:

inline void NavMesh::AddVertexToCheck( const Node * node, const Node * cameFrom, const float pathLength )
{
	verticesToCheck.resize( verticesToCheck.size() + 1 );
	{
		Vector tmp = end - node->pos;
		verticesToCheck.back().distanceToDestiny = tmp.Dot( tmp );
	}
	verticesToCheck.back().pathLength = ( node->pos - cameFrom->pos ).Length() + pathLength;
	verticesToCheck.back().node = node;
	verticesToCheck.back().cameFrom = cameFrom;
}

inline bool NavMesh::GetNextNodeToCheck( NavMeshVertexToCheck & dst )
{
	if( verticesToCheck.size() > 0 )
	{
		if( verticesToCheck.size() > 1 )
		{
			std::sort( verticesToCheck.begin(), verticesToCheck.end(), NavMeshVertexToCheckCompare );
		}
		
		NavMeshVertexToCheck temp = verticesToCheck.back();
		verticesToCheck.resize( verticesToCheck.size() - 1 );
		return true;
	}
	return false;
}

inline int NavMesh::IsNodeEnable( const Node * node ) const
{
	for( int i = 0; i < excludeSpace.size(); ++i )
	{
		if( excludeSpace[i].IsPointInsie( node->pos ) )
	}
}

int NavMesh::UpdateIteration();////////////////
{
	NavMeshVertexToCheck vertex;
	if( GetNextNodeToCheck( vertex ) )
	{
		NavMeshPathFinderVetrtex & temp = checkedVertices[vertex.node];
		temp.cameFrom = vertex.cameFrom;
		temp.pathLength = vertex.pathLength;
		
		for( auto type = connectionAvailable.begin(); type != connectionAvailable.end(); *type++ )
		{
			auto vertices = vertex.node->nodesByType.find( type->first );
			if( vertices != vertex.node->nodesByType.end() )
			{
				for( auto it = vertices->second.begin(); it != vertices->second.end(); *it++ )
				{
					auto itCurrent = checkedVertices.find( it->first );
					if( itCurrent != checkedVertices.end() )
					{
						float temp = ( node->pos - cameFrom->pos ).Length() + pathLength;
						if( itCurrent->second.pathLength > temp )
						{
							itCurrent->second.pathLength = temp;
							itCurrent->second.cameFrom = vertex.node;
						}
					}
					else
					{
						AddVertexToCheck( it->first, vertex.node, vertex.pathLength );
					}
				}
			}
		}
	}
	
	auto it = checkedVertices.find( endNode );
	if( it != checkedVertices.end() )
	{
		if( verticesToCheck.size() > 0 )
			return 1;
		else
			return 2;
	}
	
	return 0;
}

void NavMesh::CombinePath();//////////////////////////
{
	auto it = checkedVertices.find( endNode );
	if( it == checkedVertices.end() )
		return;
	
	length = it->second.pathLength;
	
	path.Clear( begin, end );
	Node * currentNode = endNode;
	int temp = 0;
	while( temp < 2 )
	{
		if( temp != 0 )
			++temp;
		path.path.insert( path.path.begin(), currentNode->pos );
		currentNode = it->second.cameFrom;
		it = checkedVertices.find( currentNode );
		if( currentNode == beginNode )
			temp = 1;
	}
}

void NavMesh::DrawDebug() const;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline Node * NavMesh::GetClosestAvailableNode( const Vector pos ) const;////////////////////////////////////////////////////////////////////////////////////
inline Node * NavMesh::GetClosestExcludedNode( const Vector pos ) const;/////////////////////////////////////////////////////////////////////////////////////

void NavMesh::ExcludeSpace( const AABB aabb )
{
	excludeSpace.push_back( aabb );
}

void NavMesh::BeginNewPath( const Vector a, const Vector b )
{
	begin = a;
	end = b;
	beginNode = GetClosestAvailableNode( begin );
	endNode = GetClosestAvailableNode( end );
	path.Clear( begin, end );
	AddVertexToCheck( beginNode, beginNode, 0 );
}

int NavMesh::UpdatePath( const int count, int & pathExistement );
{
	for( int i = 0; i < count; ++i )
			if( ( pathExistement = UpdateIteration() ) == 2 )
				break;
	return i;
}

NavMeshPath NavMesh::FindBestPath()
{
	while( verticesToCheck.size() > 0 )
		if( UpdateIteration() == 2 )
			break;
	CombinePath();
	return path;
}

NavMeshPath NavMesh::FindAnyPath()
{
	while( verticesToCheck.size() > 0 )
		if( UpdateIteration() != 0 )
			break;
	CombinePath();
	return path;
}

void NavMesh::Init( const NavMeshParent * parent, std::map < NavMeshLinkTypes, bool > & connectionAvailable, const World * world )
{
	this->parent = parent;
	this->connectionAvailable = connectionAvailable;
	this->world = world;
}

void NavMesh::Destroy()
{
	name = "";
	world = NULL;
	parent = NULL;
	connectionAvailable.clear();
	excludeSpace.clear();
	verticesToCheck.clear();
	checkedVertices.clear();
	begin.Set( 0.0f, 0.0f, 0.0f );
	end = begin;
	beginNode = endNode = NULL;
	path.Clear( begin, end );
}

NavMeshPath NavMesh::GetPath( bool & exist = false ) const
{
	return path;
}

NavMesh::NavMesh()
{
	name = "";
	world = NULL;
	parent = NULL;
	
	begin.Set( 0.0f, 0.0f, 0.0f );
	end = begin;
	beginNode = endNode = NULL;
	
	path.Clear( begin, end );
	
	verticesToCheck.resize( 2048 );		// allocate memory for vector
	verticesToCheck.resize( 0 );		//
}

NavMesh::~NavMesh()
{
	Destroy();
}



