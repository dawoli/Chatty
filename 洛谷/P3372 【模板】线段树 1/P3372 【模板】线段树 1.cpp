#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T>
class line_tree_add_delay
{
public:
    struct node
    {
        size_t lt, rt;
        T w;
        T tag = 0;
    };

    vector<node> e;
    typedef typename vector<node>::size_type size_type;
    typedef T value_type;
    line_tree_add_delay() = default;

    void pushup(int u)
    {
        e[u].w = e[u * 2].w + e[u * 2 + 1].w;
    }

    void build(int u, int L, int R, vector<T>& data)
    {
        e[u].lt = L;
        e[u].rt = R;
        if (L == R)
        {
            e[u].w = data[L]; // 修复：原来是 tree[L].w = data.at(L); 错误索引
        }
        else
        {
            int M = (L + R) / 2;
            build(u * 2, L, M, data);
            build(u * 2 + 1, M + 1, R, data);
            pushup(u);
        }
    }

    void init(size_t tree_size, vector<T> data)
    {
        e.resize((tree_size + 1) * 4);
        build(1, 1, tree_size, data);
    }

    line_tree_add_delay(size_t tree_size, vector<T> data)
    {
        e.resize((tree_size + 1) * 4);
        build(1, 1, tree_size, data);
    }

    bool InRange(size_t L, size_t R, size_t l, size_t r)
    {
        return (l <= L && R <= r); // 修复逻辑：判断区间 [L,R] 是否完全在 [l,r] 内
    }

    bool OutRange(size_t L, size_t R, size_t l, size_t r)
    {
        return (R < l || r < L); // 判断区间 [L,R] 与 [l,r] 是否完全不相交
    }

    void maketag(size_t u, size_t L, size_t R, ll x)
    {
        e[u].tag += x;
        e[u].w += (R - L + 1) * x;
    }

    void pushdown(int u, int L, int R)
    {
        if (L == R) return;
        int M = (L + R) / 2;
        maketag(u * 2, L, M, e[u].tag);
        maketag(u * 2 + 1, M + 1, R, e[u].tag);
        e[u].tag = 0;
    }

    ll query(size_t u, size_t L, size_t R, size_t l, size_t r)
    {
        if (InRange(L, R, l, r))
        {
            return e[u].w;
        }
        if (!OutRange(L, R, l, r))
        {
            int M = (L + R) / 2;
            pushdown(u, L, R);
            return query(u * 2, L, M, l, r) + query(u * 2 + 1, M + 1, R, l, r);
        }
        else
        {
            return 0;
        }
    }

    void update(size_t u, size_t L, size_t R, size_t l, size_t r, T x)
    {
        if (InRange(L, R, l, r))
        {
            maketag(u, L, R, x);
        }
        else if (!OutRange(L, R, l, r))
        {
            int M = (L + R) / 2;
            pushdown(u, L, R);
            update(u * 2, L, M, l, r, x);
            update(u * 2 + 1, M + 1, R, l, r, x);
            pushup(u);
        }
    }
};

line_tree_add_delay<int> lt;
vector<int> a;
int n, m;

int main()
{
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    lt.init(n, a);
    while (m--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        switch (op)
        {
        case 1:
            {
                int k;
                cin >> k;
                lt.update(1, 1, n, x, y, k);
                break;
            }
        case 2:
            cout << lt.query(1, 1, n, x, y) << '\n';
            break;
        }
    }
    return 0;
}
