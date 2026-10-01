#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INFL (ll) 1e18

struct LiChao
{
    struct Line { ll m, c; ll f(ll x) { return m * x + c; }};

    #define lc u << 1
    #define rc (u << 1) | 1
    vector<Line> tree;
    LiChao(int n) { tree.resize(4 * (n + 1), {0, INFL}); } // -INF for max
    ll mp(int x) { return x; } // transform coordinate with monotonic function

    void add(int u, int l, int r, Line line)
    {
        int mid = (l + r) >> 1;
        if (line.f(mp(mid)) < tree[u].f(mp(mid))) swap(tree[u], line);
        if (l == r) return;
        if (line.f(mp(l)) < tree[u].f(mp(l))) add(lc, l, mid, line);
        else add(rc, mid + 1, r, line);
    }

    ll query(int u, int l, int r, int x)
    {
        ll ans = tree[u].f(mp(x));
        if (l == r) return ans;
        int mid = (l + r) >> 1;
        if (x <= mid) ans = min(ans, query(lc, l, mid, x));
        else ans = min(ans, query(rc, mid + 1, r, x));
        return ans;
    }
};
