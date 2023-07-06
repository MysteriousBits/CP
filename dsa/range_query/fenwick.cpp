#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// struct imple
struct fenwick
{
    int n;
    vector<ll> tree;

    fenwick(int s)
    {
        n = s;
        tree.assign(n + 1, 0);
    }

    ll get(int i)
    {
        ll res = 0;
        for(; i > 0; i -= i & -i) res += tree[i];
        return res;
    }

    void add(int i, int x)
    {
        for (; i <= n; i += i & -i) tree[i] += x;
    }
    
    ll rsq(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};



// non-struct imple
inline ll get(int i, vecotr<ll>& tree)
{
    ll res = 0;
    for(; i > 0; i -= i & -i) res += tree[i];
    return res;
}

inline void add(int i, int x, vector<ll>& tree)
{
    for (; i <= n; i += i & -i) tree[i] += x;
}