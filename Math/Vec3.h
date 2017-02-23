#pragma once
#include <math.h>

class Vec3
{
public:
	inline Vec3(float v) : x(v), y(v), z(v)
	{
	}

	inline Vec3(float x, float y, float z) : x(x), y(y), z(z)
	{
	}

	inline friend Vec3 operator+(const Vec3&  lhs, const Vec3&  rhs)
	{
		return Vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	}

	inline friend Vec3 operator-(const Vec3&  lhs, const Vec3&  rhs)
	{
		return Vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	}

	inline friend Vec3 operator*(const Vec3&  lhs, const Vec3& rhs)
	{
		return Vec3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
	}

	inline friend Vec3 operator*(const Vec3&  lhs, float rhs)
	{
		return Vec3(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs);
	}

	inline Vec3& operator=(const Vec3&  rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return *this;
	}

	inline Vec3& operator+=(const Vec3&  rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	inline Vec3& operator-=(const Vec3&  rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	inline Vec3& operator*=(float rhs)
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;
		return *this;
	}

	inline Vec3& operator*=(Vec3& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}

	inline friend float dot(const Vec3&  lhs, const Vec3&  rhs)
	{
		return ((lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z));
	}

    inline friend Vec3 cross(const Vec3&  lhs, const Vec3&  rhs)
    {
        return Vec3((lhs.y*rhs.z - lhs.z*rhs.y), (lhs.z*rhs.x - lhs.x*rhs.z), (lhs.x*rhs.y - lhs.y*rhs.x));
    }

	inline float lengthSquared(void)
	{
		return (x*x + y*y + z*z);
	}

	inline Vec3 around_X_axis(const float angle) const
	{
		return Vec3(x,
			y * cos(angle) - z * sin(angle),
			y * sin(angle) + z * cos(angle));
	}

	inline Vec3 around_Y_axis(const float angle) const
	{
		return Vec3(x * cos(angle) + z * sin(angle),
			y,
			-x * sin(angle) + z * cos(angle));
	}

	inline Vec3 around_Z_axis(const float angle) const
	{
		return Vec3(x * cos(angle) - y * sin(angle),
			x * sin(angle) + y * cos(angle),
			z);
	}
	float x;
	float y;
	float z;
};