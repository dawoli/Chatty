#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d,ans;
char c[1009][1009];
int vis[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		int nx=x,ny=y,nd=d;
		vis[nx][ny]=1;
		while(k--){
			if(d==0&&ny<m&&c[nx][ny+1]=='.'){
				ny++;
			}
			else if(d==1&&nx<n&&c[nx+1][ny]=='.'){
				nx++;
			}
			else if(d==2&&ny>1&&c[nx][ny-1]=='.'){
				ny--;
			}
			else if(d==3&&nx>1&&c[nx-1][ny]=='.'){
				nx--;
			}
			else{
				d=(d+1)%4;
			}
			vis[nx][ny]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]){
					ans++;
					vis[i][j]=0;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
