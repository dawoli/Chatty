#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
int dp[1005][1005][2],b[1005][1005];//dp[i][j][0]表示步数，dp[i][j][1]表示要炸的 
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				cin>>a[i][j];
				dp[i][j][0]=dp[i][j][1]=vis[i][j]=b[i][j]=0;
			}
		}
		dp[1][1][0]=0;
		dp[1][1][1]=0;
		for(int j=2; j<=m; j++){
			if(a[1][j]=='*'){dp[1][j][0]=dp[1][j][1]=0x3f3f3f3f;continue;}
			if(dp[1][j-1][0]==0x3f3f3f3f){
				dp[1][j][0]=dp[1][j][1]=0x3f3f3f3f;
				continue;
			}
			dp[1][j][0]=dp[1][j-1][0]+1;
			dp[1][j][1]=dp[1][j-1][1]+(a[1][j]=='$');
		} 
		for(int j=2; j<=n; j++){
			if(a[j][1]=='*'){dp[j][1][0]=dp[j][1][1]=0x3f3f3f3f;continue;}
			if(dp[j-1][1][0]==0x3f3f3f3f){
				dp[j][1][0]=dp[j][1][1]=0x3f3f3f3f;
				continue;
			}
			dp[j][1][0]=dp[j-1][1][0]+1;
			dp[j][1][1]=dp[j-1][1][1]+(a[j][1]=='$');
		}
		int dx[]={0,1,0,-1};
		int dy[]={1,0,-1,0};
		queue<int> p,q;
		p.push(1);
		q.push(1);
		vis[1][1]=1;
		while(!p.empty()){
			if(vis[n][m]==1){
				break;
			}
			int x=p.front(),y=q.front();
			p.pop();
			q.pop();
			for(int i=0;i<4;i++){
				int xx=x+dx[i],yy=dy[i]+y;
				if(xx>=1&&xx<=n&&yy>=1&&yy<=m){
					if(vis[xx][yy]==0&&a[xx][yy]=='.'){
						vis[xx][yy]=1;
						b[xx][yy]=b[x][y]+1;
						p.push(xx);
						q.push(yy);
					}
				}
			}
		}
		if(n==1||m==1) cout<<dp[n][m][1]<<" "<<dp[n][m][0]<<"\n";
		else cout<<b[n][m]<<"\n";
	} 
	return 0;
}

