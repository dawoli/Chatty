#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int n,m,k;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char a[N][N];
int vst[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		memset(vst,0,sizeof vst);
		cin>>n>>m>>k;
		int cnt=1;
		int x,y,d;
		cin>>x>>y>>d;
		vst[x][y]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		for(int i=1;i<=k;i++){
			int nx=x+dx[d],ny=y+dy[d];
			if(a[nx][ny]=='.'){
				x=nx,y=ny;
				if(!vst[nx][ny]){
					vst[nx][ny]=1;
					cnt++;
				}
			}
			else d=(d+1)%4;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
