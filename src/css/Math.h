
#pragma once

class Math
{
public:
	
	static const float pi = 3.14159265359f;
	static float Min( const float a, const float b );
	static float Max( const float a, const float b );
	static Vector Min( const Vector a, const Vector b );
	static Vector Max( const Vector a, const Vector b );
	static float Abs( const float a );
	static unsigned long long int Log( const unsigned long long int base, const unsigned long long int a );
	static float Log( const float base, const float a );							// returns not the best approximation: abs(log(base,a) - Math::Log(base,a)) <~ 0.2
	static float Interpolate( const float a, const float b, const float t );		// 0 <= t <= 1, sin
	static Vector Interpolate( const Vector a, const Vector b, const float t );		// 0 <= t <= 1, sin
	static Quat GetQaternion( const Vector rotator );
	static Vecotr GetForwardVector( const Vector rotator );
	static Vecotr GetLeftVector( const Vector rotator );
	static Vecotr GetUpVector( const Vector rotator );
	static float Clamp( const float a, const float min, const float max );
};



