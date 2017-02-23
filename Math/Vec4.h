#pragma once

class Vec4
{
public:
	inline Vec4(float v)
	{
	}

	inline Vec4(float x, float y, float z, float w)
	{
	}

	inline friend Vec4 operator+(const Vec4&  lhs, const Vec4&  rhs)
	{
		return Vec4(0);
	}

	inline friend Vec4 operator-(const Vec4&  lhs, const Vec4&  rhs)
	{
		return Vec4(0);
	}

	inline friend Vec4 operator*(const Vec4&  lhs, const Vec4& rhs)
	{
		return Vec4(0);
	}

	inline friend Vec4 operator*(const Vec4&  lhs, float rhs)
	{
		return Vec4(0);
	}

	inline Vec4& operator=(const Vec4&  rhs)
	{
		return *this;
	}

	inline Vec4& operator+=(const Vec4&  rhs)
	{
		return *this;
	}

	inline Vec4& operator-=(const Vec4&  rhs)
	{
		return *this;
	}

	inline Vec4& operator*=(float rhs)
	{
		return *this;
	}

	inline Vec4& operator*=(Vec4& rhs)
	{
		return *this;
	}

	inline friend float dot(const Vec4&  lhs, const Vec4&  rhs)
	{
		return 0;
	}

	inline float lengthSquared(void)
	{
		return 0;
	}

	float x;
	float y;
	float z;
	float w;
};