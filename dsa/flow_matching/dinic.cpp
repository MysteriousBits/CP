#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INFL (ll) 1e18

struct Dinic
{
    int s, t, n;
    vector<vector<int>> g;
    vector<vector<ll>> cap;
    vector<int> dist, ptr;
 
    Dinic(int s, int t, vector<vector<pair<int, ll>>>& dg) : s(s), t(t)
    {
        n = dg.size() - 1;
        g.resize(n + 1);
        dist.resize(n + 1); ptr.resize(n + 1);
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
        dist.assign(n + 1, -1);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
 
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
 
            for (int v : g[u])
            {
                if (dist[v] != -1 || !cap[u][v]) continue;
 
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
 
        return dist[t] != -1;
    }
 
    ll dfs(int u, ll f)
    {
        if (u == t) return f;
 
        for (int& p = ptr[u]; p < (int) g[u].size(); ++p)
        {
            int v = g[u][p];
            if (dist[v] != dist[u] + 1 || !cap[u][v]) continue;
 
            ll now = dfs(v, min(f, cap[u][v]));
            if (!now) continue;
 
            cap[u][v] -= now;
            cap[v][u] += now;
            return now;
        }
 
        return 0;
    }
 
    ll flow()
    {
        ll f = 0;
        while (bfs())
        {
            ptr.assign(n + 1, 0);
            while (ll sent = dfs(s, INFL))
                f += sent;
        }
 
        return f;
    }
};