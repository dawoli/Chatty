#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
bool chart[maxn][maxn];
bool vis[maxn][maxn];
int n,m,k;
int x,y,d;
bool isin(int x,int y){
	if(x>0&&x<=n&&y>0&&y<=m&&chart[x][y]) return true;
	return false;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		for(int i=1;i<=1005;i++) memset(chart[i],0,sizeof(chart[i]));
		for(int i=1;i<=1005;i++) memset(vis[i],0,sizeof(vis[i]));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char mark;
				cin>>mark;
				if(mark=='x') chart[i][j]=false;
				else chart[i][j]=true;
			}
		}
		vis[x][y]=true;
		for(int i=1;i<=k;i++){
			int nx=x+dx[d],ny=y+dy[d];
			if(isin(nx,ny)){
				x=nx;
				y=ny;
				vis[x][y]=true;
			}
			else{
				d=(d+1)%4;
			}
		//	cout<<x<<" "<<y<<" "<<d<<endl;
		//	cout<<nx<<" "<<ny<<endl;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

