#include<bits/stdc++.h>
using namespace std;
char f[1009][1009];
bool c[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<=1005;i++){
			for(int j=0;j<=1005;j++){
				f[i][j]=0;
				c[i][j]=0;
			}
		}
		int n,m,k,x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>f[i][j];
			}
		}
		c[x][y]=1;
		int nx=x,ny=y,nd=d;
		for(int i=1;i<=k;i++){
			if(nd==0){
				if(f[nx][ny+1]=='.'&&ny+1<=m){
					ny++;
					c[nx][ny]=1;
				}
				else nd=(nd+1)%4;
			}
			else if(nd==1){
				if(f[nx+1][ny]=='.'&&nx+1<=n){
					nx++;
					c[nx][ny]=1;
				}
				else nd=(nd+1)%4;
			}
			else if(nd==2){
				if(f[nx][ny-1]=='.'&&ny-1>=1){
					ny--;
					c[nx][ny]=1;
				}
				else nd=(nd+1)%4;
			}
			else{
				if(f[nx-1][ny]=='.'&&nx-1>=1){
					nx--;
					c[nx][ny]=1;
				}
				else nd=(nd+1)%4;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(c[i][j]==1) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
