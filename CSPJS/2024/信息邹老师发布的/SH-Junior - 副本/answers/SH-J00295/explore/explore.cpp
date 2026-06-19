#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
int T,n,m,k,x,y,d;
bool a[N][N],vis[N][N];
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
string s;
void solve(){
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			if(s[j]=='x') a[i][j+1]=1;
			else a[i][j+1]=0;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) vis[i][j]=0;
	vis[x][y]=1;
	for(int i=1;i<=k;i++){
		int xx=x+dirx[d],yy=y+diry[d];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!a[xx][yy]){
			x=xx;y=yy;
			vis[x][y]=1;
		}
		else d=(d+1)%4;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(vis[i][j]) ans++;
	cout<<ans<<'\n';
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
} 
