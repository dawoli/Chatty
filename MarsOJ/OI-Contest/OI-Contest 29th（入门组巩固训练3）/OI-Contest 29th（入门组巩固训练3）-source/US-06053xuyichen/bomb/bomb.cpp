#include <bits/stdc++.h>
using namespace std;
char mp[1010][1010];
int n,m;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int box=10000000,step;
int vis[1005][1005];
int vis2[1005][1005];
struct node{
	int x,y,b,s;
};
int bfs(){
	queue<node>q;
	q.push({1,1,0,0});
	vis[1][1]=0;
	while(q.size()){
		node p=q.front();
		q.pop();
		vis[p.x][p.y]=p.s;
		vis2[p.x][p.y]=p.b;
		if(p.x==n&&p.y==m){
			if(p.b<box){
				box=p.b;
				step=p.s;
			}
			else if(p.b==box){
				step=min(p.s,step);
			}
			continue;
		}
		for(int i=0;i<4;i++){
			int px=p.x+dir[i][0];
			int py=p.y+dir[i][1];
			if(px>=1 && px<=n && py>=1 && py<=m && ((p.b==vis2[px][py] && p.s<vis[px][py]) || vis[px][py]==0 || p.b<vis2[px][py])){
				if(mp[px][py]=='.')
					q.push({px,py,p.b,p.s+1});
				else if(mp[px][py]=='$'){
					q.push({px,py,p.b+1,p.s+1});
				}
				else{
					continue;
				}
				
			}
		}
	}
	return 0; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	int t;
	cin>>t;
	for(int ii=0;ii<t;ii++){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		bfs();
		cout<<box<<' '<<step<<"\n"; 
		memset(vis,0,sizeof(vis));
	}
	
} 
