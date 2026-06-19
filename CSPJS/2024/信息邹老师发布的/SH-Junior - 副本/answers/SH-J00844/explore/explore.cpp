#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,k,dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}},x,y,d;
char map[1010][1010];
bool f[1010][1010];
bool inmap(int x,int y){
	return x>0&&y>0&&x<=n&&y<=m;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int sum=1;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>map[i][j];
				f[i][j]=0;
			}
		}
		f[x][y]=1;
		while(k--){
			int nx=x+dir[d][0],ny=y+dir[d][1];
			if(inmap(nx,ny)&&map[nx][ny]=='.'){
				x=nx;
				y=ny;
				if(!f[x][y])sum++;
				f[x][y]=1;
			}else{
				d=(d+1)%4; 
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
