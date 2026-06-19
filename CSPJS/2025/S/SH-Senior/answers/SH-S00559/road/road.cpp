#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

class UnionFinder
{
public:
    UnionFinder(int n);
    int getRoot(int u);
    void unite(int u, int v);
    bool isUnited(int u, int v);
    bool isRoot(int u);
private:
    vector<int> fa;
};

struct EdgeNode
{
    int u, v, w;
};

class Solution
{
public:
    Solution();
    void solve(istream &in, ostream &out);
private:
    multiset<EdgeNode> edge;
    int n, m, k;
};

UnionFinder::UnionFinder(int n) : fa(n + 1)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
}

bool UnionFinder::isRoot(int u)
{
    return u == fa[u];
}

int UnionFinder::getRoot(int u)
{
    return isRoot(u) ? u : fa[u] = getRoot(fa[u]);
}

bool UnionFinder::isUnited(int u, int v)
{
    return getRoot(u) == getRoot(v);
}

void UnionFinder::unite(int u, int v)
{
    if (!isUnited(u, v))
    {
        fa[getRoot(u)] = getRoot(v);
    }
}

Solution::Solution() {}

void Solution::solve(istream &in, ostream &out)
{
    in >> n >> m >> k;

    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        in >> u >> v >> w;
        edge.insert({u, v, w});
        edge.insert({v, u, w});
    }

    for (int i = 1; i <= k; ++i)
    {
        int cj;
        in >> cj;
        for (int j = 1; j <= n; ++j)
        {
            int w;
            in >> w;
            edge.insert({n + i, j, w});
            edge.insert({j, n + i, w});
        }
    }

    UnionFinder uf(n + k);
    int sum = 0;

    for (auto road : edge)
    {
        if (!uf.isUnited(road.u, road.v))
        {
            uf.unite(road.u, road.v);
            sum += road.w;
        }
    }

    out << sum << endl;
}

bool operator< (EdgeNode a, EdgeNode b)
{
    return a.w < b.w;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    Solution sl;

    sl.solve(cin, cout);

    return 0;
}
