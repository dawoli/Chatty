#include<bits/stdc++.h>
using namespace std;
struct point{
    int a,b;
};
queue<point> q;
char a[1005][1005];
int vis[1005][1005],step[1005][1005];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    int T;cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        while(!q.empty()) q.pop();
        memset(vis,0,sizeof(vis));
        q.push({1,1});vis[1][1]=1;step[1][1]=0;
        while(!q.empty()){
            point x=q.front();q.pop();
            if(x.a==n&&x.b==m){
                cout<<0<<' '<<step[n][m]<<endl;
                break;
            }
            for(int i=0;i<4;i++){
                int tx=x.a+dx[i],ty=x.b+dy[i];
                if(tx<1||tx>n||ty<1||ty>m||a[tx][ty]=='*') continue;
                q.push({tx,ty});vis[tx][ty]=1;step[tx][ty]=step[x.a][x.b]+1;
            }
        }
    }
    return 0;
}
