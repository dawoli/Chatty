#include <bits/stdc++.h>
using namespace std;
char mp[1010][1010];
bool vis[1010][1010];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,m,k,t,rx,ry,rd;
struct node{
	int x,y,d;
};
int bfs(){
	memset(vis,0,sizeof(vis));
	int ans=0;
	node p={rx,ry,rd};
	if(vis[p.x][p.y]==0){
			ans+=1;
			vis[p.x][p.y]=1;
		}
	for(int i=0;i<k;i++){
		int px=p.x+dir[p.d][0],py=p.y+dir[p.d][1];
		if(px>=1 && px<=n && py>=1 && py<=m && mp[px][py]=='.'){
			p={px,py,p.d};
		}
		else p={p.x,p.y,(p.d+1)%4};
		if(vis[p.x][p.y]==0){
			ans+=1;
			vis[p.x][p.y]=1;
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int ii=0;ii<t;ii++){
		cin>>n>>m>>k;
		cin>>rx>>ry>>rd;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[i][j];
		cout<<bfs()<<"\n";
	}
	return 0;
}
