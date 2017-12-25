
#ifndef QUAT_H
#define QUAT_H

#include "../Includer.h"

struct Quat
{
private:
	
	float x, y, z, w;
	
public:
	
	inline float& operator[]( const int id );
	
	inline Quat & operator = ( const Quat& src );
	inline Quat operator * ( const Quat& src ) const;
	inline Quat& operator *= ( const Quat& src ) const;
	inline Vector operator * ( const Vector& src ) const;
	inline Quat operator - () const;
	
	inline Vector GetAxis() const;
	inline float GetAngle() const;
	inline float Length() const;
	inline Quat Normalized() const;
	inline Quat& Normalize();
	
	inline Quat Inversed() const;
	inline Quat& Inverse();
	inline bool IsOpposite( const Quat& src );
	
	inline Quat Slerp( const Quat& dst, const float time );
	inline void ClampAngle( const float maxAngle );
	inline void SetAngle( const float angle );
	
	Quat( const Quat& src_a, const Quat& src_b );
	Quat( const Vector& axis, const float angle );
	Quat();
	Quat( const float a, const float b, const float c, const float d );
};

#endif

