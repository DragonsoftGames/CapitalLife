#include "math/Vec2.hpp"

const Vec2 Vec2::Zero(0.0f, 0.0f);
const Vec2 Vec2::Unit(1.0f, 1.0f);
const Vec2 Vec2::Up(0.0f, 1.0f);
const Vec2 Vec2::Down(0.0f, -1.0f);
const Vec2 Vec2::Left(-1.0f, 0.0f);
const Vec2 Vec2::Right(1.0f, 0.0f);

float Vec2::dot(const Vec2& _vecA, const Vec2& _vecB)
{
	return (_vecA.x * _vecB.x + _vecA.y * _vecB.y);
}

float Vec2::cross(const Vec2& _vecA, const Vec2& _vecB)
{
	return (_vecA.x * _vecB.y - _vecA.y * _vecB.x);
}

float Vec2::distance(const Vec2& _vecA, const Vec2& _vecB)
{
	return static_cast<float>(sqrt(
		((_vecA.x - _vecB.x)*(_vecA.x - _vecB.x)) + 
		((_vecA.y - _vecB.y)*(_vecA.y - _vecB.y))
	));
}