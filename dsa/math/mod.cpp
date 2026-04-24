#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353
#define MAXN 100001

ll fact[MAXN];

void calc_fact(ll mod = MOD)
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll mod(ll n, ll mod = MOD)
{
    n %= mod;
    return n < 0 ? mod + n : n;
}

ll modpow(ll n, ll k, ll mod = MOD)
{
    ll ret = 1;

    while (k)
    {
        if (k & 1) ret = (ret * n) % mod;
        n = (n * n) % mod;
        k >>= 1;
    }

    return ret;
}

inline ll inv(ll n, ll mod = MOD)
{
    return modpow(n, mod - 2, mod);
}

inline ll mul(ll x, ll y, ll mod = MOD)
{
    return ((x % mod) * (y % mod)) % mod;
}

inline ll dvd(ll x, ll y, ll mod = MOD)
{
    return mul(x, inv(y, mod), mod);
}

ll C(int n, int k, ll mod = MOD)
{
    if (k > n) return 0;
    
    return (1LL * fact[n] *
        inv((1LL * fact[k] * fact[n - k]) % mod)) % mod;
}