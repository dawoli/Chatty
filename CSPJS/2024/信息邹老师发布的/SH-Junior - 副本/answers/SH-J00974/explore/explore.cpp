#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1005;
const ll dx[5]={0,1,0,-1};
const ll dy[5]={1,0,-1,0};
char mp[N][N];
ll vis[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout); 
	ll T;
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		ll n,m,k;
		cin>>n>>m>>k;
		ll x0,y0,d0;
		cin>>x0>>y0>>d0;
		for(ll i = 1;i <= n;i++){
			for(ll j = 1;j <= m;j++){
				cin>>mp[i][j];
			}
		}
		ll x,y,d,cnt=1;
		x=x0;y=y0;d=d0;
		vis[x][y]=1;
		for(ll i = 1;i <= k;i++){
			ll nx=x+dx[d],ny=y+dy[d];
			if(nx>=1 && nx<=n && ny>=1 && ny<=m && mp[nx][ny]=='.'){
				x=nx;y=ny;
			}
			else{
				d++;
				d%=4;
			}
			if(!vis[x][y])cnt++;
			vis[x][y]=1;
		}
		cout<<cnt<<'\n';
	}
	return 0;
} 

