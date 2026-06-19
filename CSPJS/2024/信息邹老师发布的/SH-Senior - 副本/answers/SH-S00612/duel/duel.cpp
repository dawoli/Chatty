#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f

const int maxn=1e5+5;

int a[maxn];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    memset(a,0,sizeof(a));
    int n;
    int t;
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++) {
        cin>>t;
        mx=max(mx,t);
        a[t]++;
    }
    int ans=0;
    for(int i=1;i<=mx;i++) {
        ans=max(0, ans-a[i]);
        ans+=a[i];
    }
    cout<<ans;
    return 0;
}