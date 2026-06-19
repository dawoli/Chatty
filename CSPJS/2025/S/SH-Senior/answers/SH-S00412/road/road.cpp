// 15:45 Start coding.
// 16:32 End coding & Segmentation fault.
// 16:49 I think the sample is incorrect.
// 16:53 I am incorrect.
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
pair<ll,pair<ll,ll> > to[1000009];
pair<ll,pair<ll,ll> > tt[13][1000009];
pair<ll,pair<ll,ll> > tmp1[2000009],tmp2[2000009], asn[2000009];
ll q[1009];
ll c[20];
bool use658[20];
ll ans = 0x3f3f3f3f3f3f3f3f;
ll fa[10009];
ll root(ll x) {
    if(fa[x] == x) return x;
    return fa[x] = root(fa[x]);
}
bool unite(ll x,ll y) {
    x = root(x), y = root(y);
    if(x==y) return false;
    fa[x] = y;
    return true;
}
void dfs(ll x) {
    if(x == k + 1) {
        ll san = 0;
        ll nn = 0;
        bool flag = 1;
        for(int i=1;i<=k;i++) {
            if(use658[i]) {
                san += c[i];
                if(flag == 1) {
                    if(nn) merge(tmp2+1,tmp2+nn+1,tt[i]+1,tt[i]+n+1,tmp1+1);
                    else {
                        for(int j=1;j<=n;j++) {
                            tmp1[j] = tt[i][j];
                        }
                    }
                    nn+=n;
                } else {
                    if(nn) merge(tmp1+1,tmp1+nn+1,tt[i]+1,tt[i]+n+1,tmp2+1);
                    else {
                        for(int j=1;j<=n;j++) {
                            tmp2[j] = tt[i][j];
                        }
                    }
                    nn+=n;
                }
                flag = !flag;
            }
        }
        if(flag == 1) {
            if(nn) merge(tmp2+1,tmp2+nn+1,to+1,to+m+1,asn+1);
            else {
                for(int j=1;j<=m;j++) {
                    asn[j] = to[j];
                }
            }
            nn+=m;
        } else {
            if(nn) merge(tmp1+1,tmp1+nn+1,to+1,to+m+1,asn+1);
            else {
                for(int j=1;j<=m;j++) {
                    asn[j] = to[j];
                }
            }
            nn+=m;
        }
        for(int i=1;i<=n;i++) fa[i] = i;
        for(int i=1;i<=nn;i++) {
            ll w = asn[i].first, u = asn[i].second.first, v = asn[i].second.second;
            if(unite(u,v)) {
                //cout<<use658[1]<<use658[2]<<" "<<san<<" "<<u<<" "<<v<<" "<<w<<endl;
                san += w;
            }
        }
        ans = min(ans,san);
        return;
    }
    use658[x]=true;
    dfs(x+1);
    use658[x]=false;
    dfs(x+1);
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld %lld %lld",&n,&m,&k);
    for(int i=1;i<=m;i++) {
        ll u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        to[i] = make_pair(w,make_pair(u,v));
    }
    sort(to+1,to+m+1);
    bool flag = true;
    if(k == 0) flag = false;
    for(int i=1;i<=k;i++) {
        scanf("%lld",&c[i]);
        if(c[i]!=0) flag = false;
        for(int j=1;j<=n;j++) {
            scanf("%lld",&q[j]);
            //tt[i][j]=make_pair(p,make_pair(i,j));
            if(q[j]!=0) flag = false;
        }
        ll ttt = i;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                tt[ttt][(i-1)*n+j]=make_pair(q[i]+q[j],make_pair(i,j));
            }
        }
        sort(tt[i]+1,tt[i]+n+1);
    }
    if(flag) {
        printf("0");
        return 0;
    }
    dfs(1);
    printf("%lld",ans);
    return 0;
}
