#include<bits/stdc++.h>
#define N 1005
using namespace std;
bool vis[N][N];
char a[N][N];
int cnt,n,m,dir[5][2]={{0,1},{1,0},{0,-1},{-1,0}};

void defs(int sx,int sy,int sd,int k){
	if(k==0)
		return;
	int nx=sx+dir[sd][0],ny=sy+dir[sd][1];
	if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.'){
		if(!vis[nx][ny]){
			vis[nx][ny]=true;
			cnt++;
		}
		defs(nx,ny,sd,k-1);
	}
	else defs(sx,sy,(sd+1)%4,k-1);
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int k,sx,sy,sd;
		cnt=1;
		cin>>n>>m>>k;
		cin>>sx>>sy>>sd;
		vis[sx][sy]=true;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				scanf("%c",&a[i][j]);
			}
		}
		defs(sx,sy,sd,k);
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
