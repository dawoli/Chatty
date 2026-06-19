#include<bits/stdc++.h>
using namespace std;
#define ll long long
char a[1009][1009];
bool flag[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		ll n,k,m;
		n=0,m=0,k=0;
		ll x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		ll ans=1,nx=x,ny=y;
		flag[x][y]=1;
		for(ll i=1;i<=k;i++){
			if(d==0){
				if(1<=y+1&&y+1<=m&&a[x][y+1]=='.'){
					y++;
					if(flag[x][y]==0)ans++;
					flag[x][y]=1;
				}
			}
			else if(d==1){
				if(1<=x+1&&x+1<=n&&a[x+1][y]=='.'){
					x++;
					if(flag[x][y]==0)ans++;
					flag[x][y]=1;
				}
			}
			else if(d==2){
				if(1<=y-1&&y-1<=m&&a[x][y-1]=='.'){
					y--;
					if(flag[x][y]==0)ans++;
					flag[x][y]=1;
				}
			}
			else if(d==3){
				if(1<=x-1&&x-1<=n&&a[x-1][y]=='.'){
					x--;
					if(flag[x][y]==0)ans++;
					flag[x][y]=1;
				}
			}
			if(nx==x&&ny==y)d=(d+1)%4;
			nx=x,ny=y;
		}
		cout<<ans;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				a[i][j]='x';
			}
		}
		memset(flag,0,sizeof(flag));
	}
	return 0;
} 
