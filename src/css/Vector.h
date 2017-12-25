
#ifndef VECTOR_H
#define VECTOR_H

#include "../Includer.h"

class Vector
{
private:
	
	float x, y, z;
	
public:
	
	friend class Quat;
	
	inline float& operator [] ( int a );
	
	inline Vector operator + ( const Vector& src ) const;
	inline Vector& operator += ( const Vector& src );
	inline Vector operator - ( const Vector& src ) const;
	inline Vector& operator -= ( const Vector& src );
	
	inline Vector operator && ( const Vector& src ) const;
	
	inline Vector operator * ( const Vector& src ) const;
	inline Vector& operator *= ( const Vector& src );
	inline Vector operator * ( const float src ) const;
	inline Vector& operator *= ( const float src );
	inline Vector operator / ( const Vector& src ) const;
	inline Vector& operator /= ( const Vector& src );
	inline Vector operator / ( const float src ) const;
	inline Vector& operator /= ( const float src );
	
	inline bool operator == ( const Vector& src ) const;
	inline bool operator != ( const Vector& src ) const;
	inline bool operator < ( const float src ) const;
	inline bool operator > ( const float src ) const;
	inline bool operator < ( const Vector& src ) const;
	inline bool operator > ( const Vector& src ) const;
	inline bool operator <= ( const Vector& src ) const;
	inline bool operator >= ( const Vector& src ) const;
	
	inline Vector& Set( const float x, const float y, const float z );
	
	inline Vector Cross( const Vector& src ) const;
	inline float Dot( const Vector& src ) const;
	inline float Lenght() const;
	inline Vector Versor() const;
	inline Vector& Normalize();
	inline Vector& CreateVector( const Vector& src1, const Vector& src2 );
	
	inline void SetLenght( const float dst );
	inline void GoToVector( const Vector& dst, const float velocity );
	inline void GoToLenght( const float dst, const float velocity );
	
	Vector();
	Vector( const float x, const float y, const float z );
};

#endif

