#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<utility>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
int t,n,m,k,x,y,d;
char a[1001][1001];
bool v[1001][1001];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y,int d,int k){
	v[x][y]=1;
	if(!k)return;
	int nx=x+dx[d],ny=y+dy[d];
	if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.')dfs(nx,ny,d,k-1);
	else dfs(x,y,(d+1)%4,k-1);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		dfs(x,y,d,k);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans+=v[i][j];
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
