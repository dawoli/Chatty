#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int a[105];
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
    int kk=a[1];
    sort(a+1,a+n+1,cmp);
    int pos;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==kk)
        {
            pos=i;
            break;
        }
    }
    int l=pos/n;
    int s=pos%n;
    if(s==0)
    {
        cout<<l<<" ";
        if(l%2==0)cout<<1;
        else cout<<n-1;
    }
    else
    {
        cout<<l+1<<" ";
        if((l+1)%2==0)cout<<n-s+1;
        else cout<<s;
    }
    return 0;
}
