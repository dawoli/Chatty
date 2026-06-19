#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10000009],f[100000][1000];
long long sum=0;
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    f[1][1]=max(a[1],a[2]);
    for(int j=1;j<=log2(n);j++)
    {
        for(int i=1;i<=n+(1<<j)+1;i++)
        {
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        int t;
        cin>>t;
        sum+=f[i][int(log2(t))];
    }
    cout<<sum;
    return 0;
}