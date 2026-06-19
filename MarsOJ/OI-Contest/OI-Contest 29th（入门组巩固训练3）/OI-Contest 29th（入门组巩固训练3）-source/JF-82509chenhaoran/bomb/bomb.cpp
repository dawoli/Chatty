#include <bits/stdc++.h>
using namespace std;
char s[1002][1002];
int a[1002][1002];
long long ans = INT_MAX , st = 0;
int n , m;
void dfs(int x , int y , long long cnt , long long step)
{
    if(x == n - 1 && y == m - 1)
    {
        if(cnt < ans)
        {
            ans = cnt;
            st = step;
        }
        return;
    }
    if(a[x][y] == 1)
    {
        dfs(x + 1 , y , cnt , step+1);
        dfs(x - 1 , y , cnt , step+1);
        dfs(x , y + 1 , cnt , step+1);
        dfs(x , y - 1 , cnt , step+1);
    }
    else if(a[x][y] == 2)
    {
        dfs(x + 1 , y , cnt , step+1);
        dfs(x - 1 , y , cnt , step+1);
        dfs(x , y + 1 , cnt , step+1);
        dfs(x , y - 1 , cnt , step+1);
        dfs(x + 1 , y , cnt + 1, step+1);
        dfs(x - 1 , y , cnt + 1, step+1);
        dfs(x , y + 1 , cnt + 1, step+1);
        dfs(x , y - 1 , cnt + 1, step+1);
    }
    else{
        return;
    }
}
int main()
{
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    int T;
    cin >> T;
    for(int i = 1;i <= T;i++)
    {
        cin >> n >> m;
        memset(a,-1,sizeof(a));
        for(int x = 0;x < n;x++)
        {
            for(int y = 0;y < m;y++)
            {
                cin >> s[x][y];
                if(s[x][y]=='.') a[x][y] = 1;
                else if(s[x][y] == '$') a[x][y] = 2;
            }
        }
        ans = INT_MAX;
        st = 0;
        dfs(0 , 0 , 0 , 0);
        cout << ans << " " << st << endl;
    }
    return 0;
}