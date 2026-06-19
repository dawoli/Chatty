#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=1e20;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
    }
    for(int i=1;i<=k;i++)
    {
        long long d,e[10009],ans1=0;
        cin>>d;
        ans1+=d;
        for(int j=1;j<=n;j++)
        {
            cin>>e[j];
            ans1+=e[j];
        }
        ans=min(ans,ans1);
    }
    cout<<ans<<endl;
}
//你好，我是洛谷网红Nephren(uid=1436750)
//当你看到我写的话时，我差不多快退役了
//今年我T1都没写出来，真是废物呢，呵呵
//不过，我永远喜欢我的npyCute_Furina
//退役，回归whk吧 
