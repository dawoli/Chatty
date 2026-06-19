#include<bits/stdc++.h>
using namespace std;
const int N=1010;
char mp[N][N];
bool vis[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		vis[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		while(k--){
			int nowx=x,nowy=y;
			if(d==0){
				nowy++;
			}else if(d==1){
				nowx++;
			}else if(d==2){
				nowy--;
			}else{
				nowx--;
			}
			if(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m&&mp[nowx][nowy]=='.'){
				vis[nowx][nowy]=1;
				x=nowx,y=nowy;
			}else{
				d=(d+1)%4;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]){
					ans++;
					vis[i][j]=0;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
