#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353
#define MAXN 100001

inline ll mod(ll n, ll m = MOD)
{
    return (m + n % m) % m;
}

ll modpow(ll n, ll k, ll m = MOD)
{
    ll ret = 1;
    n = mod(n, m);
    while (k)
    {
        if (k & 1) ret = (ret * n) % m;
        n = (n * n) % m;
        k >>= 1;
    }

    return ret;
}

inline ll inv(ll n, ll m = MOD)
{
    return modpow(n, m - 2, m);
}

inline ll mul(ll x, ll y, ll m = MOD)
{
    return (mod(x, m) * mod(y, m)) % m;
}

inline ll dvd(ll x, ll y, ll m = MOD)
{
    return mul(x, inv(y, m), m);
}

// Binomial coeffecient
ll fact[MAXN];
void calc_fact(ll m = MOD)
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i)
    {
        fact[i] = (fact[i - 1] * i) % m;
    }
}

ll C(int n, int k, ll m = MOD)
{
    if (k > n) return 0;
    
    return dvd(fact[n], fact[k] * fact[n - k] % m, m);
}