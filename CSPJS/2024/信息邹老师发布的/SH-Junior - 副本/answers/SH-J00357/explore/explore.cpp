#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e3+9;
ll dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
ll T,n,m,k,x,y,d;
char mp[N][N];
ll dir[N][N];
bool vis[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
				vis[i][j]=0;
				dir[i][j]=-1;
			}
		ll ans=1;
		vis[x][y]=1;
		dir[x][y]=d;
		while(k--){
			ll nx=x+dx[d],ny=y+dy[d];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.'){
				x=nx; y=ny;
				if(dir[x][y]==d)
					break;
				dir[x][y]=d;
				if(!vis[x][y]){
					ans++;
					vis[x][y]=1;
				}
			}
			else{
				d++;
				if(d==4) d=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

