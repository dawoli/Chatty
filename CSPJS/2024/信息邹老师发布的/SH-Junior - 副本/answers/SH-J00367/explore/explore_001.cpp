#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d;
bool vis[1009][1009][7];
char mp[1009][1009];
void solve() {
	int ans=0;
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>mp[i][j];
			for(int o=0;o<=3;o++) vis[i][j][o]=false;
		}
	} 
	for(int i=0;i<=k;i++) {
		if(vis[x][y][d]) {
			cout<<ans<<endl;
			return ;
		}
		bool f=true;
		for(int j=0;j<=3;j++) if(vis[x][y][j]==true) f=false;
		if(f==true) {
			ans++;
		}
		vis[x][y][d]=true;
		if(d==0) {
			if(y+1>m||mp[x][y+1]=='x') d=1;
			else y=y+1;
		}
		else if(d==1) {
			if(x+1>n||mp[x+1][y]=='x') d=2;
			else x=x+1;
		}
		else if(d==2){
			if(y-1<1||mp[x][y-1]=='x') d=3;
			else y=y-1;
		}
		else {
			if(x-1<1||mp[x-1][y]=='x') d=0;
			else x=x-1;
		}
	}
	cout<<ans<<endl;
}
int main(){ 
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		solve();
	}
	return 0; 
}
