#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1009;
ll t,n,m,k,a[N][N],x,y,d,vst[N][N],ans;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(ll u=1;u<=t;u++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				char x;
				cin>>x;
				if(x=='.'){
					a[i][j]=1;
				}else{
					a[i][j]=0;
				}
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				vst[i][j]=0;
			}
		}
		for(ll i=1;i<=k;i++){
			vst[x][y]=1;
			if(d==0){
				if(y+1>m || a[x][y+1]==0){
					d=1;
				}else{
					y=y+1;
				}
			}else if(d==1){
				if(x+1>n || a[x+1][y]==0){
					d=2;
				}else{
					x=x+1;
				}
			}else if(d==2){
				if(y-1<1 || a[x][y-1]==0){
					d=3;
				}else{
					y=y-1;
				}
			}else if(d==3){
				if(x-1<1 || a[x-1][y]==0){
					d=0;
				}else{
					x=x-1;
				}
			}
			vst[x][y]=1;
		}
		ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				if(vst[i][j]==1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
