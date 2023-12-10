#pragma once
#include <iostream>

class Vector2D
{
public:
	Vector2D();
	Vector2D(float x, float y);
	float x;
	float y;

	// todo - implement Vector2 math
	Vector2D& operator+ (const Vector2D& other);

	friend std::ostream& operator<<(std::ostream& os, const Vector2D& vector);
};

