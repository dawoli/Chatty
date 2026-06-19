#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,stp;
};
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int t,n,m,cnt=0;
bool vis[1001][1001];
string s[1001];
int bfs(){
    queue<node> q;
    q.push({0,0,0});
    vis[0][0]=1;
    while(!q.empty()){
        node t=q.front();
        q.pop();
        if(t.x==n-1 && t.y==m-1)
            return t.stp;
        for(int i=0;i<4;i++){
            int nx=t.x+dir[i][0];
            int ny=t.y+dir[i][1];
            if(0<=nx && 0<=ny && nx<=n && ny<=m && !vis[nx][ny]){
                q.push({nx,ny,t.stp+1});
                vis[nx][ny]=1;
            }
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    cin>>t;
    while(t--){
        cnt=0;
        memset(vis,0,sizeof(vis));
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>s[i];
            for(int j=0;j<m;j++)
                if(s[i][j]=='$')
                    cnt++;
        }
        if(n==1)
            cout<<cnt<<' '<<m-1;
        else{
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(s[i][j]=='*')
                        vis[i][j]=1;
            cout<<"0 "<<bfs();
        }
        cout<<endl;
    }
    return 0;
}
