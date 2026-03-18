#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-12
#define pi 3.141592653589793115997963468544185161590576171875L

bool feq(const long double& a, const long double& b)
{
    long double del = fabsl(a - b);
    if (del <= EPS) return true;

    return del <= EPS * max(fabsl(a), fabsl(b));
}