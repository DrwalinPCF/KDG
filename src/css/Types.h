
#ifndef TYPES_H
#define TYPES_H

class Int3
{
private:
	
	int data[3];
	
public:
	
	inline int& operator () ( const int id );
	inline int& operator [] ( const int id );
	
	Int3( const int a, const int b, const int c );
	Int3();
};

#endif

