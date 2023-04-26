#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

const int K = 25;
int step = 0;
int depth[MAXN], vis_start[MAXN], vis_end[MAXN];
int st[MAXN][K];

int k;
vector<vector<int>> tree;

void build_st(int u, int p)
{
    st[u][0] = p;
    for (int i = 1; i <= k; ++i)
        st[u][i] = st[st[u][i - 1]][i - 1];
}

void dfs(int u, int p, int d)
{
    depth[u] = d++;
    vis_start[u] = step++;
    build_st(u, p);

    for (auto v : tree[u])
    {
        if (v != p) dfs(v, u, d);
    }

    vis_end[u] = step++;
}

bool is_ancestor(int a, int b)
{
    return vis_start[a] < vis_start[b] && vis_end[a] > vis_end[b];
}

int lca(int a, int b)
{
    if (is_ancestor(a, b)) return a;
    if (is_ancestor(b, a)) return b;

    for (int i = k; i >= 0)
    {
        if (!is_ancestor(st[a][i], b)) a = st[a][i];
    }

    return st[a][0];
}

int get_ancestor(int u, int n)
{
    for (int i = 0; n > 0; ++i)
    {
        if (n & (1 << i))
        {
            u = st[u][i];
            n -= (1 << i);
        }
    }

    return u;
}
