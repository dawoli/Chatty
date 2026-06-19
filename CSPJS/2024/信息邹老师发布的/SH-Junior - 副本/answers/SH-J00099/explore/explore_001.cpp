#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1009
ll T,n,m,k,x0,y0,d0,vst[N][N],ans;
ll dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char c[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		memset(vst,0,sizeof vst);
		ans=0;
		cin>>n>>m>>k>>x0>>y0>>d0;
		for(ll i=1;i<=n;i++)for(ll j=1;j<=m;j++)cin>>c[i][j];
		vst[x0][y0]=1;
		for(ll i=1;i<=k;i++){
			ll nx=x0+dx[d0],ny=y0+dy[d0];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&c[nx][ny]=='.'){
				vst[nx][ny]=1,x0=nx,y0=ny;
			}
			else d0=(d0+1)%4;
		}
		for(ll i=1;i<=n;i++)for(ll j=1;j<=m;j++)ans+=vst[i][j];
		cout<<ans<<"\n"; 
	}
	return 0;
} 
