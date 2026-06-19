#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

void read(ll &x) {
    x=0;
    char c=getchar();
    while(!('0'<=c && c<='9')) c=getchar();
    while('0'<=c && c<='9') {
        x=x*10+c-'0';
        c=getchar();
    }
}

void read(int &x) {
    x=0;
    char c=getchar();
    while(!('0'<=c && c<='9')) c=getchar();
    while('0'<=c && c<='9') {
        x=x*10+c-'0';
        c=getchar();
    }
}

const int N=1e4+15;
const int M=1e6+5;

ll n, m, k;
pair<ll, pair<int,int>> ed[M];
pair<ll, pair<int,int>> e[M];

ll c[11];
ll a[11][N];



int fa[N];
int sz[N];

int find(int x) {
    if(fa[x]==x) return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
// sort --> merge  (to do)

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    read(n); read(m); read(k);
    for(int i=1;i<=m;i++) {
        read(ed[i].second.first);
        read(ed[i].second.second);
        read(ed[i].first);
    }
    sort(ed+1, ed+m+1);
    for(int i=1;i<=n;i++) fa[i]=i, sz[i]=1;
    int cnt=0, tot=n;
    ll sum=0, ans=0;
    for(int i=1,fu, fv;i<=m;i++) {
        fu=find(ed[i].second.first);
        fv=find(ed[i].second.second);
        if(fu==fv) continue;
        ans+=ed[i].first;
        ed[++cnt]=ed[i];
        if(sz[fu] < sz[fv]) fa[fu]=fv, sz[fv]+=sz[fu];
        else fa[fv]=fu, sz[fu]+=sz[fv];
        --tot;
        if(tot==1) break;
    }
    for(int i=1;i<=k;i++) {
        read(c[i]);
        for(int j=1;j<=n;j++) read(a[i][j]);
    }
    int ct=cnt;
    for(int s=(1<<k)-1;s>0;--s) {
        ct=cnt;
        sum=0;
        memcpy(e, ed, sizeof(pair<ll, pair<int,int>>)*(n+2));
        for(int i=1;i<=n+k;i++) fa[i]=i, sz[i]=1;
        tot=n;
        for(int i=1;i<=k;i++) {
            if(!(s&(1<<(i-1)))) continue;
            sum+=c[i];
            for(int j=1;j<=n;j++) {
                e[++ct]=make_pair(a[i][j], make_pair(n+i, j));
            }
            ++tot;
        }
        sort(e+1, e+ct+1);
        for(int i=1,fu, fv;i<=ct;i++) {
            fu=find(e[i].second.first);
            fv=find(e[i].second.second);
            if(fu==fv) continue;
            sum+=e[i].first;
            if(sz[fu] < sz[fv]) fa[fu]=fv, sz[fv]+=sz[fu];
            else fa[fv]=fu, sz[fu]+=sz[fv];
            --tot;
            if(tot==1) break;
        }
        ans=min(ans, sum);
    }
    cout<<ans;
    return 0;
}