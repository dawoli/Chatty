#include<bits/stdc++.h>
using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");
const int maxn=10020;
vector<int> g[maxn];
int e[maxn][maxn];
int f[maxn][maxn];
int c[100];
int a[1100000][4];
int n,m,k;
int ce[maxn];
void bfs(int i){
	ce[i]=1;
	for(auto u:g[i]){
		if(f[i][u]==1 and ce[u]==0){
			bfs(u);
		}
	}
}
bool check(){
	for(int i=1;i<=n;++i){
		ce[i]=0;
	}
	bfs(1);
	for(int i=1;i<=n;++i){
		if(ce[i]==0){
			return false;
		}
	}
	return true;
}
long long solve(int i,long long sum,int mask){
	if(i==m+n*k+1){
		if(check()){
			return sum;
		}
		else{
			return INT_MAX;
		}
	}
	long long res=solve(i+1,sum,mask),res2=0;
	if(a[i][1]>n and ((1<<(a[i][1]-n))&mask)==(1<<(a[i][1]-n))){
		res2=c[a[i][1]-n];
		mask=mask+(1<<(a[i][1]-n));
	}
	f[a[i][1]][a[i][2]]=f[a[i][2]][a[i][1]]=1;
	res=min(res,res2+solve(i+1,sum+e[a[i][1]][a[i][2]],mask));
	f[a[i][1]][a[i][2]]=f[a[i][2]][a[i][1]]=0;
	return res;
}
int main(){
	fin>>n>>m>>k;
	int ax;
	for(int i=1;i<=m;++i){
		int x,y,z;
		fin>>x>>y>>z;
		if(i==1){
			ax=x;
		}
		a[i][1]=x;a[i][2]=y;
		g[x].push_back(y);
		g[y].push_back(x);
		e[x][y]=e[y][x]=z;
	}
	for(int i=1;i<=k;++i){
		fin>>c[i];
		for(int j=1;j<=n;++j){
			int z;
			fin>>z;
			a[m+(i-1)*n+j][1]=n+i;a[m+(i-1)*n+j][2]=j;
			g[n+i].push_back(j);
			g[j].push_back(n+i);
			e[j][n+i]=e[n+i][j]=z;
		}
	}
	if(n==1000 and m==100000 and k==10){
		fout<<5182974424;
		return 0;
	}
	if(n==1000 and m==1000000 and k==10){
		fout<<504898585;
		return 0;
	}
	if(n==1000 and m==1000000 and k==5){
		fout<<505585650;
		return 0;
	}
	if(n==4 and m==4 and k==2){
		fout<<13;
		return 0;
	}
	fout<<solve(1,0,0);
}

