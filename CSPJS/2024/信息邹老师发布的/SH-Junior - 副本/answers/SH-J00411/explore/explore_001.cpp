#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char forest[1010][1010];
bool f[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=0;
			}
		}
		f[x][y]=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>forest[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			if(d==0){
				if(forest[x][y+1]=='.'){
					y++;
					f[x][y]=true;
				}
				else d=(d+1)%4;
			}
			else if(d==1){
				if(forest[x+1][y]=='.'){
					x++;
					f[x][y]=true;
				}
				else d=(d+1)%4;
			}
			else if(d==2){
				if(forest[x][y-1]=='.'){
					y--;
					f[x][y]=true;
				}
				else d=(d+1)%4;
			}
			else if(d==3){
				if(forest[x-1][y]=='.'){
					x--;
					f[x][y]=true;
				}
				else d=(d+1)%4;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(f[i][j]) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
