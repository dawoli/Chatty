#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int T,n,m,k,x,y,d0;
char d[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void solve(){
	cin>>n>>m>>k;
	cin>>x>>y>>d0;
	int di=d0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)cin>>d[i][j];
	map<pair<int,int>,int>mp;
	int ans=1;
	mp[{x,y}]=1;
	for(int i=1;i<=k;i++){
		int nx=x+dx[di],ny=y+dy[di];
		if(nx>n||nx<1||ny>m||ny<1||d[nx][ny]=='x'){
			di=(di+1)%4;
			continue;
		}
		x=nx,y=ny;
		if(!mp[{x,y}])ans++;
		mp[{x,y}]++;
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--)solve();
	fclose(stdin);fclose(stdout);
}
