#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> manacher(string& s)
{
    int n = s.size();
    vector<vector<int>> p(2, vector<int>(n));
    // p[0] -> even length, p[1] -> odd length
    // p[1][i] = 0, for no palindrome around, p[0][i] = 0, if s[i] != s[i - 1]

    for (int t = 0; t < 2; ++t)
    {
        int l = 0, r = 0, e = 1 - t;
        for (int i = 1; i < n; ++i)
        {
            if (r < i) r = i - e, l = i;
            else p[t][i] = min(r - i + e, p[t][l + r - i + e]);

            if (i + p[t][i] - e == r) l = 2 * i - r - e;
            while (r < n - 1 && l && s[l - 1] == s[r + 1]) ++r, --l, p[t][i]++;
        }
    }

    return p;
}

bool is_pal(int l, int r, vector<vector<int>>& p)
{
    int m = (l + r) / 2;
    if ((r - l) & 1) { return m + p[0][m + 1] >= r; }
    return m + p[1][m] >= r;
}