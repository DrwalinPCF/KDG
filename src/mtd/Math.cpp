
#pragma once

float Math::Min( const float a, const float b )
{
	return ( a < b ) ? a : b;
}

float Math::Max( const float a, const float b )
{
	return ( a > b ) ? a : b;
}

Vector Math::Min( const Vector a, const Vector b )
{
	return Vector( Math::Min(a[0],b[0]), Math::Min(a[1],b[1]), Math::Min(a[2],b[2]) );
}

Vector Math::Max( const Vector a, const Vector b )
{
	return Vector( Math::Max(a[0],b[0]), Math::Max(a[1],b[1]), Math::Max(a[2],b[2]) );
}

float Math::Abs( const float a )
{
	return ( a < 0.0f ) ? -a : a;
}

unsigned long long int Math::Log( const unsigned long long int base, const unsigned long long int a )
{
	unsigned long long int val = a, dst = 0;
	
	while( val )
	{
		val /= base;
		++dst;
	}
	return dst;
}

static float Math::Log( const float base, const float a )
{
	if( base <= 0.0f )
		return 0.0f;
	if( a <= 0.0f )
		return 0.0f;
	float val = a, dst = 0.0f;;
	while( val > base )
	{
		val /= base;
		dst += 1.0f
	}
	val /= base;
	return dst + pow( val, val );
}

static float Math::Interpolate( const float a, const float b, const float t )
{
	float mult = cos(t*Math::pi*0.5f);
	return ( a * mult ) + ( b * ( 1.0f - mult ) );
}

static Vector Math::Interpolate( const Vector a, const Vector b, const float t )
{
	float mult = cos(t*Math::pi*0.5f);
	return ( a * mult ) + ( b * ( 1.0f - mult ) );
}

static Quat Math::GetQaternion( const Vector rotator )
{
	return rot( Vector( 1.0f, 0.0f, 0.0f ), rotation[0] ) * Quat( Vector( 0.0f, 1.0f, 0.0f ), rotation[1] ) * Quat( Vector( 0.0f, 0.0f, 1.0f ), rotation[2] );
}

static Vecotr Math::GetForwardVector( const Vector rotator )
{
	return GetQaternion( rotator ) * Vector( 0.0f, 0.0f, 1.0f );
}

static Vecotr Math::GetLeftVector( const Vector rotator )
{
	return GetQaternion( rotator ) * Vector( 1.0f, 0.0f, 0.0f );
}

static Vecotr Math::GetUpVector( const Vector rotator )
{
	return GetQaternion( rotator ) * Vector( 0.0f, 1.0f, 0.0f );
}

static float Math::Clamp( const float a, const float min, const float max )
{
	return ( a < min ) ? min : ( ( a > max ) ? max : a );
}



