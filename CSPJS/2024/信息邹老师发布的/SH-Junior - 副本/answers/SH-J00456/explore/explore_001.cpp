#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
int n = 0,m = 0,k = 0,x = 0,y = 0,d = 0;
        //int n,m,k;
ll g[100010][100010];
ll viss[103][103];
//ll viss[1002][1002] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//int di[4] = {0,1,2,3};
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int dfs(int x,int y){
    ll viss[103][103];
    int fg = 0;
    viss[x][y] = true;
    for(int i = 0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(g[nx][ny] == 1 && viss[nx][ny] == 0){
            viss[nx][ny] = 1;
            dfs(nx,ny);
        }
        else fg++;
    }
    if(fg == 4){
        return 0;
    }
    else{
        ll cnt = 0;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                if(viss[i][j] == true){
                    cnt++;
                    viss[i][j] == 0;
                }
        return cnt;
    }
}
/*
void dfs2(int x,int y){

    int fg = 0;
    vis[x][y] = true;
    for(int i = 0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(G[nx][ny] == 1 && vis[nx][ny] == 0){
            vis[nx][ny] = true;
            dfs(nx,ny);
        }
        else fg++;
    }
    if(fg == 4){
        return;
    }
}*/
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int eve = 1;eve<=T;eve++){
        //viss[1002][1002] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


        cin>>n>>m>>k;
        //int x,y,d;
        cin>>x>>y>>d;
        for(ll i = 1;i<=n;i++){
            for(ll j = 1;j<=m;j++){
                char a;cin>>a;
                if(a == '.') g[i][j] = 1;
                else if(a=='x') g[i][j] = 0;

            }
        }


        cout<<dfs(x,y)<<"\n";

    }

    return 0;
}
