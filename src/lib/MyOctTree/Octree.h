
#ifndef OCTTREE_H
#define OCTTREE_H

#include <vector>
#include <cstring>
#include <cstdio>

typedef long long int octtreePosDataType;
#define OCTTREE_PRINTF_SPECIFIER %lld

template < class T >
struct OcttreeNode
{
public:
	OcttreeNode<T> * node[2][2][2];
	T * data;
	
	inline void Destroy();
	
	inline octtreePosDataType GetNodeNumber();
	inline void Print( const octtreePosDataType i );
	inline void AddToVboEdges( std::vector < Vector > & points, Vector offset, Vector size );
	
	OcttreeNode();
	~OcttreeNode();
};

template < class T >
struct Octtree
{
public:
	OcttreeNode<T> node;
	T defaultValue;
	T defaultValueCopy;
	octtreePosDataType lvl;
	
	inline bool PosNotEnable( const octtreePosDataType _x, const octtreePosDataType _y, const octtreePosDataType _z );
	
	inline bool Exist( const octtreePosDataType _x, const octtreePosDataType _y, const octtreePosDataType _z );
	inline void Set( const octtreePosDataType _x, const octtreePosDataType _y, const octtreePosDataType _z, const T src );
	inline T& Get( const octtreePosDataType _x, const octtreePosDataType _y, const octtreePosDataType _z );
	inline T& GetConst( const octtreePosDataType _x, const octtreePosDataType _y, const octtreePosDataType _z );		// get only exist node
	inline void Erase( const octtreePosDataType _x, const octtreePosDataType _y, const octtreePosDataType _z );
	
	inline octtreePosDataType GetNumberOfNodes();
	
	inline void Print();
	inline octtreePosDataType GetSpaceSizeAxes();
	
	inline void Clear();
	
	inline void Init( const octtreePosDataType levels_, const T defaultValue_ );
	
	Octtree();
	~Octtree();
};

#endif



