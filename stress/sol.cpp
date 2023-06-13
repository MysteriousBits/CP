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

int n, m, tp;

void ro(int j, vector<vector<char>>& c, vector<vector<char>>& b)
{
    loop(i, 0, m / 2)
    {
        swap(c[j][i], c[j][m - i - 1]);
        swap(c[n - j - 1][i], c[n - j - 1][m - i - 1]);
    }
}

void co(int j, vector<vector<char>>& c, vector<vector<char>>& b)
{
    loop(i, 0, n / 2)
    {
        swap(c[i][j], c[n - i - 1][j]);
        swap(c[i][m - j - 1], c[n - i - 1][m - j - 1]);
    }
}

bool check_row(int i, vector<vector<char>>& a, vector<vector<char>>& b)
{
    loop(j, 0, m)
    {
        if (min(a[i][j], a[n - i - 1][j]) != min(b[i][j], b[n - i - 1][j]) ||
            max(a[i][j], a[n - i - 1][j]) != max(b[i][j], b[n - i - 1][j]))
            return false;
    }

    return true;
}

bool check_col(int i, vector<vector<char>>& a, vector<vector<char>>& b)
{
    loop(j, 0, n)
    {
        if (min(a[j][i], a[j][m - i - 1]) != min(b[j][i], b[j][m - i - 1]) ||
            max(a[j][i], a[j][m - i - 1]) != max(b[j][i], b[j][m - i - 1]))
            return false;
    }

    return true;
}

void solve()
{
    cin >> n >> m >> tp;
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<char>> b(n, vector<char>(m));

    loop(i, 0, n)
    {
        loop(j, 0, m) cin >> a[i][j];
    }
    loop(i, 0, n)
    {
        loop(j, 0, m) cin >> b[i][j];
    }

    VB row(n / 2, true), col(m / 2, true);
    loop(i, 0, n / 2)
    {
        if (check_row(i, a, b)) row[i] = false;
    }
    loop(i, 0, m / 2)
    {
        if (check_col(i, a, b)) col[i] = false;
    }

    vector<pair<char, int>> ans;
    loop(i, 0, n / 2)
    {
        if (row[i])
        {
            ro(i, a, b);
            ans.pb({'R', i + 1});
        }
    }
    loop(i, 0, m / 2)
    {
        if (col[i])
        {
            co(i, a, b);
            ans.pb({'C', i + 1});
        }
    }

    if (a != b) cout << "-1\n";
    else
    {
        cout << ans.size() << nl;
        for (auto [c, i] : ans) cout << c << '#' << i << nl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}