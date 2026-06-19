#include<bits/stdc++.h>
#define int long long
using namespace std;
int q,n,sq,ans=0;
signed main()
{
    cin>>q;
    while (q--)
    {
        ans=0;
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            if (i%(int)floor(sqrt(i))==0)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}