#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1009;
int T,n,m,k,x,y,d;
char mp[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[i][j];
		ll ans=1;
		mp[x][y]='0';
		while(k--){
			int nx,ny;
			if(d==0) nx=x,ny=y+1;
			else if(d==1) nx=x+1,ny=y;
			else if(d==2) nx=x,ny=y-1;
			else nx=x-1,ny=y;
			if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='x'){
				d=(d+1)%4;
				continue;
			}
			if(mp[nx][ny]!='0') ans++;
			x=nx,y=ny,mp[x][y]='0';
		}
		cout<<ans<<endl;
	}
	return 0;
} 
