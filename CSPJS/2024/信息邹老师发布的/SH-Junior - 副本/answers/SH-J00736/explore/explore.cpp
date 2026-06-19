#include<bits/stdc++.h>
using namespace std;
int T;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int solve(){
	int n,m,k,x,y,d,sum=0;
	cin>>n>>m>>k>>x>>y>>d;
	char g[n+5][m+5];
	bool f[n+5][m+5]={0};
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>g[i][j];
	f[x][y]=1;
	while(k>0){
		int nx=x+dx[d],ny=y+dy[d];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&g[nx][ny]=='.'){
			x=nx;
			y=ny;
			f[nx][ny]=1;
		}
		else{
			d=(d+1)%4;
		}
		k--;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(f[i][j])
				sum++;
	return sum;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
		cout<<solve()<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
