#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
char a[1005][1005];int n,m,x,y,step,d;
bool vis[1005][1005];
void csh(){
	memset(a,' ',sizeof(a));
	memset(vis,0,sizeof(vis));
}
void dfs(int x,int y,int d,int k){
//	cout<<x<<" "<<y<<endl;  
	
	
	int nx,ny; 
	nx=x+dx[d],ny=y+dy[d]; 
	vis[x][y]=1;if(k==0) return;
	if(a[nx][ny]=='x'||nx<1||ny<1||nx>n||ny>m){
		dfs(x,y,(d+1)%4,k-1);
	}else{
		dfs(nx,ny,d,k-1);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		csh();
//		cin>>n>>m>>step>>x>>y>>d;
		scanf("%d%d%d%d%d%d",&n,&m,&step,&x,&y,&d);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				cout<<a[i][j];
//			}
//			cout<<endl;
//		}
		dfs(x,y,d,step);
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
			 	if(vis[i][j]) cnt++;
			}
		} 
		printf("%d\n",cnt);
	}
} 
