#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,k;
int x,y,d;
int sum;
char mp[1010][1010];
bool v[1010][1010];
int dfs(int x,int y,int d,int sum,int k){
	if(k==0){
		return sum;
	}
	k--;
	int nx=x+dx[d];
	int ny=y+dy[d];
	if(nx>=1 && nx<=n && ny>=1 && ny<=m && mp[nx][ny]!='x'){
		if(!v[nx][ny]){
			sum++;
		}
		v[nx][ny]=1;
		return dfs(nx,ny,d,sum,k);
	}else{
		d=(d+1)%4;
		return dfs(x,y,d,sum,k);
	}
};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		sum=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				v[i][j]=0;
			}
		}
		v[x][y]=1;
		sum++;
		cout<<dfs(x,y,d,sum,k)<<endl;
	}
	return 0;
}
