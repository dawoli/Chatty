#include <iostream>

using namespace std;

int a[10005][20005];
int n,k,q;
bool flag = 0;

bool dfs(int curr,int step,int r,int c)
{
    if(step == r)
    {
        if(curr == c) flag = true;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 2;j <= k;j++)
        {
            if(a[i][j] == curr)
            {
                for(int t = j;t <= k;t++)
                {
                    dfs(t,step + 1,r,c);
                }
            }
        }
    }
    return 0;
}

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i][0];
            for(int j = 1;j <= a[i][0];j++) cin >> a[i][j];
        }
        for(int i = 1;i <= q;i++)
        {
            int r,c;
            cin >> r >> c;
            dfs(1,1,r,c);
            if(flag == 1) cout << 1 <<endl;
            else cout << 0 <<endl;
            flag = 0;
        }
    }
    return 0;
}
