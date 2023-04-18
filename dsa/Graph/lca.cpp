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

int height[MAXN];
int st[MAXN][20];

void build_st(int u, int p)
{
    st[u][0] = p;
 
    for (int i = 1; i <= k; ++i)
    {
        st[u][i] = st[st[u][i - 1]][i - 1];
    }
}

int get_ancestor(int u, int n)
{
    int x = 0;
    while (n > 0)
    {
        if (n & (1 << lstbits))
        {
            u = st[u][x];
            n -= lstbits;
        }
        x ++;
    }
 
    return u;
}
 
int lca(int a, int b)
{
    if (height[b] > height[a]) swap(a, b);
 
    if (height[a] > height[b])
    {
        a = get_ancestor(a, height[a] - height[b]);
    }
 
    if (a == b) return a;
 
    int l = 1, r = height[a];
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (get_ancestor(a, mid) == get_ancestor(b, mid)) r = mid;
        else l = mid + 1;
    }
 
    return get_ancestor(a, l);
}