#include<bits/stdc++.h>
using namespace std;
bool vis[4][14];
char a[52][2];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        int index;
        if(a[i][0]=='D')
        {
            index=0;
        }
        if(a[i][0]=='C')
        {

            index=1;
        }
        if(a[i][0]=='H')
        {
            index=2;
        }
        if(a[i][0]=='S')
        {
            index=3;
        }
        if(a[i][1]>='2'&&a[i][1]<='9')
        {
            vis[index][a[i][1]-48]=1;
        }
        if(a[i][1]=='A')
        {
            vis[index][1]=1;
        }
        if(a[i][1]=='T')
        {
            vis[index][10]=1;
        }
        if(a[i][1]=='J')
        {
            vis[index][11]=1;
        }
        if(a[i][1]=='Q')
        {
            vis[index][12]=1;
        }
        if(a[i][1]=='K')
        {
            vis[index][13]=1;
        }
    }
    int res=0;
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(vis[i][j]==0)
            {
                res++;
            }
        }
    }
    cout<<res;
    return 0;
}
