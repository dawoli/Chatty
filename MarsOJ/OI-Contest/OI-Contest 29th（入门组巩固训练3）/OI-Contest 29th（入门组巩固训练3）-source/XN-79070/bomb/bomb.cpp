#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
char a[1005][1005];
bool vis[1005][1005];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool check(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m&&!vis[x][y]&&a[x][y]!='*';
}
int maxnk=0x3f3f3f3f,maxn=0x3f3f3f3f;
int dp1[1005][1005];
struct node{
	int x,y,t,k;
};
queue<node> q;
void bfs(){
	memset(vis,false,sizeof vis);
	q.push({1,1,0,0});
	vis[1][1]=true;
	while(!q.empty()){
		node t=q.front();
		q.pop();
		if(t.x==n&&t.y==m){
			cout<<t.k<<" "<<t.t<<endl;
			break;
		}
		for(int i=0;i<4;i++){
			int dx=t.x+dir[i][0];
			int dy=t.y+dir[i][1];
			if(check(dx,dy)){
				vis[dx][dy]=true;
				q.push({dx,dy,t.t+1,t.k});
			}
		}
	}
}
void dfs(int x,int y,int k,int t){
	if(dp1[x][y]<k){
		return ;
	}
	if(x==n&&y==m){
		if(maxnk>=k){
			maxnk=k;
			maxn=t;
		}
		return ;
	}
	for(int i=0;i<4;i++){
		int dx=x+dir[i][0];
		int dy=y+dir[i][1];
		if(check(dx,dy)){
			dp1[dx][dy]=min(k+(a[dx][dy]=='$'),dp1[dx][dy]);
			vis[dx][dy]=true;
			dfs(dx,dy,k+(a[dx][dy]=='$'),t+1);
			vis[dx][dy]=false;
		}
	}
}
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		bool flag=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				if(a[i][j]=='$'){
					flag=false;
				}
				vis[i][j]=false;
				dp1[i][j]=0x3f3f3f3f;
			}
		}
		if(flag){
			bfs();
			continue;
		}
		vis[1][1]=true;
		dp1[1][1]=1;
		dfs(1,1,0,0);
		cout<<maxnk<<" "<<maxn<<endl;
		maxnk=maxn=0x3f3f3f3f;
	}
	return 0;
}
