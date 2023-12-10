#include "Vector2D.h"

Vector2D::Vector2D():
    x(0.0f),
    y(0.0f)
{
}

Vector2D::Vector2D(float x, float y) : x(x), y(y)
{

}

Vector2D& Vector2D::operator+(const Vector2D& other)
{
    x += other.x;
    y += other.y;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector2D& vector)
{
    os << "(" << vector.x << "," << vector.y << ")";
         
    return os;
}
