#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(string& s)
{
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;

    for (int i = 1; i < n; ++i)
    {
        int cur = p[i - 1];
        while (cur && s[cur] != s[i])
            cur = p[cur - 1];

        p[i] = cur + (s[i] == s[cur]);
    }

    return p;
}