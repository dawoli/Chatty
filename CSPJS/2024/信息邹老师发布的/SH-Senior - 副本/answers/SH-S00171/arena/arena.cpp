#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
pair<int,int> c[100005];
int K=0;
int tot;
int ls[500005];
int rs[500005];
int ff[500005];
int d[500005];
int tim[500005];
int winner[500005];
int dep[500005];
void build(int x){
    if(x<=(1<<K)){
        tim[x]=x;
        winner[x]=x;
        return ;
    }
    build(ls[x]);build(rs[x]);
    if(d[x]==0){
        int vl=a[winner[ls[x]]];
        if(vl>=dep[x]){
            tim[x]=tim[ls[x]];
            winner[x]=winner[ls[x]];
        }else{
            tim[x]=tim[rs[x]];
            winner[x]=winner[rs[x]];
        }
    }else{
        int vl=a[winner[rs[x]]];
        tim[x]=tim[rs[x]];
        winner[x]=vl>=dep[x]?winner[rs[x]]:winner[ls[x]];
    }
    return ;
}
int X[4];
int res[100005];
int CURRENT;
int dfs(int l,int r,int x,int lim){
    if(tim[x]<=CURRENT)return a[winner[x]]>=lim?winner[x]:0;
    if(l>CURRENT)return (l+r)*(r-l+1)/2;
    if(x<=(1<<K))return x;
    int mid=(l+r)>>1;
    if(d[x]==0){
        if(tim[ls[x]]<=CURRENT)return dfs(mid+1,r,rs[x],lim);
        return dfs(l,mid,ls[x],lim?:dep[x])+dfs(mid+1,r,rs[x],lim);
    }else{
        return dfs(l,mid,ls[x],lim)+dfs(mid+1,r,rs[x],lim?:dep[x]);
    }
}
mt19937 rd(time(0));
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        cin>>c[i].first;
        c[i].second=i;
    }
    sort(c+1,c+m+1);
    while((1<<K)<n)K++;
    tot=(1<<K);
    vector<int> cur;
    for(int i=1;i<=(1<<K);i++)cur.push_back(i);
    for(int i=1;i<=K;i++){
        vector<int> nw;
        for(int j=0;j<cur.size();j+=2){
            tot++;nw.push_back(tot);
            ls[tot]=cur[j];rs[tot]=cur[j+1];ff[cur[j]]=ff[cur[j+1]]=tot;
            char ch;cin>>ch;d[tot]=ch-'0';dep[tot]=i;
        }
        cur=nw;
    }
    ff[0]=1;
    int T;cin>>T;
    while(T--){
        cin>>X[0]>>X[1]>>X[2]>>X[3];
        for(int i=1;i<=n;i++){
            a[i]^=X[i&3];
        }
        build(tot);
        int root=0;
        int ptr=1;int rg=0;
        for(int i=1;i<=n;i++){
            CURRENT=i;
            if(i==1 or __builtin_popcountll(i-1)==1){
                root=ff[root];
                if(rg==0)rg=1;
                else rg<<=1;
            }
            while(ptr<=m and c[ptr].first==i){
                res[c[ptr].second]=dfs(1,rg,root,0);
                ptr++;
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++)ans^=i*res[i];
        cout<<ans<<endl;
        for(int i=1;i<=n;i++){
            a[i]^=X[i&3];
        }
    }
    return 0;
}
