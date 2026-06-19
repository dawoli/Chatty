#include<bits/stdc++.h>
using namespace std;
int n,m,L,V,T;
int d[100001],v[100001],a[100001],p,cnt;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
{
    cin>>n>>m>>L>>V;
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i]>>v[i]>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>p;
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]<=p){
            if(v[i]>V)cnt++;
        }
    }
    cout<<cnt<<" 1"<<endl;
}
    return 0;
}
