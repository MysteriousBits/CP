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

char a[100][100], b[100][100], c[100][100];

void cpy()
{
    loop(i, 0, n)
    {
        loop(j, 0, m) c[i][j] = a[i][j];
    }
}

bool eq()
{
    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            if (c[i][j] != b[i][j]) return false;
        }
    }

    return true;
}

void ro(int j)
{
    loop(i, 0, m / 2)
    {
        swap(c[j][i], c[j][m - i - 1]);
        swap(c[n - j - 1][i], c[n - j - 1][m - i - 1]);
    }
}

void co(int j)
{
    loop(i, 0, n / 2)
    {
        swap(c[i][j], c[n - i - 1][j]);
        swap(c[i][m - j - 1], c[n - i - 1][m - j - 1]);
    }
}

void solve()
{
    cin >> n >> m >> tp;
    int k = n / 2 + m / 2;
    assert(k <= 20);

    loop(i, 0, n)
    {
        loop(j, 0, m) cin >> a[i][j];
    }
    loop(i, 0, n)
    {
        loop(j, 0, m) cin >> b[i][j];
    }

    int ans = INF;
    vector<pair<char, int>> op;
    loop(mask, 0, 1 << k)
    {
        cpy();
        vector<pair<char, int>> tmp;
        loop(i, 0, m / 2)
        {
            if (mask & (1 << i))
            {
                co(i);
                tmp.pb({'C', i});
            }
        }

        loop(i, m / 2, k)
        {
            if (mask & (1 << i))
            {
                ro(i - m / 2);
                tmp.pb({'R', i - m / 2});
            }
        }

        if (eq() && (int) tmp.size() < ans)
        {
            ans = tmp.size();
            op = tmp;
        }

        // for (auto [c, i] : tmp) cout << c << ' ' << i + 1 << nl;
        // loop(i, 0, n)
        // {
        //     loop(j, 0, m) cout << c[i][j] << ' ';
        //     cout << nl;
        // }
        // cout << nl;
    }

    if (ans == INF) cout << "-1\n";
    else
    {
        cout << ans << nl;
        for (auto [c, i] : op) cout << c << ' ' << i + 1 << nl;
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