#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    vector<int> inv;
    int n,p;
    cin>>n>>p;
    inv.resize(n+1);
    inv[1]=1;
    for (int i=2;i<=n;i++)
    {
        inv[i]=(p-inv[p%i]*(p/i)%p);
    }
    for (int i=1;i<=n;i++)
    {
        cout<<inv[i]<<'\n';
    }
    cout<<flush;
    return 0;
}