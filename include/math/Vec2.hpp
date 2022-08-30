#pragma once

#include <cmath>
#include <functional>

class Vec2
{
public:
	float x;
	float y;

	Vec2() :
		x(0.0f),
		y(0.0f)
	{ }

	// Constructor with values
	explicit Vec2(float p_x, float p_y) :
		x(p_x),
		y(p_y)
	{ }

	template<class X, class Y>
	explicit Vec2(X p_x, Y p_y) :
		x(static_cast<float>(p_x)),
		y(static_cast<float>(p_y))
	{ }

	// Copy constructor
	Vec2(const Vec2& other) :
		x(other.x),
		y(other.y)
	{ }



	// Magnitude/Length of vector
	float magnitude() const
	{
		return static_cast<float>(sqrt((x * x) + (y * y)));
	}

	// Magnitude/Length squared of vector
	float magnitudeSquared() const
	{
		return (x * x) + (y * y);
	}

	// Normalize vector
	void normalize()
	{
		float len = static_cast<float>(sqrt((x * x) + (y * y)));
		
		if (len != 0.)
		{
			x /= len;
			y /= len;
		}
	}

	void lerp(Vec2 target, float alpha)
	{
		const float invAlpha = 1.0f - alpha;
		x = (x * invAlpha) + (target.x * alpha);
		y = (y * invAlpha) + (target.y * alpha);
	}

	// Dot product of 2 vector
	float dot(const Vec2& other)
	{
		return dot(*this, other);
	}

	// Cross product of 2 vector
	float cross(const Vec2& other)
	{
		return cross(*this, other);
	}

	// Euclidean Distance between 2 vectors
	float distance(const Vec2& other)
	{
		return distance(*this, other);
	}

	template <class T>
	T convert(std::function<T(Vec2&)> func)
	{
		func(*this);
	}



	static float dot(const Vec2& _vecA, const Vec2& _vecB);
	static float cross(const Vec2& _vecA, const Vec2& _vecB);
	static float distance(const Vec2& _vecA, const Vec2& _vecB);



	Vec2 operator+(const Vec2& other)
	{
		return Vec2(x + other.x, y + other.y);
	}
	Vec2& operator+=(const Vec2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vec2 operator-(const Vec2& other)
	{
		return Vec2(x - other.x, y - other.y);
	}
	Vec2& operator-=(const Vec2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vec2 operator*(const float _val)
	{
		return Vec2(x * _val, y * _val);
	}
	Vec2& operator*=(const float _val)
	{
		x *= _val;
		y *= _val;
		return *this;
	}
	
	Vec2 operator/(const float _val)
	{
		return Vec2(x / _val, y / _val);
	}
	Vec2& operator/=(const float _val)
	{
		x /= _val;
		y /= _val;
		return *this;
	}

	bool operator==(const Vec2& other)
	{
		return x == other.x && y == other.y;
	}



	static const Vec2 Zero;
	static const Vec2 Unit;
	static const Vec2 Up;
	static const Vec2 Down;
	static const Vec2 Left;
	static const Vec2 Right;
};