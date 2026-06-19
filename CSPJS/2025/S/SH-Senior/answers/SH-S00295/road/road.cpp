#include<bits/stdc++.h>
using namespace std;
inline int read(){
    char c=getchar_unlocked();
    int f=0;
    while(!isdigit(c))c=getchar_unlocked();
    while(isdigit(c))f=f*10+c-'0',c=getchar_unlocked();
    return f;
}
struct edge{
    int v,w;
};
vector<edge>e[11000];
struct ke{
    int u,v,w;
    bool operator<(const ke &x)const{
        return w<x.w;
    }
}ed[1000005];
struct DSU{
    vector<int>pa,siz;
    explicit DSU(int s):pa(s),siz(s){
        iota(pa.begin(),pa.end(),0);
        for(auto &i:siz)i=1;
    }
    int find(int x){
        return pa[x]==x?x:pa[x]=find(pa[x]);
    }
    void unite(int x,int y){
        int tmpx=find(x),tmpy=find(y);
        if(siz[tmpx]<siz[tmpy]){
            siz[tmpy]+=siz[tmpx];
            pa[tmpx]=tmpy;
        }
        else{
            siz[tmpx]+=siz[tmpy];
            pa[tmpy]=tmpx;
        }
    }
}D(11000);
vector<ke>mst;
struct cted{
    int v,w;
    bool operator<(const cted &x)const{
        return w<x.w;
    }
}a[11][10005];
//int a[11][10005];
int c[15];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),w=read();
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        ed[i]={u,v,w};
    }
    for(int i=1;i<=k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++){
            int w=read();
            a[i][j]={j,w};
            //a[i][j]=read();
        }
        sort(a[i]+1,a[i]+n+1);
    }
    if(k==0){
        sort(ed+1,ed+m+1);
        int cnt=0;
        long long cost=0;
        for(int i=1;i<=m;i++){
            int u=ed[i].u,v=ed[i].v,w=ed[i].w;
            if(D.find(u)==D.find(v))continue;
            D.unite(u,v);
            cost+=w;
            cnt++;
            if(cnt==n)break;
        }
        printf("%lld\n",cost);
    }
    else{
        sort(ed+1,ed+m+1);
        int cnt=0;
        long long cost=0;
        for(int i=1;i<=m;i++){
            int u=ed[i].u,v=ed[i].v,w=ed[i].w;
            if(D.find(u)==D.find(v))continue;
            D.unite(u,v);
            cost+=w;
            cnt++;
            mst.push_back(ed[i]);
            if(cnt==n)break;
        }
        sort(mst.begin(),mst.end());
        int lim=1<<k;
        for(int i=1;i<lim;i++){
            //int vis[11][10005]={0};
            int cnt[11]={0},avail[11]={0};
            int tmp=i;
            long long costt=0;
            int extra=0;
            for(int j=1;j<=k;j++){
                if(tmp&1)costt+=c[j],avail[j]=1,extra++,cnt[j]=1;
                tmp>>=1;
            }
            DSU Dt(11000);
            //int vis[11005]={0};
            int cntt=0;
            for(int j=1;j<n+extra;j++){
                int u=0,v=0,w=1e9;
                if(cnt[0]<n-1)
                    u=mst[cnt[0]].u,v=mst[cnt[0]].v,w=mst[cnt[0]].w,cnt[0]++;
                while(Dt.find(u)==Dt.find(v)&&cnt[0]<n-1){
                    u=mst[cnt[0]].u,v=mst[cnt[0]].v,w=mst[cnt[0]].w,cnt[0]++;
                }
                if(Dt.find(u)==Dt.find(v))u=0,v=0,w=1e9;
                //cout<<"!"<<u<<" "<<v<<<" "<<w<<endl;
                for(int p=1;p<=k;p++){
                    if(avail[p]&&cnt[p]<=n){
                        int tu=10000+p,tv=a[p][cnt[p]].v,tw=a[p][cnt[p]].w;
                        cnt[p]++;
                        while(Dt.find(tu)==Dt.find(tv)&&cnt[p]<=n){
                            tu=10000+p,tv=a[p][cnt[p]].v,tw=a[p][cnt[p]].w,cnt[p]++;
                        }
                        if(Dt.find(tu)!=Dt.find(tv)){
                            if(tw<w){
                                if(u!=0){
                                    if(u<10000)cnt[0]--;
                                    else cnt[u-10000]--;
                                }
                                u=tu,v=tv,w=tw;
                            }
                            else{
                                cnt[tu-10000]--;
                            }
                        }
                    }
                }
                /*cout<<u<<" "<<v<<"\n";
                if(u==0&&v==0){
                    cout<<cnt[0]<<"\n";
                    cout<<cnt[1]<<"\n";
                }*/
                //vis[u]=1,vis[v]=1;
                Dt.unite(u,v);
                costt+=w;
                if(!(u==0&&v==0))
                cntt++;
            }
            //cout<<"cnt="<<cntt<<" "<<n+extra<<endl;
            //for(int j=1;j<=n;j++)
            //if(vis[j]==0)cout<<j<<"! ";
            //cout<<endl;
            //cout<<costt<<endl<<endl;
            cost=min(cost,costt);
        }
        printf("%lld\n",cost);
    }
    return 0;
}
//g++ -O2 -std=c++14 -static road.cpp -Wall -o road
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/