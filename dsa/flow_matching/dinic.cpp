#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INFL (ll) 1e18

struct Dinic {
  struct Edge { int u, v; ll oc, c; };
  int s, t, n;
  vector<vector<int>> g;
  vector<Edge> edges;
  vector<int> dist, ptr;

  Dinic(int n, int s, int t) : s(s), t(t), n(n) { g.resize(n + 1); }

  void add_edge(int u, int v, ll cap, ll rcap = 0) {
    g[u].pb(edges.size()); g[v].pb(edges.size() + 1);
    edges.pb({u, v, cap, cap}); edges.pb({v, u, rcap, rcap});
  }
  bool bfs() {
    dist.assign(n + 1, -1); dist[s] = 0;
    queue<int> q; q.push(s);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int id : g[u]) {
        auto& e = edges[id];
        if (dist[e.v] == -1 && e.c)
          dist[e.v] = dist[u] + 1, q.push(e.v);
      }
    }
    return dist[t] != -1;
  }
  ll dfs(int u, ll f) {
    if (u == t) return f;
    for (int& p = ptr[u]; p < (int)g[u].size(); p++) {
      auto& e = edges[g[u][p]];
      if (dist[e.v] != dist[u] + 1 || !e.c) continue;
      ll now = dfs(e.v, min(f, e.c));
      if (!now) continue;
      e.c -= now; edges[g[u][p] ^ 1].c += now;
      return now;
    }
    return 0;
  }
  ll maxflow() {
    ll f = 0;
    while (bfs()) {
      ptr.assign(n + 1, 0);
      while (ll sent = dfs(s, INFL)) f += sent;
    }
    return f;
  }
  // flow on edge id: rev=false for forward, rev=true for reverse (undirected)
  ll flow(int id, bool rev = false) {
    id = id << 1 | rev;
    return edges[id].oc - edges[id].c;
  }
};