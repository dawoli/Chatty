#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

int n , k , q , a[3010][2010];
bool f[10][2s00010];

void dfs(int st , int lstid , int lst)
{
    if (st > 5) return;
    for (int i = 1; i <= n; i++)
    {
        if (i == lstid) continue;
        for (int j = 1; j <= a[i][0]; j++)
        {
            if (a[i][j] != lst) continue;
            for (int k = j + 1; k < j + k; k++)
            {
                f[st][a[i][k]] = true;
                dfs(st + 1 , i , a[i][k]);
            }
        }
    }
}

int main()
{
    freopen("chain.in" , "r" , stdin);
    freopen("chain.out" , "w" , stdout);
    int T;
    cin >> T;
    while (T--)
    {
        memset(f , false , sizeof(f));
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i][0];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= a[i][0]; j++)
            {
                cin >> a[i][j];
            }
        }
        if (n <= 10 && q <= 100)
        {
            cout << "1\n";
            dfs(1 , 0 , 1);
        }
        else
        {
            cout << "2\n";
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= a[i][0]; j++)
                {
                    if (a[i][j] != 1) continue;
                    for (int k = i + 1; k < j + k; k++)
                    {
                        f[1][a[i][k]] = true;
                    }
                }
            }
        }
        while (q--)
        {
            int r , c;
            cin >> r >> c;
            cout << f[r][c] << endl;
        }
    }
    return 0;
}
