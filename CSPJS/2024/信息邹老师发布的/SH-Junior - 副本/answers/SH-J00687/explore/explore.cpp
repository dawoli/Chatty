#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,t;
char mp[1005][1005];
int vis[1005][1005];
bool inmap(int a,int b){
	return a>=1&&a<=n&&b>=1&&b<=m;
}
void dfs(int xx,int yy,int dd,int kk){
	while(kk>0){
	if(dd==0){
		int ny=yy+1;
	if(inmap(xx,ny)==true&&mp[xx][ny]=='.'){
		vis[xx][ny]=1;
		dfs(xx,ny,0,kk-1);
	}
	else dfs(xx,yy,1,kk-1);
}
	else if(dd==1){
		int nx=xx+1;
		if(inmap(nx,yy)==true&&mp[nx][yy]=='.'){
			vis[nx][yy]=1;
			dfs(nx,yy,1,kk-1);
		}else{
			dfs(xx,yy,2,kk-1);
		}
	}
	else if(dd==2){
		int ny=yy-1;
		if(inmap(xx,ny)==true&&mp[xx][ny]=='.'){
			vis[xx][ny]=1;
			dfs(xx,ny,2,kk-1);
		}else{
			dfs(xx,yy,3,kk-1);
		}
	}
	else if(dd==3){
		int nx=x-1;
		if(inmap(nx,yy)==true&&mp[nx][yy]=='.'){
			vis[nx][yy]=1;
			dfs(nx,yy,3,kk-1);
		}else{
			dfs(xx,yy,0,kk-1);
		}
	}
}
}
int main(){
	//freopen("explore.in","r",stdin);
	//freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int sum=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		vis[x][y]=1;
		dfs(x,y,d,k);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
