#include<bits/stdc++.h>
using namespace std;
constexpr int maxn=301;
int n,a[maxn],f[maxn][maxn],w[maxn][maxn];
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
            w[i][j]=w[i][j-1]+a[j];
    for (int L=1;L<n;L++)
        for (int i=1;i+L<=n;i++)
        {
            int j=i+L,&fij=f[i][j];
            fij=INT_MAX;
            for (int k=i;k<j;k++)
                fij=min(fij,f[i][k]+f[k+1][j]);
            fij+=w[i][j];
        }
    cout<<f[1][n]<<endl;
    return 0;
}