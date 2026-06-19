#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e3+10;

int n,m,k;
int xs,ys,ds;
char c[MAXN][MAXN]={};
bool v[MAXN][MAXN]={};

int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};

bool check(int x,int y,int d) {
	int xl,yl;
	xl=x+dx[d];
	yl=y+dy[d];
	if(xl>=1 && xl<=n && yl>=1 && yl<=m && c[xl][yl]=='.')
		return true;
	else
		return false;
}

void dfs(int x,int y,int d,int kn) {
	v[x][y]=true;
	if(kn==0)
		return ;
	if(check(x,y,d)) {
		dfs(x+dx[d],y+dy[d],d,kn-1);
	}
	else {
		dfs(x,y,(d+1)%4,kn-1);
	}
}

int T;

int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n>>m>>k>>xs>>ys>>ds;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				cin>>c[i][j];
				v[i][j]=false;
			}
		}
		dfs(xs,ys,ds,k); int ljy=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(v[i][j]) {
					ljy++;
				}
			}
		}
		cout<<ljy<<endl;
	}
	return 0;
}
