#include<bits/stdc++.h>
using namespace std;
int T;//5
int n,m,k,stx,sty,stf,tpa;//1005,1005,1000005
char mp[1005][1005][5];
bool vis[1005][1005][5];
void dfs(int x,int y,int f,int l){
	if(l==k) return;
	l++;
	//cout<<x<<' '<<y<<' '<<f<<endl;
	
	if(vis[x][y][T]==0){
		//cout<<x<<' '<<y<<' '<<T<<endl;
		vis[x][y][T]=1;
		//cout<<vis[x][y][T]<<endl;
		/*for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) cout<<i<<' '<<j<<' '<<T<<endl;    //cout<<vis[n][m][T];
			cout<<endl;
		}*/
		tpa++;
	}
	if(f==0) {
		if(mp[x+1][y][T]=='.') return dfs(x+1,y,f,l);
		else return dfs(x,y,f+1,l);
	}
	if(f==1) {
		if(mp[x][y-1][T]=='.') return dfs(x,y+1,f,l);
		else return dfs(x,y,f+1,l);
	}
	if(f==2) {
		if(mp[x-1][y][T]=='.') return dfs(x-1,y,f,l);
		else return dfs(x,y,f+1,l);
	}
	if(f==3) {
		if(mp[x][y+1][T]=='.') return dfs(x,y-1,f,l);
		else return dfs(x,y,0,l);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	T--;
	for(T;T>-1;T--){
		tpa=0;
		cin>>n>>m>>k>>stx>>sty>>stf;
		for(int i=1;i<=n;i++) mp[0][i][T]='x';
		for(int i=1;i<=m;i++) mp[i][0][T]='x';
		for(int i=1;i<=n;i++) mp[m+1][i][T]='x';
		for(int i=1;i<=m;i++) mp[i][n+1][T]='x';
		
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>mp[i][j][T];
		
		dfs(stx,sty,stf,0);
		/*for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) cout<<vis[n][m][T];
			cout<<endl;
		}*/
		cout<<tpa<<endl;
	}
	return 0;
} 
