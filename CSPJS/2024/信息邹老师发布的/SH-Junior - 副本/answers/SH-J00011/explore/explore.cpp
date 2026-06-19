#include<bits/stdc++.h>
using  namespace std;

const int N=1e3+5;

char ch[N][N];
bool used[N][N];
int n,m,k,t,cnt=0,ans=0;
int sx,sy,sd;
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};

void dfs(int x,int y,int d){
	int xx=x+fx[d],yy=y+fy[d];
	if(cnt==k) {
		return;
	}
	cnt++; 
	if(xx>n||xx<=0||yy>m||yy<=0) {
		dfs(x,y,(d+1)%4);
		return;
	}
	if(ch[xx][yy]=='x') {
		dfs(x,y,(d+1)%4);
		return;
	} 
	if(!used[xx][yy]) {
		ans++;
		used[xx][yy]=1;
	}
	dfs(xx,yy,d);
} 

int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--) {
		memset(used,0,sizeof(used));
		cin>>n>>m>>k;
		cin>>sx>>sy>>sd;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				cin>>ch[i][j]; 
			}
		}		
		cnt=0,ans=1;
		used[sx][sy]=1;
		dfs(sx,sy,sd);
		cout<<ans<<'\n';
	}
	return 0;
}
