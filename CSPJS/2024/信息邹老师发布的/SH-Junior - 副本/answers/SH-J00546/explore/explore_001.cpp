#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
const int maxk=1e6+5;
int T,n,m,k;
char G[maxn][maxn];
bool have[maxn][maxn];
bool check(int x,int y) {
	return 1<=x&&x<=n&&1<=y&&y<=m&&G[x][y]=='.';
}
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--) {
		int x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				have[i][j]=false;
			}
		}
		for(int i=1;i<=n;i++) {
			string s;
			cin>>s;
			for(int j=1;j<=m;j++) {
				G[i][j]=s[j-1];
			}
		}
		while(k--) {
			have[x][y]=true;
			int nx=x,ny=y;
			if(d==0)  ny++;
			if(d==1)  nx++;
			if(d==2)  ny--;
			if(d==3)  nx--;
			if(check(nx,ny))  x=nx,y=ny;
			else  d=(d+1)%4;
			have[x][y]=true;
		}
		int cnt=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(have[i][j])  cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}

