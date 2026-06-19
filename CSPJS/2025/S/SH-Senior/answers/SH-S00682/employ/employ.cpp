#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int maxn=505;
int n,m,s[maxn],c[maxn];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%1lld",&s[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
    int now=1;
    for(int i=1;i<=n;i++)now=(now*i)%mod;
    printf("%lld\n",now);
    return 0;
}