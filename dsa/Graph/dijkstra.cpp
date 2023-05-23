#include <bits/stdc++.h>
using namespace std;

// Template
// ==============================================
    typedef long long ll;
    typedef vector<int> VI;
    typedef vector<bool> VB;
    typedef vector<vector<int>> VVI;
    typedef pair<int, int> PI;
    typedef vector<pair<int, int>> VPI;
    #define pb push_back
    #define ff first
    #define ss second
    #define loop(i, s, e) for (int i = s; i < e; ++i)
    #define inp(v) for (auto& x : v) cin >> x
    #define all(a) a.begin(), a.end()
    #define revall(a) a.rbegin(), a.rend()
    #define nl "\n"
    #define MOD 998244353
    #define MAXN 200001
    #define INF (int) 1e9
    #define MINF (int) -1e9
// ==============================================

struct Node
{
    int u;
    ll dist;

    bool operator< (const Node& v) const
    {
        return dist < v.dist;
    }
};

void dijkstra(int start, vector<ll>& dis, vector<VPI>& adj)
{
    priority_queue<Node> q;
    dis[start] = 0;
    q.push({start, 0});

    while (!q.empty())
    {
        Node node = q.top();
        int u = node.u;
        q.pop();

        if (dis[u] < node.dist) continue;

        for (auto e : adj[u])
        {
            if (node.dist + e.ss < dis[e.ff])
            {
                dis[e.ff] = node.dist + e.ss;
                q.push({e.ff, dis[e.ff]});
            }
        }
    }
}