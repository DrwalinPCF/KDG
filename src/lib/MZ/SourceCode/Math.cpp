/*
	Copyright (C) 2017 Marek Zalewski
	
	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.
	
	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1.	The origin of this software must not be misrepresented; you must not
		claim that you wrote the original software. If you use this software
		in a product, an acknowledgment in the product documentation is required.
	2.	Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.
	3.	This notice may not be removed or altered from any source distribution.
*/

#ifndef MATH_CPP
#define MATH_CPP

#include "../SourceHeader/Math.h"

namespace Math
{
	inline float Min( const float a, const float b )
	{
		return ( a < b ) ? a : b;
	}
	
	inline float Max( const float a, const float b )
	{
		return ( a > b ) ? a : b;
	}
	
	inline Vector Min( const Vector& a, const Vector& b )
	{
		return Vector( Math::Min(a[0],b[0]), Math::Min(a[1],b[1]), Math::Min(a[2],b[2]) );
	}
	
	inline Vector Max( const Vector& a, const Vector& b )
	{
		return Vector( Math::Max(a[0],b[0]), Math::Max(a[1],b[1]), Math::Max(a[2],b[2]) );
	}
	
	inline float Abs( const float a )
	{
		return ( a < 0.0f ) ? -a : a;
	}
	
	inline unsigned long long int Log( const unsigned long long int base, const unsigned long long int a )
	{
		unsigned long long int val = a, dst = 0;
		
		while( val )
		{
			val /= base;
			++dst;
		}
		return dst;
	}
	
	inline float Log( const float base, const float a )
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
	
	inline float Interpolate( const float a, const float b, const float t )
	{
		float mult = cos(t*Math::pi*0.5f);
		return ( a * mult ) + ( b * ( 1.0f - mult ) );
	}
	
	inline Vector Interpolate( const Vector& a, const Vector& b, const float t )
	{
		float mult = cos(t*Math::pi*0.5f);
		return ( a * mult ) + ( b * ( 1.0f - mult ) );
	}
	
	inline Vecotr GetForwardVector( const Vector& rotator )
	{
		return Quat( rotator ) * Vector( 0.0f, 0.0f, 1.0f );
	}
	
	inline Vecotr GetLeftVector( const Vector& rotator )
	{
		return Quat( rotator ) * Vector( 1.0f, 0.0f, 0.0f );
	}
	
	inline Vecotr GetUpVector( const Vector& rotator )
	{
		return Quat( rotator ) * Vector( 0.0f, 1.0f, 0.0f );
	}
	
	inline float Clamp( const float a, const float min, const float max )
	{
		return ( a < min ) ? min : ( ( a > max ) ? max : a );
	}
	
	inline float Sqrt( const float a )
	{
		return sqrt( a );
	}
};

#endif

