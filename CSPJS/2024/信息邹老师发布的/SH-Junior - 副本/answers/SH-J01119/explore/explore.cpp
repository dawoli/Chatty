#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans,maxn[7];
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
bool vis[1002][1002];
char mp[1002][1002];
void dfs(int a,int b,int f,int sum){
	if (sum == k){
		return;
	}
	for (int c=0;c<4;c++){
		if (f == c){
			int nx = a+dx[c];
			int ny = b+dy[c];
			if (nx<1 || nx>n || ny<1 || ny>m || mp[nx][ny] == 'x'){
				f = (f+1)%4;
				dfs(a,b,f,sum+1);
				return;
			}
			if (!(vis[nx][ny])){
				ans++;
			}
			vis[nx][ny] = true;
			dfs(nx,ny,f,sum+1);
			return;
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for (int i=1;i<=t;i++){
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for (int j=1;j<=n;j++){
			for (int s=1;s<=m;s++){
				cin >> mp[j][s]; 
				vis[j][s] = false;
			}
		}
		ans = 1;
		vis[x][y] = true;
		dfs(x,y,d,0);
		maxn[i] = max(maxn[i],ans);
	}
	for (int i=1;i<=t;i++){
		cout << maxn[i] << endl;
	}
	return 0;
}
