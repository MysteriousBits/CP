#include <bits/stdc++.h>
using namespace std;

bool feq(const long double& a, const long double& b)
{
    long double del = fabsl(a - b);
    if (del <= EPS) return true;

    return del <= EPS * max(fabsl(a), fabsl(b));
}

struct vector2d
{
    long double x, y;

    bool operator==(const vector2d& p) const
    {
        return feq(x, p.x) && feq(y, p.y);
    }

    vector2d operator+(const vector2d& p) const
    {
        return {x + p.x, y + p.y};
    }

    vector2d operator-(const vector2d& p) const
    {
        return {x - p.x, y - p.y};
    }

    vector2d operator*(long double scalar) const
    {
        return {scalar * x, scalar * y};
    }

    friend vector2d operator*(long double s, const vector2d& v)
    {
        return {v.x * s, v.y * s};
    }

    vector2d operator/(long double scalar) const
    {
        return {x / scalar, y / scalar};
    }

    long double norm2() const
    {
        return x * x + y * y;
    }

    long double magnitude() const
    {
        return sqrtl(norm2());
    }

    vector2d unit() const
    {
        long double m = magnitude();
        if (feq(m, 0)) return {0, 0};
        return {x / m, y / m};
    }

    vector2d normal() const
    {
        vector2d v{y, -x};
        return v.unit();
    }
};

long double dist(const vector2d& p1, const vector2d& p2)
{
    return (p1 - p2).magnitude();
}

long double dot(const vector2d& v1, const vector2d& v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

long double angle(const vector2d& v1, const vector2d& v2)
{
    long double m = v1.magnitude() * v2.magnitude();
    if (feq(m, 0)) return 0;

    long double v = dot(v1, v2) / m;
    return acosl(min(1.0L, max(-1.0L, v)));
}

long double cross(const vector2d& v1, const vector2d& v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}