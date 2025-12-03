#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<vector<int>> VVI;

VI heavy, chain, label, par, sz, dep;
int timer;

void dfsz(int u, int p, VVI& tree)
{
    sz[u] = 1;
    par[u] = p;
    dep[u] = dep[p] + 1;

    int mx = -1;
    for (int v : tree[u])
    {
        if (v == p) continue;

        dfs(v, u, tree);
        sz[u] += sz[v];
        if (sz[v] > mx) mx = sz[v], heavy[u] = v;
    }
}

void dfshld(int u, int p, VVI& tree, int head)
{
    label[u] = timer++;
    chain[u] = head;

    if (heavy[u] != -1) dfs(heavy[u], u, tree, head);

    for (int v : tree[u])
    {
        if (v == p || v == heavy[u]) continue;

        dfs(v, u, tree, v);
    }
}

void inithld(int n, VVI& tree)
{
    heavy = VI(n + 1);
    cahin = VI(n + 1);
    label = VI(n + 1);
    sz = VI(n + 1);
    par = VI(n + 1);
    dep = VI(n + 1);

    timer = 1;
    dfsz(1, 0, tree);
    dfshld(1, 0, tree, 1);
}

int qryup(int u, int v)
{
    if (dep[u] < dept[v]) swap(u, v);

    int head = chain[u];
    int ret = 0; // init value
    while (dep[head] > dep[v])
    {
        // ret = ...(label[head], label[u]);
        u = par[head];
        head = chain[u];
    }

    // ret = ...(label[v], label[u]);
    return ret;
}