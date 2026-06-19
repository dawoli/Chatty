#include <bits/stdc++.h>
using namespace std;

long long n,m;


struct node
{
    long long shu;
    bool r;
}a[10005];



bool cmp(node a,node b)
{
    return a.shu>b.shu;

}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n*m;i++)
    {
        cin>>a[i].shu;
    }
    a[1].r=1;
    sort(a+1,a+1+n*m,cmp);
    long long ans_lie=0,ans_hang=0,ans=0;
    for(int i = 1;i<=n*m;i++)
    {
        if(a[i].r==1)ans=i;
    }
    if(ans%n==0)ans_lie=ans/n;
    else ans_lie=ans/n+1;
    ans_hang=ans%(2*n);
    if(ans_hang>n)ans_hang=n+1-ans_hang%n;
    else if(ans_hang==0)ans_hang++;
    cout<<ans_lie<<' '<<ans_hang;


    return 0;
}
