#include <bits/stdc++.h>
using namespace std;

// ── Aggregation: change this to switch between sum / min / max ────────────────

using T = long long;
const T ID = 0;                          // identity: 0 for sum, LLONG_MAX for min, LLONG_MIN for max
T combine(T a, T b) { return a + b; }   // change to min(a,b) or max(a,b)

// ── Splay Node ────────────────────────────────────────────────────────────────

struct Node {
    Node *ch[2], *par;
    bool rev;
    T val, agg;

    Node() : ch{}, par(nullptr), rev(false), val(ID), agg(ID) {}

    bool is_root() {
        return !par
            || (par->ch[0] != this && par->ch[1] != this);
    }

    void pull() {
        agg = val;
        if (ch[0]) agg = combine(ch[0]->agg, agg);
        if (ch[1]) agg = combine(agg, ch[1]->agg);
    }

    void push() {
        if (!rev) return;
        swap(ch[0], ch[1]);
        if (ch[0]) ch[0]->rev ^= 1;
        if (ch[1]) ch[1]->rev ^= 1;
        rev = false;
    }

    void push_all() {
        if (!is_root()) par->push_all();
        push();
    }

    void rotate() {
        Node* p = par;
        Node* g = p->par;
        int   s = (p->ch[1] == this);

        p->ch[s] = ch[s^1];
        if (ch[s^1]) ch[s^1]->par = p;

        ch[s^1] = p;
        p->par  = this;
        par     = g;

        if (g && g->ch[0] == p) g->ch[0] = this;
        if (g && g->ch[1] == p) g->ch[1] = this;

        p->pull();
        pull();
    }

    void splay() {
        push_all();
        while (!is_root()) {
            Node* p = par;
            if (!p->is_root()) {
                bool zigzig = (p->par->ch[0] == p) == (p->ch[0] == this);
                (zigzig ? p : this)->rotate();
            }
            rotate();
        }
    }
};

// ── Link Cut Tree ─────────────────────────────────────────────────────────────

struct LCT {
    vector<Node> nd;

    LCT(int n) : nd(n) {}

    Node* operator[](int i) { return &nd[i]; }

    void set(int u, T v) {
        nd[u].val = v;
        nd[u].splay();   // propagate pull() up
    }

    void access(Node* x) {
        Node* last = nullptr;
        for (Node* y = x; y; y = y->par) {
            y->splay();
            y->ch[1] = last;
            y->pull();
            last = y;
        }
        x->splay();
    }

    void make_root(Node* x) {
        access(x);
        x->rev ^= 1;
    }

    Node* get_root(Node* x) {
        access(x);
        while (x->ch[0]) { x->push(); x = x->ch[0]; }
        x->splay();
        return x;
    }

    T query(Node* u, Node* v) {
        make_root(u);
        access(v);
        return v->agg;
    }

    // NOTE: roots must be fixed, do not use make_root before lca()
    Node* lca(Node* u, Node* v) {
        access(u);
        Node* last = nullptr;
        for (Node* y = v; y; y = y->par) {
            y->splay();
            y->ch[1] = last;
            last = y;
        }
        return last;
    }

    void link(Node* u, Node* v) {
        make_root(u);
        if (get_root(v) != u) u->par = v;
    }

    void cut(Node* u, Node* v) {
        make_root(u);
        access(v);
        if (v->ch[0] == u && !u->ch[1]) {
            v->ch[0] = nullptr;
            u->par   = nullptr;
        }
    }

    // convenience index overloads
    void link(int u, int v)       { link(&nd[u], &nd[v]); }
    void cut(int u, int v)        { cut(&nd[u], &nd[v]); }
    bool connected(int u, int v)  { return get_root(&nd[u]) == get_root(&nd[v]); }
    T    query(int u, int v)      { return query(&nd[u], &nd[v]); }
    Node* get_root(int u)         { return get_root(&nd[u]); }
    Node* lca(int u, int v)       { return lca(&nd[u], &nd[v]); }
};

// ── Demo ──────────────────────────────────────────────────────────────────────

int main() {
    int n = 6;
    LCT lct(n + 1);  // 1-indexed

    // assign values 1..6
    for (int i = 1; i <= n; i++) lct.set(i, i);

    // Build:  1 - 2 - 3 - 4
    //                 |
    //                 5 - 6
    lct.link(1, 2); lct.link(2, 3); lct.link(3, 4);
    lct.link(3, 5); lct.link(5, 6);

    cout << "query(1,4): " << lct.query(1, 4) << "\n";  // 1+2+3+4 = 10
    cout << "query(1,6): " << lct.query(1, 6) << "\n";  // 1+2+3+5+6 = 17

    lct.set(3, 10);
    cout << "after set(3,10):\n";
    cout << "query(1,4): " << lct.query(1, 4) << "\n";  // 1+2+10+4 = 17

    lct.cut(3, 5);
    cout << "after cut(3,5):\n";
    cout << "connected(1,6): " << lct.connected(1, 6) << "\n"; // 0
    cout << "connected(1,4): " << lct.connected(1, 4) << "\n"; // 1
    cout << "query(1,4): "     << lct.query(1, 4)     << "\n"; // 17
}