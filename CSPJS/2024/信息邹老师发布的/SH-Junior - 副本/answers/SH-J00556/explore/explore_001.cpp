#include<bits/stdc++.h>
using namespace std;
char s[1009][1009];
bool vis[1009][1009];
int n,m,x,y,d,k;
int t;
int f[10][4]={{0,1},{1,0},{0,-1},{-1,0}};
bool check(int xx,int yy){
	if(xx<1||xx>n||yy<1||yy>m) return 0;
	if(s[xx][yy]=='x') return 0;
	return 1;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		memset(vis,0,sizeof(vis));
		vis[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>s[i][j];
			}
		}
		while(k--){
			int xx=x+f[d][0],yy=y+f[d][1];
			if(check(xx,yy)){
				x=xx;
				y=yy;
			}
			else{
				d=(d+1)%4;
			}
			vis[x][y]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans+=vis[i][j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
