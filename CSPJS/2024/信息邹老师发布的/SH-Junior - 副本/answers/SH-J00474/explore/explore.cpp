#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
ll n,m,k;
ll x,y,d;
char graph[1003][1003];
ll vis[1003][1003];
ll weiyi_x[4]={0,1,0,-1};
ll weiyi_y[4]={1,0,-1,0};
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				cin>>graph[i][j];
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				vis[i][j]=0;
			}
		}
		vis[x][y]=1;
		for(ll i=1;i<=k;i++){
			if(graph[x+weiyi_x[d]][y+weiyi_y[d]]!='x'&&x+weiyi_x[d]>0&&x+weiyi_x[d]<=n&&y+weiyi_y[d]>0&&y+weiyi_y[d]<=m){
				x=x+weiyi_x[d];
				y=y+weiyi_y[d];
				vis[x][y]=1;
			}
			else{
				d=(d+1)%4;
			}
		}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				ans+=vis[i][j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
