#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
    int T,n;
    void Soar()
    {
		vector<int> a(n+1,0),c(n+1,0);
        int ans=0,tag=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        c[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            c[i] = c[i - 1] + a[i];
        }
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,(int)count(c.begin()+i,c.end(),tag));
            tag+=a[i];
        }
        cout<<ans<<endl;
    }
    void solve()
    {
        cin>>T;
        while(T--)
        {
            cin>>n;
            Soar();
        }
    }
}
int main()
{
    //freopen("trip4.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    Soaring_Wings::solve();
}
