#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+13;
struct node{
    int px,py,step,bcnt;
    bool operator<(const node &a) const{
        if(bcnt!=a.bcnt) return bcnt>a.bcnt;
        return step>a.step;
    }
};
int t,n,m;
int mx[]={0,1,-1,0,0};
int my[]={0,0,0,1,-1};
int dist[MAXN][MAXN],box[MAXN][MAXN];
char a[MAXN][MAXN];
bool vis[MAXN][MAXN];
priority_queue<node> pq;
inline void bfs(){
    int x,y,q,p,r;
    dist[1][1]=box[1][1]=0;
    pq.push({1,1,0,0});
    while(!pq.empty()){
        x=pq.top().px;
        y=pq.top().py;
        pq.pop();
        if(vis[x][y]) continue;
        vis[x][y]=true;
        for(int i=1;i<=4;i++){
            q=x+mx[i],p=y+my[i];
            if(q<1||p<1||q>n||p>m||a[q][p]=='*') continue;
            if(a[q][p]=='$') r=box[x][y]+1;
            else r=box[x][y];
            if(r<box[q][p]){
                box[q][p]=r;
                dist[q][p]=dist[x][y]+1;
                pq.push({q,p,dist[q][p],r});
            }
            else if(r==box[q][p]&&dist[x][y]+1<dist[q][p]){
                dist[q][p]=dist[x][y]+1;
                pq.push({q,p,dist[q][p],r});
            }
        }
    }
    return;
}
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    cin>>t;
    while(t--){
		memset(dist,0x3f,sizeof(dist));
		memset(box,0x3f,sizeof(box));
		memset(vis,false,sizeof(vis));
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i]+1;
        bfs();
        cout<<box[n][m]<<' '<<dist[n][m]<<'\n';

    }
    return 0;
}
