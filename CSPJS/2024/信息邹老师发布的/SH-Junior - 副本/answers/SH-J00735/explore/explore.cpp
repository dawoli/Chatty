#include<bits/stdc++.h>
using namespace std;
int t,cnt=1;
char a[1001][1001];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y,int k,int d,int n,int m){
	if(k==0){
		cout<<cnt<<endl;
		cnt=0;
		return;
	}
	int nx=x+dx[d];
	int ny=y+dy[d];
	if(nx>=1 && nx<=n && ny>=1 && ny<=m && a[nx][ny]=='.'){
		cnt++;
		dfs(nx,ny,k-1,d,n,m);
	}
	else{
		dfs(x,y,k-1,(d+1)%4,n,m);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int m,n,k,x,y,d;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		dfs(x,y,k,d,n,m);
	}
} 
