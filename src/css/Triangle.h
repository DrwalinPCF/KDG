
#pragma once

class Triangle
{
private:
	
	Vector a, b, c;
	Vector normal;
	
	Vector abNormal, bcNormal, acNormal;
	
	float det;
	
public:
	
	inline AABB GetAABB() const;
	inline Vector GetNormal() const;
	
	void Move( const Vector src );
	void Rotate( const Vector origin, const Vector rotator );
	void Scale( const Vector origin, const Vector scale );
	
	inline Vector GetClosestPoint( const Vector p ) const;
	inline bool IsPointIn( const Vector p ) const;
	inline bool GetCrossPoint( const Vector p1, const Vector p2, Vector * dst );
	
	inline void Set( const Vector A, const Vector B, const Vector C, const Vector normal );
	
	Triangle();
	~Triangle();
};



