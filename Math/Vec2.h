#pragma once
#include <math.h>

class Vec2
{
public:
	inline Vec2(float v) : x(v), y(v)
	{
	}

	inline Vec2(float x, float y) : x(x), y(y)
	{
	}

	inline friend Vec2 operator+(const Vec2&  lhs, const Vec2&  rhs)
	{
		return Vec2( lhs.x + rhs.x , lhs.y + rhs.y);
	}

	inline friend Vec2 operator-(const Vec2&  lhs, const Vec2&  rhs)
	{
		return Vec2(lhs.x - rhs.x , lhs.y - rhs.y);
	}

	inline friend Vec2 operator*(const Vec2&  lhs, const Vec2& rhs)
	{
		return Vec2(lhs.x * rhs.x, lhs.y * rhs.y);
	}

	inline friend Vec2 operator*(const Vec2&  lhs, float rhs)
	{
		return Vec2(lhs.x * rhs, lhs.y * rhs);
	}

	inline Vec2& operator=(const Vec2&  rhs)
	{
		x = rhs.x;
		y = rhs.y;
		return *this;
	}

	inline Vec2& operator+=(const Vec2&  rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	inline Vec2& operator-=(const Vec2&  rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	inline Vec2& operator*=(float rhs)
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}

	inline Vec2& operator*=(Vec2& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}

	inline friend float dot(const Vec2&  lhs, const Vec2&  rhs)
	{
		return ((lhs.x * rhs.x) + (lhs.y * rhs.y));
	}

	inline float lengthSquared(void)
	{
		return ((x*x) + (y*y));
	}

	inline Vec2 toPolar() const
	{
		return Vec2(sqrt(x*x + y*y), tanf((y / x)));
	}

	inline Vec2 toCartesian() const
	{
		return Vec2(x * cosf(y), x * sinf(y));
	}


	float x;
	float y;
};
