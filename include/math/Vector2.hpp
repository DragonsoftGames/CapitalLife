#pragma once

#include <cmath>

template<class T>
class Vector2
{
public:
	T x;
	T y;

	Vector2() :
		x(static_cast<T>(0)),
		y(static_cast<T>(0))
	{}

	// Constructor with values
	explicit Vector2(T _x, T _y) :
		x(_x),
		y(_y)
	{}

	// Copy constructor
	Vector2(const Vector2<T>& _vec) :
		x(_vec.x),
		y(_vec.y)
	{}

	////////////////////
	// Public Methods //
	////////////////////

	// Magnitude/Length of vector
	T magnitude() const
	{
		return static_cast<T>(sqrt((x * x) + (y * y)));
	}

	// Magnitude/Length squared of vector
	T magnitudeSquared() const
	{
		return static_cast<T>((x * x) + (y * y));
	}

	// Normalize vector
	void normalize()
	{
		T len = static_cast<T>(sqrt((x * x) + (y * y)));
		
		if (len != 0.)
		{
			x = static_cast<T>(x/len);
			y = static_cast<T>(y/len);
		}
	}

	template<class X>
	void lerp(Vector2<X> target, float alpha)
	{
		const float invAlpha = 1.0f - alpha;
		x = (x * invAlpha) + (static_cast<T>(target.x) * alpha);
		y = (y * invAlpha) + (static_cast<T>(target.y) * alpha);
	}

	// Dot product of 2 vector
	T dot(const Vector2<T>& _vec)
	{
		return dot(*this, _vec);
	}

	// Cross product of 2 vector
	T cross(const Vector2<T>& _vec)
	{
		return cross(*this, _vec);
	}

	// Euclidean Distance between 2 vectors
	T distance(const Vector2<T>& _vec)
	{
		return distance(*this, _vec);
	}

	// Angle between 2 vectors
	double angle(const Vector2<T>& _vec)
	{
		return angle(*this, _vec);
	}

	//////////////////////
	// Static functions //
	//////////////////////

	static bool compareFD(const T &a, const T &b);
	static T dot(const Vector2<T>& _vecA, const Vector2<T>& _vecB);
	static T cross(const Vector2<T>& _vecA, const Vector2<T>& _vecB);
	static T distance(const Vector2<T>& _vecA, const Vector2<T>& _vecB);
	static double angle(const Vector2<T>& _vecA, const Vector2<T>& _vecB);

	////////////////////////
	// Operator functions //
	////////////////////////

	Vector2<T> operator+(const Vector2<T>& other)
	{
		return Vector2<T>(x + other.x, y + other.y);
	}
	Vector2<T>& operator+=(const Vector2<T>& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2<T> operator-(const Vector2<T>& other)
	{
		return Vector2<T>(x - other.x, y - other.y);
	}
	Vector2<T>& operator-=(const Vector2<T>& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2<T> operator*(const T _val)
	{
		return Vector2<T>(x * _val, y * _val);
	}
	Vector2<T>& operator*=(const T _val)
	{
		x *= _val;
		y *= _val;
		return *this;
	}
	
	Vector2<T> operator/(const T _val)
	{
		return Vector2<T>(x / _val, y / _val);
	}
	Vector2<T>& operator/=(const T _val)
	{
		x /= _val;
		y /= _val;
		return *this;
	}

	/////////////////////
	// Default Vectors //
	/////////////////////

	static const Vector2<T> Zero;
	static const Vector2<T> Unit;
	static const Vector2<T> Up;
	static const Vector2<T> Down;
	static const Vector2<T> Left;
	static const Vector2<T> Right;
};

template<class T>
bool Vector2<T>::compareFD(const T &a, const T &b)
{
	return (std::fabs(a - b) < static_cast<T>(0.005));
}

template<class T>
const Vector2<T> Vector2<T>::Zero(static_cast<T>(0), static_cast<T>(0));

template<class T>
const Vector2<T> Vector2<T>::Unit(static_cast<T>(1), static_cast<T>(1));

template<class T>
const Vector2<T> Vector2<T>::Up(static_cast<T>(0), static_cast<T>(1));

template<class T>
const Vector2<T> Vector2<T>::Down(static_cast<T>(0), static_cast<T>(-1));

template<class T>
const Vector2<T> Vector2<T>::Left(static_cast<T>(-1), static_cast<T>(0));

template<class T>
const Vector2<T> Vector2<T>::Right(static_cast<T>(1), static_cast<T>(0));

template<class T>
T Vector2<T>::dot(const Vector2<T>& _vecA, const Vector2<T>& _vecB)
{
	return (_vecA.x * _vecB.x + _vecA.y * _vecB.y);
}

template<class T>
T Vector2<T>::cross(const Vector2<T>& _vecA, const Vector2<T>& _vecB)
{
	return (_vecA.x * _vecB.y - _vecA.y * _vecB.x);
}

template<class T>
T Vector2<T>::distance(const Vector2<T>& _vecA, const Vector2<T>& _vecB)
{
	return static_cast<T>(sqrt(
		((_vecA.x - _vecB.x)*(_vecA.x - _vecB.x)) + 
		((_vecA.y - _vecB.y)*(_vecA.y - _vecB.y))
	));
}

// TODO: Update/Refactor to optimize
template<class T>
double Vector2<T>::angle(const Vector2<T>& _vecA, const Vector2<T>& _vecB)
{
	Vector2<double> t_vecA(static_cast<double>(_vecA.x), static_cast<double>(_vecA.y));
	Vector2<double> t_vecB(static_cast<double>(_vecB.x), static_cast<double>(_vecB.y));
	return (acos(Vector2<double>::dot(t_vecA, t_vecB) / (t_vecA.magnitude() * t_vecB.magnitude())));
}

using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;