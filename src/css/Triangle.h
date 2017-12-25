
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "..\Includer.h"

class Triangle
{
private:
	
	Vector pointA;
	Vector pointB;
	Vector pointC;
	
public:
	
	inline bool operator == ( const Triangle& other ) const;
	inline bool operator != ( const Triangle& other ) const;
	
	inline bool IsTotalOutsideBox( const AABB& box ) const;
	
	inline Vector GetClosestPoint( const Vector& point ) const;
	
	inline bool IsPointInside( const Vector& point ) const;		// if point is inside, then point is in the volume of infinite length which perpendicular cross section is triangle, volume edges are parall to each other; using unnormalized vectors
	inline bool GetIntersectionWithLine( const Line& line, Vector& intersection ) const;
	inline bool GetIntersectionOfPlaneWithLine( const Vector& begin, const Vector& end, Vector& intersection );		// using unnormalized vectors
	
	inline Vector GetNormal() const;
	inline Vector GetNormalFast() const;
	inline bool IsFrontFacing( const Vector& direction ) const;
	inline float GetArea() const;
	inline void Set( const Vector& a, const Vector& b, const Vector& c );
	inline bool IsOnSameSide( const Vector& p1, const Vector& p2, const Vector& a, const Vector& b ) const;
	
	Triangle();
	Triangle( const Vector& a, const Vector& b, const Vector& c );
	~Triangle();
};

#endif

