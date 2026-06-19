#include<bits/stdc++.h>
using namespace std;

int a[105];

bool cmp(int x,int y)
{
    return x>y;
}


int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,t;
    cin>>n>>m;
    for(int i = 1;i <= n*m;i++) cin>>a[i];
    t=a[1];
    sort(a+1,a+(n*m)+1,cmp);

    int l;

    for(int i = 1;i <= m*n;i++)
    {
        if(a[i]==t) l=i;
    }
    if((l-1)/n%2==1)
    {
        int i=(l-1)/n+1;
        int j=i*n-l+1;
        cout<<i<<" "<<j;
    }
    else
    {
        int i=(l-1)/n+1;
        int j=l-(i-1)*n;
        cout<<i<<" "<<j;
    }
    return 0;
}
