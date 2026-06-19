#include<bits/stdc++.h>
using namespace std;
int T;
char field[1005][1005];
bool vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		int n,m,k,xx,yy,d,ans=0;
		cin>>n>>m>>k>>xx>>yy>>d;
		vis[xx][yy]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>field[i][j];
			}
		}
		for(;k!=0;k--){
			if(d==0){
				if(field[xx][yy+1]=='.'){
					yy+=1;
					vis[xx][yy]=1;
				}
				else{
					d=(d+1)%4;
				}
			}
			else if(d==1){
				if(field[xx+1][yy]=='.'){
					xx+=1;
					vis[xx][yy]=1;
				}
				else{
					d=(d+1)%4;
				}
			}
			else if(d==2){
				if(field[xx][yy-1]=='.'){
					yy-=1;
					vis[xx][yy]=1;
				}
				else{
					d=(d+1)%4;
				}
			}
			else if(d==3){
				if(field[xx-1][yy]=='.'){
					xx-=1;
					vis[xx][yy]=1;
				}
				else{
					d=(d+1)%4;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=1003;i++){
			for(int j=1;j<=1003;j++){
				field[i][j]=0;
				vis[i][j]=0;
			}
		}
	}
	return 0;
}
