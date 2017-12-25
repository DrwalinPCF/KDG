
#ifndef VMATRIX_H
#define VMATRIX_H

#include "../Includer.h"

class VMatrix
{
private:
	
	float m[4][4];
	
public:
	
	inline VMatrix SetMatrix(
		const float src00, const float src01, const float src02, const float src03,
		const float src10, const float src11, const float src12, const float src13,
		const float src20, const float src21, const float src22, const float src23,
		const float src30, const float src31, const float src32, const float src33 );
	inline VMatrix SetMatrix( const VMatrix& src );
	inline VMatrix SetMatrix( const float **src );
	
	inline VMatrix& InitEmpty();
	
	inline VMatrix& operator = ( const VMatrix& src );
	
	inline VMatrix& operator += ( const Vector& src );
	inline VMatrix operator * ( const VMatrix& src ) const;
	inline VMatrix& operator *= ( const VMatrix& src );
	inline Vector operator * ( const Vector& src ) const;
	inline VMatrix operator * ( const float src ) const;
	inline VMatrix& operator *= ( const float src );
	
	inline VMatrix& Translate( const Vector& src );
	inline VMatrix& RotateX( const float angle );
	inline VMatrix& RotateY( const float angle );
	inline VMatrix& RotateZ( const float angle );
	inline VMatrix& Scale( const Vector& src );
	inline VMatrix& Scale( const float src );
	
	inline Vector GetVertex( const Vector& src ) const;
	inline Vector GetVertexBack( const Vector& src ) const;
	
	inline VMatrix GetReverse() const;
	inline VMatrix& Reverse();
	
	inline float GetDet() const;
	
	VMatrix();
};

#endif

