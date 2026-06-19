#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int l=1;l<=t;l++){
		int n,m,k;
		int x,y,d;
		char a[1005][1005]={0};
		int vis[1005][1005]={0};
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		int ans=0;
		vis[x][y]=1;
		for(int i=1;i<=k;i++){
			if(d==0){
				if(a[x][y+1]=='.'){
					vis[x][y+1]=1;
					y=y+1;
				}
				else{
					d=1;
				}
			}else if(d==1){
				
				if(a[x+1][y]=='.'){
					vis[x+1][y]=1;
					x=x+1;
				}
				else{
					d=2;
				}
			}else if(d==2){
				
				if(a[x][y-1]=='.'){
					vis[x][y-1]=1;
					y=y-1;
				}
				else{
					d=3;
				}
			}else{
				
				if(a[x-1][y]=='.'){
					vis[x-1][y]=1;
					x=x-1;
				}
				else{
					d=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

