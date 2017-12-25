
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../css/Triangle.h"

inline Triangle Triangle::GetRotated( const Quat& rotation ) const
{
	return Triangle( rotation*pointA, rotation*pointB, rotation*pointC );
}

inline Triangle Triangle::GetMoved( const Vector& possition ) const
{
	return Triangle( possition+pointA, possition+pointB, possition+pointC );
}

inline Triangle Triangle::GetTranslated( const Vector& possition, const Quat& rotation ) const
{
	return Triangle( possition+rotation*pointA, possition+rotation*pointB, possition+rotation*pointC );
}

inline bool Triangle::operator == ( const Triangle& other ) const
{
	return (pointA==other.pointA) && (pointB==other.pointB) && (pointC==other.pointC);
}

inline bool Triangle::operator != ( const Triangle& other ) const
{
	return (pointA!=other.pointA) || (pointB!=other.pointB) || (pointC!=other.pointC);
}

inline bool Triangle::IsTotalOutsideBox( const AABB& box ) const
{
	if( pointA[0] > box.GetMax()[0] && pointB[0] > box.GetMax()[0] && pointC[0] > box.GetMax()[0] )	return true;
	if( pointA[1] > box.GetMax()[1] && pointB[1] > box.GetMax()[1] && pointC[1] > box.GetMax()[1] ) return true;
	if( pointA[2] > box.GetMax()[2] && pointB[2] > box.GetMax()[2] && pointC[2] > box.GetMax()[2] ) return true;
	if( pointA[0] < box.GetMin()[0] && pointB[0] < box.GetMin()[0] && pointC[0] < box.GetMin()[0] ) return true;
	if( pointA[1] < box.GetMin()[1] && pointB[1] < box.GetMin()[1] && pointC[1] < box.GetMin()[1] ) return true;
	if( pointA[2] < box.GetMin()[2] && pointB[2] < box.GetMin()[2] && pointC[2] < box.GetMin()[2] ) return true;
	return false;
	/*
	return ((pointA[0] > box.GetMax()[0] && pointB[0] > box.GetMax()[0] && pointC[0] > box.GetMax()[0]) ||
			(pointA[1] > box.GetMax()[1] && pointB[1] > box.GetMax()[1] && pointC[1] > box.GetMax()[1]) ||
			(pointA[2] > box.GetMax()[2] && pointB[2] > box.GetMax()[2] && pointC[2] > box.GetMax()[2]) ||
			(pointA[0] < box.GetMin()[0] && pointB[0] < box.GetMin()[0] && pointC[0] < box.GetMin()[0]) ||
			(pointA[1] < box.GetMin()[1] && pointB[1] < box.GetMin()[1] && pointC[1] < box.GetMin()[1]) ||
			(pointA[2] < box.GetMin()[2] && pointB[2] < box.GetMin()[2] && pointC[2] < box.GetMin()[2]));
	*/
}

inline Vector Triangle::GetClosestPoint( const Vector& point ) const
{
	Vector ab = vertex[1] - vertex[0];
	Vector ac = vertex[2] - vertex[0];
	Vector ap = p - vertex[0];
	float d1 = ab.Dot(ap);
	float d2 = ac.Dot(ap);
	if (d1 <= 0.0f && d2 <= 0.0f)
		return vertex[0];
	
	Vector bp = p - vertex[1];
	float d3 = ab.Dot(bp);
	float d4 = ac.Dot(bp);
	if (d3 >= 0.0f && d4 <= d3)
		return vertex[1];
	
	float vc = (d1*d4) - (d3*d2);
	if( vc <= 0.0f && d1 >= 0.0f && d3 <= 0.0f )
	{
		float v = d1 / (d1 - d3);
		return vertex[0] + (v * ab);
	}
	
	Vector cp = p - vertex[2];
	float d5 = ab.Dot(cp);
	float d6 = ac.Dot(cp);
	if (d6 >= 0.0f && d5 <= d6)
		return vertex[2];
	float vb = (d5*d2) - (d1*d6);
	if( vb <= 0.0f && d2 >= 0.0f && d6 <= 0.0f )
	{
		float w = d2 / (d2 - d6);
		return vertex[0] + (ac * w);
	}
	float va =( d3*d6) - (d5*d4);
	if( va <= 0.0f && (d4 - d3) >= 0.0f && (d5 - d6) >= 0.0f )
	{
		float w = (d4 - d3) / ((d4 - d3) + (d5 - d6));
		return vertex[1] + ((vertex[2] - vertex[1]) * w);
	}
	float denom = 1.0f / (va + vb + vc);
	float v = vb * denom;
	float w = vc * denom;
	return vertex[0] + (ab * v) + (ac * w);
}

inline bool Triangle::IsPointInside( const Vector& point ) const
{
	Vector ab = pointB - pointA;
	Vector ac = pointA - pointC;
	Vector cb = pointC - pointB;
	
	Vector _ab = normal && ab;
	Vector _ac = normal && ac;
	Vector _cb = normal && cb;
	
	if( _ab.Dot( p - pointA ) * _ab.Dot( cb ) >= 0.0f )
		if( _ac.Dot( p - pointA ) * _ac.Dot( ab ) >= 0.0f )
			if( _cb.Dot( p - pointC ) * _cb.Dot( ac ) >= 0.0f )
				return true;
	return false;
	
	/*
	Vector p_ = p - pointA;
	float x = ( pointB - pointA ).Dot( p_ );
	float y = ( pointC - pointA ).Dot( p_ );
	float z = ( pointC - pointB ).Dot( p - pointB );
	
	if( x + y < 1.000001f )
		if( y + z > 1.000001f )
			if( z - x < 0.000001f )
				return true;
	return false;
	*/
	
	/*
	if( ( pointB - pointA ).Dot( p - pointA ) + ( pointC - pointA ).Dot( p - pointA ) < 1.000001f )
		if( ( pointA - pointB ).Dot( p - pointB ) + ( pointC - pointB ).Dot( p - pointB ) < 1.000001f )
			if( ( pointA - pointC ).Dot( p - pointC ) + ( pointB - pointC ).Dot( p - pointC ) < 1.000001f )
				return true;
	return false;
	*/
	
	/*
	Vector p = point - pointA;
	float x = ( pointB - pointA ).Dot( p );
	float y = ( pointC - pointA ).Dot( p );
	
	if( x > -0.000001f )
		if( y > -0.000001f )
			return y + x < 1.000001f;
	return false;
	*/
	
	/*
	const Vector a = pointC - pointA;
	const Vector b = pointB - pointA;
	const Vector c = point - pointA;

	const float dotAA = a.Dot( a );
	const float dotAB = a.Dot( b );
	const float dotAC = a.Dot( c );
	const float dotBB = b.Dot( b );
	const float dotBC = b.Dot( c );

	const float invDenom =  1/(dotAA * dotBB - dotAB * dotAB);
	const float u = (dotBB * dotAC - dotAB * dotBC) * invDenom;
	const float v = (dotAA * dotBC - dotAB * dotAC ) * invDenom;

	return (u > -ROUNDING_ERROR) && (v >= 0) && (u + v < 1+ROUNDING_ERROR);
	*/
}

inline bool Triangle::GetIntersectionWithLine( const Vector& begin, const Vector& end, Vector& intersection ) const
{
	if( GetIntersectionOfPlaneWithLine( begin, end, intersection ) )
		return IsPointInside( intersection );
	return false;
}

inline bool Triangle::GetIntersectionOfPlaneWithLine( const Vector& begin, const Vector& end, Vector& intersection )
{
	Vector normal = GetNormal();
	Vector direction = end - begin;
	float dot = normal.Dot( direction );
	
	if( dot == 0.0f )
		return false;
	
	float t = normal.Dot( pointA - begin ) / ( dot );
	
	if( t < 0.0f || t > 1.0f )
		return false;
	
	intersection = begin + ( direction * t );
	return true;
}

inline Vector Triangle::GetNormal() const
{
	return (pointB-pointA) && (pointC-pointA).Versor();
}

inline Vector Triangle::GetNormalFast() const
{
	return (pointB-pointA) && (pointC-pointA);
}

inline bool Triangle::IsFrontFacing( const Vector& direction ) const
{
	return GetNormalFast().Dot( direction ) <= 0.0f;
}

inline float Triangle::GetArea() const
{
	return ( (pointB - pointA) && (pointC - pointA).GetLength() ) * 0.5f;
}

inline void Triangle::Set( const Vector& a, const Vector& b, const Vector& c )
{
	pointA = a;
	pointB = b;
	pointC = c;
}

inline bool Triangle::IsOnSameSide( const Vector& p1, const Vector& p2, const Vector& a, const Vector& b ) const
{
	Vector bminusa = b - a;
	Vector cp1 = bminusa && (p1-a);
	Vector cp2 = bminusa && (p2-a);
	float res = cp1 && cp2;
	if( res < 0.0f )
	{
		cp1 = bminusa.Versor() && ((p1-a).Versor());
		if( cp1[0] > -ROUNDING_ERROR && cp1[0] < ROUNDING_ERROR && cp1[0] > -ROUNDING_ERROR && cp1[0] < ROUNDING_ERROR && cp1[0] > -ROUNDING_ERROR && cp1[0] < ROUNDING_ERROR )
			return true;
		return false;
	}
	return true;
}

Triangle::Triangle()
{
	pointA.Set( 0.0f, 0.0f, 0.0f );
	pointC = pointB = pointA;
}

Triangle::Triangle( const Vector& a, const Vector& b, const Vector& c )
{
	pointA = a;
	pointB = b;
	pointC = c;
}

Triangle::~Triangle()
{
	pointA.Set( 0.0f, 0.0f, 0.0f );
	pointC = pointB = pointA;
}

#endif

