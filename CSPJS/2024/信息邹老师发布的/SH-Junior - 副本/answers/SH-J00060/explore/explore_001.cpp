#include<bits/stdc++.h>
using namespace std;
int dx[10]={0,-1,0,1},dy[10]={1,0,-1,0};
int a[1010][1010],vis[1010][1010];
char s;
int n,m,k;
int x,y,d;
int t;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		vis[x][y]=1;
		
		for(int j=1;j<=m;++j){
			for(int i=1;i<=n;++i){
				cin>>s;
				if(s=='x') a[i][j]=0;
				else a[i][j]=1;
			}
		}
		while(k--){
			if(a[x+dx[d]][y+dy[d]]==1&&x>0&&y>0&&x<=n&&y<=m){
				x+=dx[d],y+=dy[d];
				vis[x][y]=1;
			}else{
				d=(d+1)%4;
			}
		}
		int ans=0;
		for(int j=1;j<=m;++j){
			for(int i=1;i<=n;++i){
				ans+=vis[i][j];
			}
		}
		cout<<ans;
	}
	return 0;
}
