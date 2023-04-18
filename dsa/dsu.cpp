#include <bits/stdc++.h>
using namespace std;

// struct imple
struct dsu
{
    int *parent, *size;
 
    dsu(int n)
    {
        parent = new int[n + 1];
        size = new int[n + 1];
 
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    ~dsu()
    {
        delete[] parent;
        delete[] size;
    }

    int find(int u)
    {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
 
    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
 
        if (u != v)
        {
            if (size[u] < size[v]) swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
    }
};


// Nonstruct imple
int find(int u, int parent[])
{
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v, int parent[], int size[])
{
    u = find(u, parent);
    v = find(v, parent);

    if (u != v)
    {
        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
}


// vector imple
// parent = 0 for roots
int find(int u, vecotr<int>& a)
{
    if (!a[u]) return u;
    return a[u] = find(a[u]);
}

void merge(int u, int v, vector<int>& a, vector<int>& size)
{
    u = find(u, a);
    v = find(v, a);

    if (u != v)
    {
        if (size[u] < size[v]) swap(u, v);
        a[v] = u;
        size[u] += size[v];
    }
}