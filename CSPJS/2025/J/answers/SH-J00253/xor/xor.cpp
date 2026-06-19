#include<bits/stdc++.h>
using namespace std;
const int M=105e4; int mx[M]; bool vis[M];
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    vis[0]=true;
    int n,k,sum=0,ans=0; cin>>n>>k;
    for(int i=1,a;i<=n;i++) {
        cin>>a,sum^=a;
        if(vis[k^sum]) ans=max(ans,mx[k^sum]+1);
        vis[sum]=true,mx[sum]=max(mx[sum],ans);
        //cout<<sum<<' '<<(k^sum)<<' '<<mx[sum]<<' '<<mx[k^sum]<<' '<<ans<<'\n';
    }
    cout<<ans;
    return 0;
}
