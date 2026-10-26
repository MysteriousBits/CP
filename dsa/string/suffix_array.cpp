#include <bits/stdc++.h>
using namespace std;

// pass s + "$" for suffix array
vector<int> suffix_array(string& s, int lim = 256)
{
    int n = s.size();
    vector<int> p(n), cls(n), cnt(lim);

    for (auto c : s) cnt[c]++;
    for (int i = 1; i < lim; ++i) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) p[--cnt[s[i]]] = i;

    int classes = 0;
    for (int i = 1; i < n; ++i)
    {
        if (s[p[i]] != s[p[i - 1]]) ++classes;
        cls[p[i]] = classes;
    }

    for (int k = 0; 1 << k < n; ++k)
    {
        cnt.assign(classes + 1, 0);
        for (int i = 0; i < n; ++i) p[i] = (p[i] - (1 << k) + n) % n;
        for (int i = 0; i < n; ++i) cnt[cls[p[i]]]++;
        for (int i = 1; i <= classes; ++i) cnt[i] += cnt[i - 1];

        vector<int> np(n);
        for (int i = n - 1; i >= 0; --i) np[--cnt[cls[p[i]]]] = p[i];
        p.swap(np);

        np.assign(n, 0); classes = 0;
        pair<int, int> prev = {cls[p[0]], cls[(p[0] + (1 << k)) % n]};
        for (int i = 1; i < n; ++i)
        {
            pair<int, int> now = {cls[p[i]], cls[(p[i] + (1 << k)) % n]};
            if (now != prev) ++classes;
            np[p[i]] = classes;
            prev = now;
        }

        cls.swap(np);
        if (classes == n - 1) break;
    }

    return p;
}

vector<int> kasai(string& s, vector<int>& p)
{
    int n = s.size();
    vector<int> lcp(n - 1), pi(n);
    for (int i = 0; i < n; ++i) pi[p[i]] = i;

    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        if (pi[i] == n - 1)
        {
            k = 0;
            continue;
        }

        int j = p[pi[i] + 1];
        while (max(i, j) + k < n && s[i + k] == s[j + k]) ++k;
        lcp[pi[i]] = k;
        if (k) --k;
    }

    return lcp;
}