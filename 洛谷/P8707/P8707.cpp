#include<bits/stdc++.h>
using namespace std;
int n,m,f[31][31];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        f[i][1]=1;
    for(int i=1;i<=m;i++)
        f[1][i]=1;
    for(int i=2;i<=n;i++)
        {
        for(int j=2;j<=m;j++)
        {
            if(i%2==0&&j%2==0)f[i][j]=0;
            else f[i][j]=f[i-1][j]+f[i][j-1];
        }
    }
    cout<<f[n][m];
    return 0;
}