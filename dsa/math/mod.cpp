#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353
#define MAXN 100001

int fact[MAXN];

ll mod(ll n)
{
    n %= MOD;
    return n < 0 ? MOD + n : n;
}

ll modpow(ll n, int k)
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

ll C(int n, int k)
{
    if (k > n) return 0;
    
    return (1LL * fact[n] *
        inv((1LL * fact[k] * fact[n - k]) % MOD)) % MOD;
}