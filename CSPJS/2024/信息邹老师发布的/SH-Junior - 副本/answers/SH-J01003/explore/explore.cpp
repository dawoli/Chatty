#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;
bool forest[MAXN][MAXN];
bool flag[MAXN][MAXN];
int direct[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int T;
void solve(){
	memset(forest,0,sizeof(forest));
	memset(flag,0,sizeof(flag));
	int n,m,k;
	cin>>n>>m>>k;
	int x,y,d;
	cin>>x>>y>>d;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char c;
			cin>>c;
			if(c=='x') forest[i][j]=1;
		}
	int ans=0;
	flag[x][y]=1;
	ans++;
	for(int i=1;i<=k;i++){
		int nxtX=x+direct[d][0];
		int nxtY=y+direct[d][1];
		if(!forest[nxtX][nxtY] && (nxtX>=1 && nxtX<=n) && (nxtY>=1 && nxtY<=m)){
			x=nxtX;
			y=nxtY;
			if(!flag[x][y]) ans++;
			flag[x][y]=1;
		}
		else d=(d+1)%4;
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
