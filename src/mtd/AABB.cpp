
#pragma once

void DrawDebug() const;////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline float GetVolume() const
{
	Vector a = max-min;
	return abs( a[0] * a[1] * a[2] );
}

inline AABB & AABB::operator = ( const AABB src )
{
	min = src.min;
	max = src.max;
	return *this;
}

inline AABB AABB::operator + ( const AABB src ) const
{
	return AABB( Math::Min(min,src.min), Math::Max(max,src.max) );
}

inline AABB AABB::operator + ( const Vector src ) const
{
	return AABB( min+src, max+src );
}

inline AABB AABB::operator - ( const Vector src ) const
{
	return AABB( min-src, max-src );
}

inline bool AABB::IsPointInsie( const Vector p ) const
{
	if( p >= min )
		if( p <= max )
			return true;
	return false;
}

inline bool AABB::SharedPart( const AABB a, const AABB b, AABB & dst )
{
	if( a.max > b.min )
	{
		if( a.min < b.max )
		{
			dst.min = Math::Max( a.min, b.min );
			dst.max = Math::Min( a.max, b.max );
			return true;
		}
	}
	return false;
}

inline bool AABB::SharedPart( const AABB src, AABB & dst ) const
{
	if( max > src.min )
	{
		if( min < src.max )
		{
			dst.min = Math::Max( min, src.min );
			dst.max = Math::Min( max, src.max );
			return true;
		}
	}
	return false;
}

inline Vector AABB::GetMin() const
{
	return min;
}

inline Vector AABB::GetMax() const
{
	return max;
}

inline Vector AABB::GetSize() const
{
	return max-min;
}

inline Vector AABB::GetCenter() const
{
	return (min+max) * 0.5f;
}


inline void AABB::AddPoint( const Vector point )
{
	if( point[0] < min[0] )				min[0] = point[0];
	else if( point[0] > max[0] )		max[0] = point[0];
	if( point[1] < min[1] )				min[1] = point[1];
	else if( point[1] > max[1] )		max[1] = point[1];
	if( point[2] < min[2] )				min[2] = point[2];
	else if( point[2] > max[2] )		max[2] = point[2];
}

inline void AABB::SetMin( const Vector min_ )
{
	min = min_;
}

inline void AABB::SetMax( const Vector max_ )
{
	max = max_;
}

inline void AABB::Set( const Vector min_, const Vector max_ )
{
	min = min_;
	max = max_;
}

AABB::AABB()
{
	min.Set( 0.0f, 0.0f, 0.0f );
	max.Set( 0.0f, 0.0f, 0.0f );
}

AABB::AABB( const Vector min_, const Vector max_ )
{
	min = min_;
	max = max_;
}

AABB::~AABB()
{
	min.Set( 0.0f, 0.0f, 0.0f );
	max.Set( 0.0f, 0.0f, 0.0f );
}



inline AABBint & AABBint::operator = ( const AABBint src )
{
	strcpy( this, &src, sizeof(AABBint) );
	return *this;
}

inline bool AABBint::operator == ( const AABBint src ) const
{
	return memcmp( this, &src, sizeof(AABBint) ) == 0;
}

inline bool AABBint::operator != ( const AABBint src ) const
{
	return memcmp( this, &src, sizeof(AABBint) ) != 0;
}

inline long long int AABBint::GetMinX() const
{
	return min[0];
}

inline long long int AABBint::GetMinY() const
{
	return min[1];
}

inline long long int AABBint::GetMinZ() const
{
	return min[2];
}

inline long long int AABBint::GetMaxX() const
{
	return max[0];
}

inline long long int AABBint::GetMaxY() const
{
	return max[1];
}

inline long long int AABBint::GetMaxZ() const
{
	return max[2];
}


inline void AABBint::SetMinX( const long long int val )
{
	min[0] = val;
}

inline void AABBint::SetMinY( const long long int val )
{
	min[1] = val;
}

inline void AABBint::SetMinZ( const long long int val )
{
	min[2] = val;
}

inline void AABBint::SetMaxX( const long long int val )
{
	max[0] = val;
}

inline void AABBint::SetMaxY( const long long int val )
{
	max[1] = val;
}

inline void AABBint::SetMaxZ( const long long int val )
{
	max[2] = val;
}


AABBint::AABBint( const AABB src, const AABB scale, const long long int size )
{
	Vector scale_ = scale.GetSize();
	scale_ = Vector( ((float)(size))/scale_[0], ((float)(size))/scale_[1], ((float)(size))/scale_[2] );
	AABB temp = src-scale.GetMin();
	temp.Set( temp.GetMin()*scale_ );
	min[0] = src.GetMinX();
	min[1] = src.GetMinY();
	min[2] = src.GetMinZ();
	max[0] = src.GetMaxX();
	max[1] = src.GetMaxY();
	max[2] = src.GetMaxZ();
}

AABBint::AABBint()
{
	memset( min, 0, sizeof(min) );
	memset( max, 0, sizeof(max) );
}

AABBint::~AABBint()
{
	memset( min, 0, sizeof(min) );
	memset( max, 0, sizeof(max) );
}



