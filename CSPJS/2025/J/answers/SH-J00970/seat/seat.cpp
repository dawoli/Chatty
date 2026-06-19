#include <bits/stdc++.h>
using namespace std;
int a[111],s=1,f[111][111],g=1,k;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<=n*m;i++)
    {
        if(a[i]>a[1])
        {
            s++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i%2==1)
            {
                f[i][j]=g;
                if(g==s)
                    cout<<i<<" "<<j;
            }
            else
            {
                k=m-j+1;
                f[i][k]=g;
                if(g==s)
                    cout<<i<<" "<<k;
            }

            g++;

        }
    }

}
