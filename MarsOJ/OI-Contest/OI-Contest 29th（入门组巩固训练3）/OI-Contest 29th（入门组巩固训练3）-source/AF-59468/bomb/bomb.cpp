#include<iostream>
#include<queue>
#include<fstream>
using namespace std;
pair<int,int> mem[1005][1005];
char mp[1005][1005];
int n,m;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
pair<int,int> dfs(int x,int y){
    if(x==n&&y==m)
        return {0,0};
    if(mem[x][y].second)
        return mem[x][y];
    mem[x][y]={2e9,2e9};
    pair<int,int> tmp;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='*')
            continue;
        pair<int,int> tmp=dfs(nx,ny);
        if(mp[nx][ny]=='.')
            mem[x][y]=min(mem[x][y],{tmp.first,tmp.second+1});
        else
            mem[x][y]=min(mem[x][y],{tmp.first+1,tmp.second+1});
    }
    return mem[x][y];
}
// pair<int,int> bfs(){
//     queue<pair<int,pair<int,int>> q;
//     int l=0;
//     q.push({1,{}})
// }
void solve(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
            mp[i][j]=s[j-1];
    }
    pair<int,int> ans=dfs(1,1);
    printf("%d %d\n",ans.first,ans.second);
    return;
}
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
        solve();
    return 0;
}