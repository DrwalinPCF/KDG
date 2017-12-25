
#ifndef VMATRIX_CPP
#define VMATRIX_CPP

#include "../css/VMatrix.h"

inline VMatrix VMatrix::SetMatrix(
	float src00, float src01, float src02, float src03,
	float src10, float src11, float src12, float src13,
	float src20, float src21, float src22, float src23,
	float src30, float src31, float src32, float src33 )
{
	m[0][0] = src00; m[0][1] = src01; m[0][2] = src02; m[0][3] = src03;
	m[1][0] = src10; m[1][1] = src11; m[1][2] = src12; m[1][3] = src13;
	m[2][0] = src20; m[2][1] = src21; m[2][2] = src22; m[2][3] = src23;
	m[3][0] = src30; m[3][1] = src31; m[3][2] = src32; m[3][3] = src33;
	return *this;
}

inline VMatrix& VMatrix::operator = ( const VMatrix& src )
{
	m[0][0] = src.m[0][0]; m[0][1] = src.m[0][1]; m[0][2] = src.m[0][2]; m[0][3] = src.m[0][3];
	m[1][0] = src.m[1][0]; m[1][1] = src.m[1][1]; m[1][2] = src.m[1][2]; m[1][3] = src.m[1][3];
	m[2][0] = src.m[2][0]; m[2][1] = src.m[2][1]; m[2][2] = src.m[2][2]; m[2][3] = src.m[2][3];
	m[3][0] = src.m[3][0]; m[3][1] = src.m[3][1]; m[3][2] = src.m[3][2]; m[3][3] = src.m[3][3];
	return *this;
}

inline VMatrix VMatrix::SetMatrix( const VMatrix& src )
{
	m[0][0] = src.m[0][0]; m[0][1] = src.m[0][1]; m[0][2] = src.m[0][2]; m[0][3] = src.m[0][3];
	m[1][0] = src.m[1][0]; m[1][1] = src.m[1][1]; m[1][2] = src.m[1][2]; m[1][3] = src.m[1][3];
	m[2][0] = src.m[2][0]; m[2][1] = src.m[2][1]; m[2][2] = src.m[2][2]; m[2][3] = src.m[2][3];
	m[3][0] = src.m[3][0]; m[3][1] = src.m[3][1]; m[3][2] = src.m[3][2]; m[3][3] = src.m[3][3];
	return *this;
}

inline VMatrix VMatrix::SetMatrix( const float** src )
{
	m[0][0] = src[0][0]; m[0][1] = src[0][1]; m[0][2] = src[0][2]; m[0][3] = src[0][3];
	m[1][0] = src[1][0]; m[1][1] = src[1][1]; m[1][2] = src[1][2]; m[1][3] = src[1][3];
	m[2][0] = src[2][0]; m[2][1] = src[2][1]; m[2][2] = src[2][2]; m[2][3] = src[2][3];
	m[3][0] = src[3][0]; m[3][1] = src[3][1]; m[3][2] = src[3][2]; m[3][3] = src[3][3];
	return *this;
}

inline VMatrix VMatrix::InitEmpty()
{
	SetMatrix(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f );
	return *this;
}

inline VMatrix VMatrix::operator += ( const Vector &src )
{
	VMatrix out;
	out.m[0][3] += src.vector[0];
	out.m[1][3] += src.vector[1];
	out.m[2][3] += src.vector[2];
	return out;
}

inline VMatrix VMatrix::operator * ( const VMatrix &src ) const
{
	VMatrix out;
	out.SetMatrix(
		(m[0][0]*src.m[0][0]) + (m[0][1]*src.m[1][0]) + (m[0][2]*src.m[2][0]) + (m[0][3]*src.m[3][0]),
		(m[0][0]*src.m[0][1]) + (m[0][1]*src.m[1][1]) + (m[0][2]*src.m[2][1]) + (m[0][3]*src.m[3][1]),
		(m[0][0]*src.m[0][2]) + (m[0][1]*src.m[1][2]) + (m[0][2]*src.m[2][2]) + (m[0][3]*src.m[3][2]),
		(m[0][0]*src.m[0][3]) + (m[0][1]*src.m[1][3]) + (m[0][2]*src.m[2][3]) + (m[0][3]*src.m[3][3]),
		
		(m[1][0]*src.m[0][0]) + (m[1][1]*src.m[1][0]) + (m[1][2]*src.m[2][0]) + (m[1][3]*src.m[3][0]),
		(m[1][0]*src.m[0][1]) + (m[1][1]*src.m[1][1]) + (m[1][2]*src.m[2][1]) + (m[1][3]*src.m[3][1]),
		(m[1][0]*src.m[0][2]) + (m[1][1]*src.m[1][2]) + (m[1][2]*src.m[2][2]) + (m[1][3]*src.m[3][2]),
		(m[1][0]*src.m[0][3]) + (m[1][1]*src.m[1][3]) + (m[1][2]*src.m[2][3]) + (m[1][3]*src.m[3][3]),
		
		(m[2][0]*src.m[0][0]) + (m[2][1]*src.m[1][0]) + (m[2][2]*src.m[2][0]) + (m[2][3]*src.m[3][0]),
		(m[2][0]*src.m[0][1]) + (m[2][1]*src.m[1][1]) + (m[2][2]*src.m[2][1]) + (m[2][3]*src.m[3][1]),
		(m[2][0]*src.m[0][2]) + (m[2][1]*src.m[1][2]) + (m[2][2]*src.m[2][2]) + (m[2][3]*src.m[3][2]),
		(m[2][0]*src.m[0][3]) + (m[2][1]*src.m[1][3]) + (m[2][2]*src.m[2][3]) + (m[2][3]*src.m[3][3]),
		
		(m[3][0]*src.m[0][0]) + (m[3][1]*src.m[1][0]) + (m[3][2]*src.m[2][0]) + (m[3][3]*src.m[3][0]),
		(m[3][0]*src.m[0][1]) + (m[3][1]*src.m[1][1]) + (m[3][2]*src.m[2][1]) + (m[3][3]*src.m[3][1]),
		(m[3][0]*src.m[0][2]) + (m[3][1]*src.m[1][2]) + (m[3][2]*src.m[2][2]) + (m[3][3]*src.m[3][2]),
		(m[3][0]*src.m[0][3]) + (m[3][1]*src.m[1][3]) + (m[3][2]*src.m[2][3]) + (m[3][3]*src.m[3][3]) );
	return out;
}

inline VMatrix& VMatrix::operator *= ( const VMatrix &src )
{
	VMatrix out;
	out.SetMatrix(
		(m[0][0]*src.m[0][0]) + (m[0][1]*src.m[1][0]) + (m[0][2]*src.m[2][0]) + (m[0][3]*src.m[3][0]),
		(m[0][0]*src.m[0][1]) + (m[0][1]*src.m[1][1]) + (m[0][2]*src.m[2][1]) + (m[0][3]*src.m[3][1]),
		(m[0][0]*src.m[0][2]) + (m[0][1]*src.m[1][2]) + (m[0][2]*src.m[2][2]) + (m[0][3]*src.m[3][2]),
		(m[0][0]*src.m[0][3]) + (m[0][1]*src.m[1][3]) + (m[0][2]*src.m[2][3]) + (m[0][3]*src.m[3][3]),
		
		(m[1][0]*src.m[0][0]) + (m[1][1]*src.m[1][0]) + (m[1][2]*src.m[2][0]) + (m[1][3]*src.m[3][0]),
		(m[1][0]*src.m[0][1]) + (m[1][1]*src.m[1][1]) + (m[1][2]*src.m[2][1]) + (m[1][3]*src.m[3][1]),
		(m[1][0]*src.m[0][2]) + (m[1][1]*src.m[1][2]) + (m[1][2]*src.m[2][2]) + (m[1][3]*src.m[3][2]),
		(m[1][0]*src.m[0][3]) + (m[1][1]*src.m[1][3]) + (m[1][2]*src.m[2][3]) + (m[1][3]*src.m[3][3]),
		
		(m[2][0]*src.m[0][0]) + (m[2][1]*src.m[1][0]) + (m[2][2]*src.m[2][0]) + (m[2][3]*src.m[3][0]),
		(m[2][0]*src.m[0][1]) + (m[2][1]*src.m[1][1]) + (m[2][2]*src.m[2][1]) + (m[2][3]*src.m[3][1]),
		(m[2][0]*src.m[0][2]) + (m[2][1]*src.m[1][2]) + (m[2][2]*src.m[2][2]) + (m[2][3]*src.m[3][2]),
		(m[2][0]*src.m[0][3]) + (m[2][1]*src.m[1][3]) + (m[2][2]*src.m[2][3]) + (m[2][3]*src.m[3][3]),
		
		(m[3][0]*src.m[0][0]) + (m[3][1]*src.m[1][0]) + (m[3][2]*src.m[2][0]) + (m[3][3]*src.m[3][0]),
		(m[3][0]*src.m[0][1]) + (m[3][1]*src.m[1][1]) + (m[3][2]*src.m[2][1]) + (m[3][3]*src.m[3][1]),
		(m[3][0]*src.m[0][2]) + (m[3][1]*src.m[1][2]) + (m[3][2]*src.m[2][2]) + (m[3][3]*src.m[3][2]),
		(m[3][0]*src.m[0][3]) + (m[3][1]*src.m[1][3]) + (m[3][2]*src.m[2][3]) + (m[3][3]*src.m[3][3]) );
	SetMatrix( out );
	return *this;
}

inline VMatrix VMatrix::operator * ( const Vector &src ) const
{
	Vector out;
	out.vector[0] = (m[0][0]*src.vector[0]) + (m[0][1]*src.vector[1]) + (m[0][2]*src.vector[2]) + m[0][3];
	out.vector[1] = (m[1][0]*src.vector[0]) + (m[1][1]*src.vector[1]) + (m[1][2]*src.vector[2]) + m[1][3];
	out.vector[2] = (m[2][0]*src.vector[0]) + (m[2][1]*src.vector[1]) + (m[2][2]*src.vector[2]) + m[2][3];
	return out;
}

inline VMatrix VMatrix::operator * ( const float src ) const
{
	VMatrix out;
	out.m[0][0] = m[0][0] * src;    out.m[0][1] = m[0][1] * src;    out.m[0][2] = m[0][2] * src;    out.m[0][3] = m[0][3] * src;
	out.m[1][0] = m[1][0] * src;    out.m[1][1] = m[1][1] * src;    out.m[1][2] = m[1][2] * src;    out.m[1][3] = m[1][3] * src;
	out.m[2][0] = m[2][0] * src;    out.m[2][1] = m[2][1] * src;    out.m[2][2] = m[2][2] * src;    out.m[2][3] = m[2][3] * src;
	out.m[3][0] = m[3][0] * src;    out.m[3][1] = m[3][1] * src;    out.m[3][2] = m[3][2] * src;    out.m[3][3] = m[3][3] * src;
	return out;
}

inline VMatrix& VMatrix::operator *= ( const float src )
{
	m[0][0] *= src;    m[0][1] *= src;    m[0][2] *= src;    m[0][3] *= src;
	m[1][0] *= src;    m[1][1] *= src;    m[1][2] *= src;    m[1][3] *= src;
	m[2][0] *= src;    m[2][1] *= src;    m[2][2] *= src;    m[2][3] *= src;
	m[3][0] *= src;    m[3][1] *= src;    m[3][2] *= src;    m[3][3] *= src;
	return *this;
}

inline VMatrix& VMatrix::Translate( const Vector& src )
{
	VMatrix out;
	out.SetMatrix( 1.0f, 0.0f, 0.0f, src[0],
		0.0f, 1.0f, 0.0f, src[1],
		0.0f, 0.0f, 1.0f, src[2],
		0.0f, 0.0f, 0.0f, 1.0f );
	
	(*this) = (*this) * out;
	return *this;
}

inline VMatrix& VMatrix::RotateX( const float angle )
{
	VMatrix out;
	out.SetMatrix(	1.0f,					0.0f,					 0.0f,   0.0f,
					0.0f, cos(angle*3.14159f/180.0f), -sin(angle*3.14159f/180.0f),   0.0f,
					0.0f, sin(angle*3.14159f/180.0f),  cos(angle*3.14159f/180.0f),   0.0f,
					0.0f,                   0.0f,                    0.0f,   1.0f );
	(*this) = (*this) * out;
	return *this;
}

inline VMatrix& VMatrix::RotateY( const float angle )
{
	VMatrix out;
	out.SetMatrix(  cos(angle*3.14159f/180.0f),		0.0f, sin(angle*3.14159f/180.0f),	0.0f,
	                0.0f,    						1.0f,						0.0f,  	0.0f,
					-sin(angle*3.14159f/180.0f),	0.0f, cos(angle*3.14159f/180.0f),	0.0f,
	                0.0f,							0.0f,						0.0f,	1.0f );
	(*this) = (*this) * out;
	return *this;
}

inline VMatrix& VMatrix::RotateZ( const float angle )
{
	VMatrix out;
		out.SetMatrix( cos(angle*3.14159f/180.0f), -sin(angle*3.14159f/180.0f),   0.0f,   0.0f,
		sin(angle*3.14159f/180.0f),  cos(angle*3.14159f/180.0f),   0.0f,   0.0f,
		0.0f,                                      0.0f,   1.0f,   0.0f,
		0.0f,                                      0.0f,   0.0f,   1.0f );
	(*this) = (*this) * out;
	return *this;
}

inline VMatrix& VMatrix::Scale( const Vector& src )
{
	VMatrix out;
	out.SetMatrix( src[0],   0.0f,   0.0f,   0.0f,
		 0.0f, src[1],   0.0f,   0.0f,
		 0.0f,   0.0f, src[2],   0.0f,
		 0.0f,   0.0f,   0.0f,   1.0f );
	(*this) *= out;
	return *this;
}

inline VMatrix& VMatrix::Scale( const float src )
{
	VMatrix out;
	out.SetMatrix(  src, 0.0f, 0.0f, 0.0f,
		0.0f,  src, 0.0f, 0.0f,
		0.0f, 0.0f,  src, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f );
	(*this) *= out;
	return *this;
}

inline VMatrix VMatrix::GetReverse() const
{
	VMatrix out=(*this);
	out.SetMatrix(
		m[1][1]*m[2][2]*m[3][3] +
		m[1][2]*m[2][3]*m[3][1] +
		m[1][3]*m[2][1]*m[3][2] -
		m[1][1]*m[2][3]*m[3][2] -
		m[1][2]*m[2][1]*m[3][3] -
		m[1][3]*m[2][2]*m[3][1],
		
		m[0][1]*m[2][3]*m[3][2] +
		m[0][2]*m[2][1]*m[3][3] +
		m[0][3]*m[2][2]*m[3][1] -
		m[0][1]*m[2][2]*m[3][3] -
		m[0][2]*m[2][3]*m[3][1] -
		m[0][3]*m[2][1]*m[3][2],
		
		m[0][1]*m[1][2]*m[3][3]+
		m[0][2]*m[1][3]*m[3][1]+
		m[0][3]*m[1][1]*m[3][2]-
		m[0][1]*m[1][3]*m[3][2]-
		m[0][2]*m[1][1]*m[3][3]-
		m[0][3]*m[1][2]*m[3][1],
		
		m[0][1]*m[1][3]*m[2][2]+
		m[0][2]*m[1][1]*m[2][3]+
		m[0][3]*m[1][2]*m[2][1]-
		m[0][1]*m[1][2]*m[2][3]-
		m[0][2]*m[1][3]*m[2][1]-
		m[0][3]*m[1][1]*m[2][2],
		
		m[1][0]*m[2][3]*m[3][2]+
		m[1][2]*m[2][0]*m[3][3]+
		m[1][3]*m[2][2]*m[3][0]-
		m[1][0]*m[2][2]*m[3][3]-
		m[1][2]*m[2][3]*m[3][0]-
		m[1][3]*m[2][0]*m[3][2],
		
		m[0][0]*m[2][2]*m[3][3]+
		m[0][2]*m[2][3]*m[3][0]+
		m[0][3]*m[2][0]*m[3][2]-
		m[0][0]*m[2][3]*m[3][2]-
		m[0][2]*m[2][0]*m[3][3]-
		m[0][3]*m[2][2]*m[3][0],
		
		m[0][0]*m[1][3]*m[3][2]+
		m[0][2]*m[1][0]*m[3][3]+
		m[0][3]*m[1][2]*m[3][0]-
		m[0][0]*m[1][2]*m[3][3]-
		m[0][2]*m[1][3]*m[3][0]-
		m[0][3]*m[1][0]*m[3][2],
		
		m[0][0]*m[1][2]*m[2][3]+
		m[0][2]*m[1][3]*m[2][0]+
		m[0][3]*m[1][0]*m[2][2]-
		m[0][0]*m[1][3]*m[2][2]-
		m[0][2]*m[1][0]*m[2][3]-
		m[0][3]*m[1][2]*m[2][0],
		
		m[1][0]*m[2][1]*m[3][3]+
		m[1][1]*m[2][3]*m[3][0]+
		m[1][3]*m[2][0]*m[3][1]-
		m[1][0]*m[2][3]*m[3][1]-
		m[1][1]*m[2][0]*m[3][3]-
		m[1][3]*m[2][1]*m[3][0],
		
		m[0][0]*m[2][3]*m[3][1]+
		m[0][1]*m[2][0]*m[3][3]+
		m[0][3]*m[2][1]*m[3][0]-
		m[0][0]*m[2][1]*m[3][3]-
		m[0][1]*m[2][3]*m[3][0]-
		m[0][3]*m[2][0]*m[3][1],
		
		m[0][0]*m[1][1]*m[3][3]+
		m[0][1]*m[1][3]*m[3][0]+
		m[0][3]*m[1][0]*m[3][1]-
		m[0][0]*m[1][3]*m[3][1]-
		m[0][1]*m[1][0]*m[3][3]-
		m[0][3]*m[1][1]*m[3][0],
		
		m[0][0]*m[1][3]*m[2][1]+
		m[0][1]*m[1][0]*m[2][3]+
		m[0][3]*m[1][1]*m[2][0]-
		m[0][0]*m[1][1]*m[2][3]-
		m[0][1]*m[1][3]*m[2][0]-
		m[0][3]*m[1][0]*m[2][1],
		
		m[1][0]*m[2][2]*m[3][1]+
		m[1][1]*m[2][0]*m[3][2]+
		m[1][2]*m[2][1]*m[3][0]-
		m[1][0]*m[2][1]*m[3][2]-
		m[1][1]*m[2][2]*m[3][0]-
		m[1][2]*m[2][0]*m[3][1],
		
		m[0][0]*m[2][1]*m[3][2]+
		m[0][1]*m[2][2]*m[3][0]+
		m[0][2]*m[2][0]*m[3][1]-
		m[0][0]*m[2][2]*m[3][1]-
		m[0][1]*m[2][0]*m[3][2]-
		m[0][2]*m[2][1]*m[3][0],
		
		m[0][0]*m[1][2]*m[3][1]+
		m[0][1]*m[1][0]*m[3][2]+
		m[0][2]*m[1][1]*m[3][0]-
		m[0][0]*m[1][1]*m[3][2]-
		m[0][1]*m[1][2]*m[3][0]-
		m[0][2]*m[1][0]*m[3][1],
		
		m[0][0]*m[1][1]*m[2][2]+
		m[0][1]*m[1][2]*m[2][0]+
		m[0][2]*m[1][0]*m[2][1]-
		m[0][0]*m[1][2]*m[2][1]-
		m[0][1]*m[1][0]*m[2][2]-
		m[0][2]*m[1][1]*m[2][0] );
	return out;
}

inline Vector VMatrix::GetVertex( const Vector& src )
{
	Vector out;
	out.vector[0] = (m[0][0]*src.vector[0]) + (m[0][1]*src.vector[1]) + (m[0][2]*src.vector[2]) + m[0][3];
	out.vector[1] = (m[1][0]*src.vector[0]) + (m[1][1]*src.vector[1]) + (m[1][2]*src.vector[2]) + m[1][3];
	out.vector[2] = (m[2][0]*src.vector[0]) + (m[2][1]*src.vector[1]) + (m[2][2]*src.vector[2]) + m[2][3];
	return out;
}

//   http://www.naukowiec.org/wzory/matematyka/macierz-odwrotna-4x4_628.html
inline Vector GetVertexBack( const Vector& src )
{
	return ((*this).GetReverse()).GetVertex( src );
}

#endif

