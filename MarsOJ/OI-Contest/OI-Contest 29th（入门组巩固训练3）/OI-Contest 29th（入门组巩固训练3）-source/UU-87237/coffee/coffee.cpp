#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int v[15],t,n,m;
signed main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        int pu=0;
        memset(v,0,sizeof(v));
        for(int i=1;i<=5;i++)
            for(int j=1;j<=8;j++){
                cin>>s;
                if(s[0]=='m')v[i]++,pu++;
            }
        cin>>n>>m;
        int ans=0;
        for(int i=m;i<=5ll;i++)ans+=v[i];
        //cout<<ans<<'\n';
        n-=(7ll-m+1ll);
        for(int i=1;i<=n%7ll;i++)ans+=v[i];
        //cout<<n/7ll*pu<<'\n';
        ans+=(n/7ll*pu);
        cout<<ans<<'\n';
    }
    return 0;
}
