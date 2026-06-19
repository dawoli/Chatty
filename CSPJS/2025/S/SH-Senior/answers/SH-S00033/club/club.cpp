#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

const int MAXN = 1e5 + 8;
int n, t;
priority_queue <pair <int, int>> q[MAXN];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        for(int i = 1; i <= MAXN; i++)
            while(!q[i].empty())
                q[i].pop();

        int vis[3] = {};
        cin >> n;
        int r = n / 2, a, ans = 0;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= 3; j++)
                cin >> a, q[i].push({a, j});

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                if(vis[q[i].top().second] <= r)
                {
                    ans += q[i].top().first;
                    vis[q[i].top().second]++;
                    break;
                }
                else
                    q[i].pop();
            }

        }
        cout << ans << "\n";
    }
	return 0;
}
