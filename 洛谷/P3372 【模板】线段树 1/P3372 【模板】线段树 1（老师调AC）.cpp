#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T>
class line_tree_add_delay
{
public:
    struct node
    {
        int lt, rt;
        T w;
        T tag = 0;
    };

    vector<node> e;

    line_tree_add_delay() = default;

    void pushup(int u)
    {
        e[u].w = e[u * 2].w + e[u * 2 + 1].w;
    }

    void build(int u, int L, int R, const vector<T>& data)
    {
        e[u].lt = L;
        e[u].rt = R;
        if (L == R)
        {
            e[u].w = data[L]; // 修复：使用 data[L]（data 是 1-based）
        }
        else
        {
            int M = (L + R) / 2;
            build(u * 2, L, M, data);
            build(u * 2 + 1, M + 1, R, data);
            pushup(u);
        }
    }

    void init(int tree_size, const vector<T>& data)
    {
        e.clear();
        e.resize((tree_size + 1) * 4);
        build(1, 1, tree_size, data);
    }

    line_tree_add_delay(int tree_size, const vector<T>& data)
    {
        e.resize((tree_size + 1) * 4);
        build(1, 1, tree_size, data);
    }

    // 判断节点区间 [L,R] 是否被查询区间 [l,r] 完全覆盖
    bool InRange(int L, int R, int l, int r)
    {
        return (l <= L && R <= r);
    }

    // 判断节点区间 [L,R] 与查询区间 [l,r] 是否无交集
    bool OutRange(int L, int R, int l, int r)
    {
        return (R < l || r < L);
    }

    // 给节点打标记（增加值 x 到区间）
    void maketag(int u, int L, int R, T x)
    {
        e[u].tag += x;
        e[u].w += T(R - L + 1) * x;
    }

    void pushdown(int u, int L, int R)
    {
        if (L == R) return;
        if (e[u].tag == T(0)) return; // 只有有标记时才下推
        int M = (L + R) / 2;
        maketag(u * 2, L, M, e[u].tag);
        maketag(u * 2 + 1, M + 1, R, e[u].tag);
        e[u].tag = T(0);
    }

    T query(int u, int L, int R, int l, int r)
    {
        if (InRange(L, R, l, r))
        {
            return e[u].w;
        }
        if (OutRange(L, R, l, r))
        {
            return T(0);
        }
        int M = (L + R) / 2;
        pushdown(u, L, R);
        return query(u * 2, L, M, l, r) + query(u * 2 + 1, M + 1, R, l, r);
    }

    void update(int u, int L, int R, int l, int r, T x)
    {
        if (InRange(L, R, l, r))
        {
            maketag(u, L, R, x);
            return;
        }
        if (OutRange(L, R, l, r)) return;
        int M = (L + R) / 2;
        pushdown(u, L, R);
        update(u * 2, L, M, l, r, x);
        update(u * 2 + 1, M + 1, R, l, r, x);
        pushup(u);
    }
};

line_tree_add_delay<ll> lt;//真正的问题:十年OI一场空，不开long long见祖宗
vector<ll> a;
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m)) return 0;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    lt.init(n, a);
    while (m--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            ll k;
            cin >> k;
            lt.update(1, 1, n, x, y, k);
        }
        else if (op == 2)
        {
            cout << lt.query(1, 1, n, x, y) << '\n';
        }
    }
    return 0;
}
