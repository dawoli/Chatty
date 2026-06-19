#include<bits/stdc++.h>
using namespace std;
void fr(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
}
int n,m,k;
char ma[1005][1005];
bool vis[1005][1005];
int main(){
	fr();
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ma[i][j];
				vis[i][j]=0;
			}
		}
		vis[x][y]=1;
		int ans=1,xx,yy;
		while(k){
			k--;
			if(d==0)xx=x,yy=y+1;
			else if(d==1)xx=x+1,yy=y;
			else if(d==2)xx=x,yy=y-1;
			else if(d==3)xx=x-1,yy=y;
			if(1>xx||xx>n||1>yy||yy>m||ma[xx][yy]=='x'){
				d=(d+1)%4;
				continue;
			}
			x=xx,y=yy;
			//ans++;
			if(vis[x][y]==0)vis[x][y]=1,ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
