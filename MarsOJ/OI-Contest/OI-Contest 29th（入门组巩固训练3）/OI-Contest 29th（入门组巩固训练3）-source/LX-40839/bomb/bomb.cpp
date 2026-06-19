#include<bits/stdc++.h>
using namespace std;
int n,m,ans,ans2;
char a[1005][1005];
int s;
int mv[4][2]={{0,1},
			 {0,-1},
			 {1,0},
			 {-1,0}};
bool vis[1005][1005];
int dis[1005][1005];
struct node{
	int x,y;
};
void bfs(int mid){
	queue<node> q;
	node t;
	t.x=1,t.y=1;
	vis[1][1]=true;
	dis[1][1]=0;
	q.push(t);
	while(!q.empty()){
		node now=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			node nxt;
			nxt.x=now.x+mv[i][0];
			nxt.y=now.y+mv[i][1];
			if(nxt.x<=0||nxt.x>n||nxt.y<=0||nxt.y>m||vis[nxt.x][nxt.y]==true) continue;
			if(a[nxt.x][nxt.y]=='*') continue;
			if(a[nxt.x][nxt.y]=='$') {
				continue;
			}
			if(mid<0) return ;
			vis[nxt.x][nxt.y]=true;
			dis[nxt.x][nxt.y]=dis[now.x][now.y]+1;
			q.push(nxt);
		}
	}
}
int check(int mid){
	bfs(mid);
	if(vis[n][m]) {
		return dis[n][m];
	}
	else return -1;
}
int t;
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	cin>>t;
	while(t--){
		ans=ans2=0;
		cin>>n>>m;
		memset(vis,false,sizeof(vis));
		memset(dis,0,sizeof(dis));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){ 
				cin>>a[i][j];
				if(a[i][j]=='$') s++;
			}
		if(n==1){
			cout<<s<<" "<<m<<endl;
			return 0;
		}
		int l=0,r=s;
		while(l<=r){
			int mid=(l+r)/2;
			int t=check(mid);
			if(t!=-1){
				r=mid-1;
				ans=mid;
				ans2=t;
			} 
			else l=mid+1;
		}
		cout<<ans<<" "<<ans2<<endl;
	}
	return 0;
} 
