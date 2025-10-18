#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353
#define MAXN 100001

ll fact[MAXN];

void calc_fact()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

ll mod(ll n)
{
    n %= MOD;
    return n < 0 ? MOD + n : n;
}

ll modpow(ll n, ll k)
{
    ll ret = 1;

    while (k)
    {
        if (k & 1) ret = (ret * n) % MOD;
        n = (n * n) % MOD;
        k >>= 1;
    }

    return ret;
}

inline ll inv(ll n)
{
    return modpow(n, MOD - 2);
}

inline ll mul(ll x, ll y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

inline ll dvd(ll x, ll y)
{
    return mul(x, inv(y));
}

ll C(int n, int k)
{
    if (k > n) return 0;
    
    return (1LL * fact[n] *
        inv((1LL * fact[k] * fact[n - k]) % MOD)) % MOD;
}