#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int t;
int n,m,k;
int x0,yyy,d0;
char a[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int vis[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x0>>yyy>>d0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		vis[x0][yyy]=1;
		for(int i=1;i<=k;i++){
			int xx=x0+dx[d0];
			int yy=yyy+dy[d0];
			if(xx<1 || xx>n || yy<1 || yy>m){
				d0=(d0+1)%4;
				continue;
			}
			if(a[xx][yy]=='x'){
				d0=(d0+1)%4;
				continue;
			}
			vis[xx][yy]=1;
			x0=xx,yyy=yy;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]){
					ans++;
					vis[i][j]=0;
				}
			}
		}
		cout<<ans<<endl;
	}	
	return 0;
} 
