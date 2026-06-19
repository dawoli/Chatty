#include <bits/stdc++.h>
using namespace std;
const int N=1e3+9;
long long T,ans;
long long n,m,k,x,y,d;
char s[N][N];
int vis[N][N];
int dx[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dfs(int x,int y,int step){
	if(step==k){
		return ans;
	}
	int xx=x+dx[d][0];
	int yy=y+dx[d][1];
	if(xx<1 || xx>n || yy<1 || yy>m || s[xx][yy]=='x') {
		d=(d+1)%4;
		dfs(x,y,step+1);
	}
	else{
		if(vis[xx][yy]==0) {
			ans++;
		}
		vis[xx][yy]=1;
		dfs(xx,yy,step+1);		
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);	
	cin>>T;
	while(T--){
		ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cin>>s[i][j];
		}	
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++) vis[i][j]=0;
		}	
		cout<<dfs(x,y,0)<<endl;
	}
}
