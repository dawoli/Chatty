#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m,a[105];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int r=a[1];
    bool bl[15][15];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(a[j]==r)
            {
                bl[i][j]=1;
            }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(bl[i][j]==1)
            {
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
}
