#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll biao=1e3+10;
char c[biao][biao];
bool vis[biao][biao];
ll mv[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll t;
	cin>>t;
	
	while(t--){
		ll n,m,k,x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		
		memset(vis,0,sizeof(vis));
		
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		
		vis[x][y]=1;
		for(ll i=1;i<=k;i++){
			ll xx=x+mv[d][0],yy=y+mv[d][1];
			
			if(xx<=0 || xx>n || yy<=0 || yy>m){
				d=(d+1)%4;
				continue;
			}
			
			if(c[xx][yy]=='x'){
				d=(d+1)%4;
				continue;
			}
			
			x=xx,y=yy;
			vis[x][y]=1;
		}
		
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				if(vis[i][j]) ans++;
			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
