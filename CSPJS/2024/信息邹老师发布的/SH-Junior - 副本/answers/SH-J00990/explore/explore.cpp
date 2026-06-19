#include <bits/stdc++.h>
using namespace std;
int df[5][5]={{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        char a[1005][1005]={};
        int b[1005][1005]={};
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++)
        {
            string w;
            cin>>w;
            for(int h=1;h<=m;h++)
            {
                a[j][h]=w[h-1];
            }
        }
        int cnt=1;
        while(k--)
        {
            if(a[x+df[d][0]][y+df[d][1]]=='.')
            {
                x+=df[d][0];
                y+=df[d][1];
                if(b[x][y]==0)
                {
                    cnt++;
                    b[x][y]=1;
                }
            }
            else
            {
                d=(d+1)%4;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
