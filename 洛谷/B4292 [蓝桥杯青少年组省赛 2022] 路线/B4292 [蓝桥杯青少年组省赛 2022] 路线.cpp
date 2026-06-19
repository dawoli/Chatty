#include<bits/stdc++.h>
#define INF INT32_MAX
using namespace std;
int n,m;
vector<vector<int> > a;
vector<vector<vector<int>>> f;
int main()
{
    cin>>n>>m;
    a.resize(n+1);
    for (int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int k = 1; k <= n; k++) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (k==0)
                {
                    bool flag = true;
                    for (int i=0;i<a[x].size();i++)
                    {
                        if (a[x][i]==y)
                        {
                            f[k][x][y] = 1;
                            flag=false;
                            break;
                        }
                    }
                    if (flag)f[k][x][y]=INF;
                }
                else f[k][x][y] = min(f[k - 1][x][y], f[k - 1][x][k] + f[k - 1][k][y]);
            }
        }
    }
    for (int i=1;i<n;i++)
    {
        cout<<f[n][i][n]<<' ';
    }
    return 0;
}