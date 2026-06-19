#include<bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char a[1010][1010];
int b[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(b,0,sizeof(b));
		memset(a,'x',sizeof(a));
		int n,m,k,x0,y0,d0;
		cin>>n>>m>>k>>x0>>y0>>d0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>a[i][j];
			}
		}
		b[x0][y0]++;
		for(int i=1;i<=k;++i){
			int xx=x0+dx[d0],yy=y0+dy[d0];
			if(a[xx][yy]=='.'){
				x0=xx;
				y0=yy;
				b[x0][y0]++;
			}
			else{
				d0=(d0+1)%4;
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(b[i][j]>0){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
