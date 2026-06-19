#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005];
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+3);
    if(n==3)
    {
        if(a[0]+a[1]>a[2])
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else
    {
        cout<<n*(n-1);
    }

    return 0;
}
