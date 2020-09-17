#pragma once

#include <iostream>

struct Vector2
{
	float x;
	float y;

	Vector2(void);
	Vector2(float x, float y);
	Vector2(const Vector2 &v);
	
	friend std::ostream& operator<<(std::ostream &os, const Vector2 &v);
	
	Vector2 operator+(float f) const;
	Vector2 operator-(float f) const;
	Vector2 operator*(float f) const;
	Vector2 operator/(float f) const;
	
	Vector2 &operator+=(float f);
	Vector2 &operator-=(float f);
	Vector2 &operator*=(float f);
	Vector2 &operator/=(float f);

	Vector2 operator+(const Vector2 &v) const;
	Vector2 operator-(const Vector2 &v) const;
	Vector2 operator*(const Vector2 &v) const;
	Vector2 operator/(const Vector2 &v) const;

	Vector2 &operator+=(const Vector2 &v);
	Vector2 &operator-=(const Vector2 &v);
	Vector2 &operator*=(const Vector2 &v);
	Vector2 &operator/=(const Vector2 &v);

	bool operator==(const Vector2 &v) const;
	bool operator!=(const Vector2 &v) const;

	static Vector2 up(void);
	static Vector2 right(void);
	static Vector2 down(void);
	static Vector2 left(void);
	static Vector2 one(void);
	static Vector2 zero(void);

	static float sqr_magnitude(const Vector2 &v);
	static float magnitude(const Vector2 &v);

	static float sqr_distance(const Vector2 &v1, const Vector2 &v2);
	static float distance(const Vector2 &v1, const Vector2 &v2);
	
	static Vector2 normalize(const Vector2 &v);

	static Vector2 lerp(const Vector2 &v1, const Vector2 &v2, float t);
	static Vector2 lerp_unclamped(const Vector2 &v1, const Vector2 &v2, float t);
};
