#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t,n,a[200010],b[1000010],pre[200010];
long long ans,f[200010];
int main() {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while (t--) {
        cin>>n;
        ans=0;
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++) {
            cin>>a[i];
            pre[i]=b[a[i]];
            if (i>1&&pre[i]==i-1) ans+=a[i];
            b[a[i]]=i;
        }
        f[1]=0;
        for (int i=3;i<=n;i++) {
            if (pre[i]&&pre[i]<i-1) f[i-1]=max(f[i-2],f[pre[i]]+a[i]);
            else f[i-1]=f[i-2];
        }
        cout<<f[n-1]+ans<<endl;
    }
}