
#ifndef QUADTREE_H
#define QUADTREE_H

#include <cstring>
#include <cstdio>
#include <vector>

typedef unsigned long long int quadtreePosDataType;
#define QUADTREE_PRINTF_SPECIFIER %LLd

template < class T >
class QuadtreeNode
{
public:
	QuadtreeNode<T> * node[2][2];
	T * data;
	
	void Destroy();
	
	int GetNodeNumber();
	void Print( const int i );
	
	QuadtreeNode();
	~QuadtreeNode();
};

template < class T >
class Quadtree
{
public:
	QuadtreeNode<T> node;
	T defaultValue;
	T defaultValueCopy;
	int lvl;
	
	inline bool Exist( const quadtreePosDataType _x, const quadtreePosDataType _y );
	inline void Set( const quadtreePosDataType _x, const quadtreePosDataType _y, const T src );
	inline T& Get( const quadtreePosDataType _x, const quadtreePosDataType _y );
	inline void Erase( const quadtreePosDataType _x, const quadtreePosDataType _y );
	
	inline quadtreePosDataType GetNumberOfNodes();
	inline void Print();
	
	inline quadtreePosDataType GetSpaceSizeAxes();
	
	inline void Clear();
	
	inline void Init( const quadtreePosDataType levels_, const T defaultValue_ );
	
	Quadtree();
	~Quadtree();
};

#endif



