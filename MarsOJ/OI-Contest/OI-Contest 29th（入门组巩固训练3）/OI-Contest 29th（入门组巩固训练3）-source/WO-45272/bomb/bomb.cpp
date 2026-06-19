#include <bits/stdc++.h>
using namespace std;

struct node{
    int x, y, sum;
    bool operator < (const node& x) const {
        return sum < x.sum;
    }
};

char a[1005][1005];
bool vis[1005][1005];
int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int bfs()
{
    memset(vis, 0, sizeof vis);
    vis[1][1] = 1;
    priority_queue < node > q;
    q.push({1, 1, 0});
    while (!q.empty())
    {
        node now = q.top();
        q.pop();
        if (now.x == n && now.y == m)
        {
            return now.sum;
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = dx[i] + now.x, ty = dy[i] + now.y;
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] != '*' && vis[tx][ty] == 0)
            {
                if (a[tx][ty] == '.') q.push({tx, ty, now.sum});
                else q.push({tx, ty, now.sum + 1});
            }
        }
    }
}

int main()
{
    freopen("bomb.in", "r", stdin);
    freopen("bomb.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        cout << bfs() << endl;
    }
    return 0;
}