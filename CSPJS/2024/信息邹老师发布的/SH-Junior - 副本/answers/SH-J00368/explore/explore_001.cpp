#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int t,n,m,k,x,y,d,ans;
char mp[1001][1001];
bool vis[1001][1001];
char get() {
	if(d==0) {
		if(y<m) return mp[x][y+1];
		else return 'x';
	} else if(d==1) {
		if(x<n) return mp[x+1][y];
		else return 'x';
	} else if(d==2) {
		if(y>1) return mp[x][y-1];
		else return 'x';
	} else {
		if(x>1) return mp[x-1][y];
		else return 'x';
	}
}
void go() {
	if(d==0) {
		++y;
	} else if(d==1) {
		++x;
	} else if(d==2) {
		--y;
	} else {
		--x;
	}
	vis[x][y] = true;
}
int main() {
	//100pts???
	ifstream fin("explore.in");
	ofstream fout("explore.out");
	fin>>t;
	for(int i=1; i<=t; ++i) { //1.5*10^7(?)
		fin>>n>>m>>k>>x>>y>>d;

		memset(vis,0,n*1000+n+m+1);//10^6
		vis[x][y] = true;
		ans = 0;

		for(int j=1; j<=n; ++j) { //10^6
			for(int k=1; k<=m; ++k)
				fin>>mp[j][k];
		}

		for(int j=1; j<=k; ++j) { //10^6
			if(get() == 'x') {
				d=(d+1)%4;
			} else go();
//			cout<<x<<" "<<y<<" "<<d<<endl;
		}

		for(int j=1; j<=n; ++j) { //10^6
			for(int k=1; k<=m; ++k)
				ans += vis[j][k];
		}
		fout<<ans<<endl;
	}
}
