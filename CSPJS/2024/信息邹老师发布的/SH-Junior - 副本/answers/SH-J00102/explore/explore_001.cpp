#include<bits/stdc++.h>
using namespace std;
const int N=1e3+2;
int n,m,k;
int x,y,d;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool G[N][N];
bool vis[N][N];
int xx,yy;
int cnt;
void init(){
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++){
			G[i][j]=0;
			vis[i][j]=0;
		}
	}
	cnt=0;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		init();
		char c;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c;
				if(c=='.'){
					G[i][j]=1;
				}
				else if(c=='x')G[i][j]=0;
			}
		}
		vis[x][y]=1;
		cnt++;
		while(k--){
			xx=x+dx[d];
			yy=y+dy[d];
			if(G[xx][yy]==1){
				x=xx;
				y=yy;
				if(vis[xx][yy]==0){
					cnt++;
					vis[xx][yy]=1;
				}
			}
			else{
				if(d==3)d=0;
				else d++;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
