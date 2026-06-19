#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int T,n,m,k,d,x,y,vis[N][N],ans;
char c[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
				if(c[i][j]=='x') vis[i][j]=-1;
				else vis[i][j]=0;
			}
		}
		vis[x][y]=1;
		for(int i=1;i<=k;i++){
			if(d==0){
				if(c[x][y+1]=='x'||y+1>m){
					d=(d+1)%4;
					continue;
				}
				else{
					y=y+1;
					vis[x][y]=1;
				}
			}
			else if(d==1){
				if(c[x+1][y]=='x'||x+1>n){
					d=(d+1)%4;
					continue;
				}
				else{
					x=x+1;
					vis[x][y]=1;
				}
			}
			else if(d==2){
				if(c[x][y-1]=='x'||y<2){
					d=(d+1)%4;
					continue;
				}
				else{
					y=y-1;
					vis[x][y]=1;
				}
			}
			else{
				if(c[x-1][y]=='x'||x<2){
					d=(d+1)%4;
					continue;
				}
				else{
					x=x-1;
					vis[x][y]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1){
					ans++;
				} 
			}
		cout<<ans<<endl;
	}
	
	return 0;
}

