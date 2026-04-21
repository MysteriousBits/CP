#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct node
{
    T val;
    int l, r;
};

template<typename T>
struct persistent_segtree
{
    int n;
    T init_val;
    vector<node<T>> nodes;
    vector<int> version;
    function<T (T, T)> f;

    persistent_segtree() {}
    
    persistent_segtree(int sz, function<T (T, T)> f, T val = 0)
    {
        n = sz;
        this->f = f;
        init_val = val;

        build(vector<T>(n, init_val));
    }

    persistent_segtree(vector<T> a, function<T (T, T)> f, T val = 0)
    {
        n = a.size();
        this->f = f;
        init_val = val;

        build(a);
    }

    int build(vector<T> a)
    {
        int root = _build(0, n - 1, a);
        version.pb(root);

        return version.size() - 1;
    }

    int update(int i, T x, int v)
    {
        int root = _update(version[v], 0, n - 1, i, x);
        version.pb(root);
        return version.size() - 1;
    }

    T get(int l, int r, int v)
    {
        return _get(version[v], 0, n - 1, l, r);
    }

    int _build(int l, int r, vector<T>& a)
    {
        int root = nodes.size();
        nodes.pb(node<T>());

        if (l == r)
        {
            nodes[root].val = a[l];
            return root;
        }

        int mid = (l + r) / 2;
        nodes[root].l = _build(l, mid, a);
        nodes[root].r = _build(mid + 1, r, a);
        nodes[root].val = f(nodes[nodes[root].l].val, nodes[nodes[root].r].val);
        return root;
    }

    int _update(int u, int l, int r, int i, T x)
    {
        int root = nodes.size();
        nodes.pb(nodes[u]);

        if (l == r)
        {
            nodes[root].val = x;
            return root;
        }

        int mid = (l + r) / 2;
        if (i <= mid) nodes[root].l = _update(nodes[u].l, l, mid, i, x);
        else nodes[root].r = _update(nodes[u].r, mid + 1, r, i, x);
        nodes[root].val = f(nodes[nodes[root].l].val, nodes[nodes[root].r].val);

        return root;
    }

    T _get(int u, int tl, int tr, int l, int r)
    {
        if (l > tr || r < tl) return init_val;
        if (l <= tl && r >= tr) return nodes[u].val;

        int mid = (tl + tr) / 2;
        return f(_get(nodes[u].l, tl, mid, l, r),
            _get(nodes[u].r, mid + 1, tr, l, r));
    }
};