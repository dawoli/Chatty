#include<bits/stdc++.h>
using namespace std;

template <typename T>
class line_tree_add_delay
{
public:
    struct node
    {
        int lt, rt;
        T zmx = 0, zmn = 0; //正的
        T fmx = 0, fmn = 0; //负的
        bool h0 = false;
    };

    vector<node> e;

    line_tree_add_delay() = default;

    void pushup(int u)
    {
        e[u].zmx = max(e[u * 2].zmx, e[u * 2 + 1].zmx);
        e[u].zmn = min(e[u * 2].zmn, e[u * 2 + 1].zmn);
        e[u].fmx = max(e[u * 2].fmx, e[u * 2 + 1].fmx);
        e[u].fmn = min(e[u * 2].fmn, e[u * 2 + 1].fmn);
        e[u].h0 = e[u * 2].h0 || e[u * 2 + 1].h0;
    }

    void build(int u, int L, int R, const vector<T>& data)
    {
        e[u].lt = L;
        e[u].rt = R;
        if (L == R)
        {
            if (data.at(L) > 0)
            {
                e[u].zmx = data.at(L);
                e[u].zmn = data.at(L);
            }
            else if (data.at(L) < 0)
            {
                e[u].fmn = data.at(L);
                e[u].fmx = data.at(L);
            }
            else e[u].h0 = true;
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
    static bool InRange(int L, int R, int l, int r)
    {
        return (l <= L && R <= r);
    }

    // 判断节点区间 [L,R] 与查询区间 [l,r] 是否无交集
    static bool OutRange(int L, int R, int l, int r)
    {
        return (R < l || r < L);
    }

    pair<pair<T, T>, pair<T, T>> query(int u, int L, int R, int l, int r)
    {
        if (InRange(L, R, l, r))
        {
            return {{e[u].fmx, e[u].fmn}, {e[u].zmx, e[u].zmn}};
        }
        if (OutRange(L, R, l, r))
        {
            return {{0,0},{0,0}};
        }
        int M = (L + R) / 2;
        auto ls = query(u * 2, L, M, l, r);
        auto rs = query(u * 2 + 1, M + 1, R, l, r);
        return {{max(ls.first.first,rs.first.first),min(ls.first.second,rs.first.second)},{max(ls.second.first,rs.second.first),min(ls.second.second,rs.second.second)}};
    }
};

int main()
{
    return 0;
}