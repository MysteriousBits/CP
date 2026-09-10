#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INFL (ll) 1e18

struct Edmondkarp
{
    int s, t, n;
    vector<vector<int>> g;
    vector<vector<ll>> cap;
    vector<int> par;

    Edmondkarp(int s, int t, vector<vector<pair<int, ll>>>& dg) : s(s), t(t)
    {
        n = dg.size() - 1;
        g.resize(n + 1);
        cap.resize(n + 1, vector<ll>(n + 1));
        for (int u = 1; u <= n; ++u) for (auto[v, c] : dg[u])
        {
            g[u].pb(v);
            g[v].pb(u);
            cap[u][v] += c;
        }

        for (int u = 1; u <= n; ++u)
        {
            sort(g[u].begin(), g[u].end());
            g[u].erase(unique(g[u].begin(), g[u].end()), g[u].end());
        }
    }

    bool bfs()
    {
        par.assign(n + 1, 0);
        par[s] = s;
        queue<int> q;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : g[u])
            {
                if (par[v] || !cap[u][v]) continue;

                par[v] = u;
                if (v == t) return true;
                q.push(v);
            }
        }

        return false;
    }

    ll flow()
    {
        ll f = 0;
        while (bfs())
        {
            int u = t;
            ll mn = INFL;
            while (u != s)
            {
                mn = min(mn, cap[par[u]][u]);
                u = par[u];
            }

            f += mn;
            u = t;
            while (u != s)
            {
                cap[par[u]][u] -= mn;
                cap[u][par[u]] += mn;
                u = par[u];
            }
        }

        return f;
    }
};