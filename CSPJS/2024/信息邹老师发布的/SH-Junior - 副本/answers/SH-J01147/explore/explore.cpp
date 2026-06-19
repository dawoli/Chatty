#include<bits/stdc++.h>
std::ifstream fin("explore.in");
std::ofstream fout("explore.out");
int lx[4]={0,1,0,-1},ly[4]={1,0,-1,0};
int T;
int ans=1;
int main(){
	fin>>T;
	for(int i=1;i<=T;i++){
		ans=1;
        char a[1000][1000];
        bool b[1000][1000];
		int n,m,k;
		fin>>n>>m>>k;
		int x,y,d;
		fin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				fin>>a[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			int nx=x+lx[d],ny=y+ly[d];
			if(nx<=0||nx>n||ny<=0||ny>m){
				d=(d+1)%4;
				continue;
			}
			else if(a[nx][ny]=='x'){
				d=(d+1)%4;
				continue;
			}
			else{
				x=nx;
				y=ny;
				if(b[x][y]==false){
					ans++;
					fout<<x<<" "<<y<<"\n";
					b[x][y]=true;
				}
			}
		}
		fout<<ans<<"\n";
		x=0,y=0;
	}
	return 0;
}
