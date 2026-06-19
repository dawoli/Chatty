#include<bits/stdc++.h>
#define int long long
//#define fin std::cin
//#define fout std::cout
//DELETE!!DELETE!!FILE!!FILE!!
using std::ifstream;
using std::ofstream;
ifstream fin("explore.in");
ofstream fout("explore.out");
const int maxn=1005;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
char maze[maxn][maxn];
bool visited[maxn][maxn];
int T;
void init(){
	for(int i=0;i<maxn;i++){
		for(int j=0;j<maxn;j++){
			maze[i][j]='x';
			visited[i][j]=false;
		}
	}
}
int solve(int n,int m,int x0,int y0,int d0,int k){
	visited[x0][y0]=true;
	for(int i=0;i<k;i++){
		int nx=x0+dx[d0];
		int ny=y0+dy[d0];
		if(1<=nx and nx<=n and 1<=ny and ny<=m){
			if(maze[nx][ny]=='.'){
				visited[nx][ny]=true;
				x0=nx;
				y0=ny;
			}
			else {
				d0++;
				d0%=4;
			}
		}
		else {
			d0++;
			d0%=4;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(visited[i][j]) ans++;
		}
	}
	return ans;
}
signed main(){
	fin>>T;
	for(int i=0;i<T;i++){
		init();
		int n,m,k;
		int x0,y0,d0;
		fin>>n>>m>>k;
		fin>>x0>>y0>>d0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) fin>>maze[i][j];
		}
		fout<<solve(n,m,x0,y0,d0,k)<<"\n";
	}
	return 0;
}
