#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[5010],w[5010];
long long cnt = 0;
const int P = 998244353;
void dfs(int step,int sum,int mx,int c)
{
    if (step > n)
    {
        if (c >= 3 && sum > mx * 2) cnt++;
        return;
    }
    a[step] = 1;
    dfs(step + 1,sum + w[step],max(mx,w[step]),c + 1);
    a[step] = 0;
    dfs(step + 1,sum,mx,c);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    dfs(1,0,0,0);
    cout << cnt % P;
    return 0;
}
