#include<iostream>
#include<fstream>
using namespace std;
char mp[1005][1005];
bool vis[1005][1005];
int n,m,k,x,y,d,ans,nx,ny;
string tmp;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void solve(){
    cin>>n>>m>>k>>x>>y>>d;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        for(int j=1;j<=m;j++){
            mp[i][j]=tmp[j-1];
            vis[i][j]=0;
        }
    }
    ans=0;
    k++;
    while(k--){
        if(!vis[x][y])
            ans++;
        vis[x][y]=1;
        nx=x+dx[d];
        ny=y+dy[d];
        if(!(nx<1||nx>n||ny<1||ny>m)&&mp[nx][ny]=='.'){
            x=nx;
            y=ny;
        }
        else
            d=(d+1)%4;
    }
    cout<<ans<<"\n";
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}