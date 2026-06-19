#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x0,y0,d0,ans;
char mp[1005][1005];
bool vis[1005][1005];
bool check(int x1,int y1){
	if(x1>n||x1<1||y1>m||y1<1) return false;
	if(mp[x1][y1]=='x') return false;
	return true;
}
void dfs(int x,int y,int d,int q){
	if(q==k) return;
	if(d==0){
		if(check(x,y+1)==true){
			if(vis[x][y+1]==false) ans++;
			vis[x][y+1] = true;
			dfs(x,y+1,d,q+1);
		}
		else dfs(x,y,(d+1)%4,q+1);
	}
	if(d==1){
		if(check(x+1,y)==true){
			if(vis[x+1][y]==false) ans++;
			vis[x+1][y] = true;
			dfs(x+1,y,d,q+1);
		}
		else dfs(x,y,(d+1)%4,q+1);
	}
	if(d==2){
		if(check(x,y-1)==true){
			if(vis[x][y-1]==false) ans++;
			vis[x][y-1] = true;
			dfs(x,y-1,d,q+1);
		}
		else dfs(x,y,(d+1)%4,q+1);
	}
	if(d==3){
		if(check(x-1,y)==true){
			if(vis[x-1][y]==false) ans++;
			vis[x-1][y] = true;
			dfs(x-1,y,d,q+1);
		}
		else dfs(x,y,(d+1)%4,q+1);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	while(t--){
		ans = 1;
		memset(vis,false,sizeof(vis));
		cin >> n >> m >> k >> x0 >> y0 >> d0;
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=m;j++) cin >> mp[i][j];
		dfs(x0,y0,d0,0);
		cout << ans << endl;
	}
	return 0;
}
