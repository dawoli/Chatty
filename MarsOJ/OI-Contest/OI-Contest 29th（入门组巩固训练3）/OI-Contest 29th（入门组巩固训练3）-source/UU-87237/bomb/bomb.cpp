#include <bits/stdc++.h>
using namespace std;
int n,m,num,ans,dx[]={0,0,1,-1},dy[]={1,-1,0,0};
char c[1005][1005];
struct node{
    int x,y,st,o;
};
queue<node>q;
int vis[1005][1005][2];
void bfs(){
    while(!q.empty()){
        node t=q.front();q.pop();
        if(t.x==n && t.y==m){
            if(t.o<num)num=t.o,ans=t.st;
            else if(t.o==num)ans=min(ans,t.o);
        }
        for(int i=0;i<4;i++){
            int nx=t.x+dx[i],ny=t.y+dy[i],lp=t.o;
            if(c[nx][ny]=='$')lp++;
            if(nx<1 || nx>n || ny<1 || ny>m || c[nx][ny]=='*')continue;
            if(lp>vis[nx][ny][0])continue;
            if(lp==vis[nx][ny][0] && t.st+1>=vis[nx][ny][1])continue;
            vis[nx][ny][0]=lp,vis[nx][ny][1]=t.st+1;
            q.push({nx,ny,t.st+1,lp});
        }
    }
}
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)cin>>c[i][j];
        while(!q.empty())q.pop();
        memset(vis,0x3f,sizeof(vis));
        vis[1][1][1]=vis[1][1][0]=0,q.push({1,1,0,0});
        num=1e9,ans=1e9;
        bfs();
        cout<<num<<" "<<ans<<'\n';
    }
    return 0;
}
