// #define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Template
// ==============================================
    // Debugging
    #ifdef LOCAL
    #include "debug.h"
    #else
    #define debug(...)
    #define see(x)
    #endif

    template<typename T, typename comp = less<T>>
    using ordered_set =  tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
    typedef long long ll;
    typedef vector<int> VI;
    typedef vector<long long> VLL;
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

void solve()
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}