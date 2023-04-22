#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct segtree
{
    #define left(u) 2 * u + 1
    #define right(u) 2 * u + 2

    int n;
    T init_val = 0;
    vector<T> tree;
    function<T (T, T)> f;

    segtree(int sz, function<T (T, T)> f, T val = 0)
    {
        n = sz;
        this->f = f;
        init_val = val;

        tree.assign(1 << (__lg(n - 1) + 2), init_val);
    }

    void build(vector<T>& a) { _build(0, 0, n - 1, a); }
    void update(int i, int x) { _update(0, 0, n - 1, i, x); }
    T get(int l, int r) { return _get(0, 0, n - 1, l, r); }

    void _build(int u, int l, int r, vector<T>& a)
    {
        if (l == r)
        {
            tree[u] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        _build(left(u), l, mid, a);
        _build(right(u), mid + 1, r, a);
        tree[u] = f(tree[left(u)], tree[right(u)]);
    }

    void _update(int u, int l, int r, int i, T x)
    {
        if (l == r)
        {
            tree[u] = x;
            return;
        }

        int mid = (l + r) / 2;
        if (i <= mid) _update(left(u), l, mid, i, x);
        else _update(right(u), mid + 1, r, i, x);
        tree[u] = f(tree[left(u)], tree[right(u)]);
    }

    T _get(int u, int tl, int tr, int l, int r)
    {
        if (l > r) return init_val;
        if (tl == l && tr == r) return tree[u];

        int mid = (tl + tr) / 2;
        return f(_get(left(u), tl, mid, max(tl, l), min(mid, r)),
                 _get(right(u), mid + 1, tr, max(mid + 1, l), min(tr, r)));
    }

    #undef left
    #undef right
};
