#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==r)
        {
            r=i;
            break;
        }
    }
    if(r<=n)
    {
        cout<<1<<" "<<r;
        return 0;
    }
    if(r%n==0)
    {
        if(r/n%2==0)
        {
            cout<<r/n<<" "<<1;
            return 0;
        }
        else
        {
            cout<<r/n<<" "<<n;
            return 0;
        }
    }
    if(r/n%2==0)
    {
        cout<<r/n+1<<" "<<r%n;
        return 0;
    }
    cout<<r/n+1<<" "<<n-r%n+1;
}
