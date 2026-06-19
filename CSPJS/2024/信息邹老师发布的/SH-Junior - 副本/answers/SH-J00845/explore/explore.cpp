#include<bits/stdc++.h>
using namespace std;
int n,m,T,ans=1;
bool a[1005][1005];
bool vis[1005][1005];
char b;
void dfs(int x,int y,int d,int k){
	while(k>0){
		if(d==0&&y+1<=m){
			if(a[x][y+1]){
				vis[x][y+1]=true;
				dfs(x,y+1,d,k-1);
				break;
			}
		}
		else if(d==1&&x+1<=n){
			if(a[x+1][y]){
				vis[x+1][y]=true;
				dfs(x+1,y,d,k-1);
				break;
			}
		}
		else if(d==2&&y-1>0){
			if(a[x][y-1]){
				vis[x][y-1]=true;
				dfs(x,y-1,d,k-1);
				break;
			}
		}
		else if(d==3&&x-1>0){
			if(a[x-1][y]){
				vis[x-1][y]=true;
				dfs(x-1,y,d,k-1);
				break;
			}
		}
		d=(d+1)%4;
		k--;
	}
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	int x,y,d,k;
	while(T--){
		ans=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				vis[i][j]=false;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>b;
				if(b=='.') a[i][j]=true;
				else a[i][j]=false;
			}
		}
		vis[x][y]=true;
		dfs(x,y,d,k);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
