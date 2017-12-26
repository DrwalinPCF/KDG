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
		in a product, an acknowledgment is required.
	2.	Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.
	3.	This notice may not be removed or altered from any source distribution.
*/

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



