#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
    int w,ix;
}wi[1000005];
struct nt
{
    int v,t;
}nm[10005];
bool cmp(node x,node y)
{
    if(x.w==y.w)
    {
        return x.ix<y.ix;
    }
    return x.w<y.w;
}
bool tmp(nt x,nt y)
{
    if(x.t==y.t)
    {
        return x.v<y.v;
    }
    return x.t<y.t;
}
int main()
{
    freopen("package.in","r",stdin);
    freopen("package.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&wi[i].w);
        wi[i].ix=i;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&nm[i].t,&nm[i].v);
    }
    sort(wi+1,wi+m+1,cmp);
    sort(nm+1,nm+n+1,tmp);
    cout << (n/wi[1].ix)*wi[1].w+wi[m%wi[1].ix].w;
    return 0;
}
