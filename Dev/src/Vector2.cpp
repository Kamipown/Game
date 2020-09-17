#include <cmath>
#include <algorithm>

#include "Vector2.hpp"

Vector2::Vector2(void)
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2(const Vector2 &v)
{
	this->x = v.x;
	this->y = v.y;
}

std::ostream& operator<<(std::ostream &os, const Vector2 &v)
{
	os << "[ " << v.x << " ; " << v.y << " ]" ;
	return (os);
}

Vector2 Vector2::operator+(float f) const
{
	return (Vector2 {this->x + f, this->y + f});
}

Vector2 Vector2::operator-(float f) const
{
	return (Vector2 {this->x - f, this->y - f});
}

Vector2 Vector2::operator*(float f) const
{
	return (Vector2 {this->x * f, this->y * f});
}

Vector2 Vector2::operator/(float f) const
{
	return (Vector2 {this->x / f, this->y / f});
}

Vector2 &Vector2::operator+=(float f)
{
	this->x += f;
	this->y += f;
	return (*this);
}

Vector2 &Vector2::operator-=(float f)
{
	this->x -= f;
	this->y -= f;
	return (*this);
}

Vector2 &Vector2::operator*=(float f)
{
	this->x *= f;
	this->y *= f;
	return (*this);
}

Vector2 &Vector2::operator/=(float f)
{
	this->x /= f;
	this->y /= f;
	return (*this);
}

Vector2 Vector2::operator+(const Vector2 &v) const
{
	return (Vector2 {this->x + v.x, this->y + v.y});
}

Vector2 Vector2::operator-(const Vector2 &v) const
{
	return (Vector2 {this->x - v.x, this->y - v.y});
}

Vector2 Vector2::operator*(const Vector2 &v) const
{
	return (Vector2 {this->x * v.x, this->y * v.y});
}

Vector2 Vector2::operator/(const Vector2 &v) const
{
	return (Vector2 {this->x / v.x, this->y / v.y});
}

Vector2 &Vector2::operator+=(const Vector2 &v)
{
	this->x += v.x;
	this->y += v.y;
	return (*this);
}

Vector2 &Vector2::operator-=(const Vector2 &v)
{
	this->x -= v.x;
	this->y -= v.y;
	return (*this);
}

Vector2 &Vector2::operator*=(const Vector2 &v)
{
	this->x *= v.x;
	this->y *= v.y;
	return (*this);
}

Vector2 &Vector2::operator/=(const Vector2 &v)
{
	this->x /= v.x;
	this->y /= v.y;
	return (*this);
}

bool Vector2::operator==(const Vector2 &v) const
{
	return (this->x == v.x && this->y == v.y);
}

bool Vector2::operator!=(const Vector2 &v) const
{
	return (this->x != v.x || this->y != v.y);
}

// Shorthand for Vector2(0, 1).
Vector2 Vector2::up(void)
{
	return (Vector2 {0, 1});
}

// Shorthand for Vector2(1, 0).
Vector2 Vector2::right(void)
{
	return (Vector2 {1, 0});
}
// Shorthand for Vector2(0, -1).
Vector2 Vector2::down(void)
{
	return (Vector2 {0, -1});
}

// Shorthand for Vector2(-1, 0).
Vector2 Vector2::left(void)
{
	return (Vector2 {-1, 0});
}

// Shorthand for Vector2(1, 1).
Vector2 Vector2::one(void)
{
	return (Vector2 {1, 1});
}

// Shorthand for Vector2(0, 0).
Vector2 Vector2::zero(void)
{
	return (Vector2 {});
}

// Returns the square magnitude of the vector.
float Vector2::sqr_magnitude(const Vector2 &v)
{
	return (v.x * v.x + v.y * v.y);
}

// Returns the magnitude of the vector.
float Vector2::magnitude(const Vector2 &v)
{
	return (std::sqrt(Vector2::sqr_magnitude(v)));
}

// Returns the distance between two vectors.
float Vector2::distance(const Vector2 &v1, const Vector2 &v2)
{
	return (Vector2::magnitude(v1 - v2));
}

// Returns the square distance between two vectors.
float Vector2::sqr_distance(const Vector2 &v1, const Vector2 &v2)
{
	return (Vector2::sqr_magnitude(v1 - v2));
}

// Returns the vector with a magnitude of 1.
Vector2 Vector2::normalize(const Vector2 &v)
{
	return (v / Vector2::magnitude(v));
}

// Linearly interpolates between v1 and v2 by t.
// - The parameter t is clamped to the range [0, 1].
Vector2 Vector2::lerp(const Vector2 &v1, const Vector2 &v2, float t)
{
	return (v1 + (v2 - v1) * std::clamp(t, 0.f, 1.f));
}

// Linearly interpolates between v1 and v2 by t.
Vector2 Vector2::lerp_unclamped(const Vector2 &v1, const Vector2 &v2, float t)
{
	return (v1 + (v2 - v1) * t);
}
