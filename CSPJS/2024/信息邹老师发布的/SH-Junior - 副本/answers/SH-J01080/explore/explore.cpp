#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1009;
char mp[N][N];
ll T,n,m,k;
ll nowx,nowy,nowd;
ll nxtx,nxty,nxtd;
bool ok[N][N];
ll ans=0;
bool check(ll a,ll b){
	if(mp[a][b]=='x') return 0;
	
	if(a<1||b<1||a>n||b>m) return 0;
	
	return 1;
}
ll spin(ll d){
	return (d+1)%4;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>T;
	
	while(T--){
		memset(ok,0,sizeof(ok));
		ans=0;
		
		cin>>n>>m>>k;
		cin>>nowx>>nowy>>nowd;
		ok[nowx][nowy]=1;
		ans++;
		for(ll i=1;i<=n;++i)
			for(ll j=1;j<=m;++j)
				cin>>mp[i][j];
		
		while(k--){
			nxtx=nowx;
			nxty=nowy;
			
			if(nowd==0) nxty+=1;
			if(nowd==1) nxtx+=1;
			if(nowd==2) nxty-=1;
			if(nowd==3) nxtx-=1;
			
			if(check(nxtx,nxty)){
				nowx=nxtx;
				nowy=nxty;
				
				if(ok[nowx][nowy]==0){
					ans++;
					ok[nowx][nowy]=1;
				}
			}
			else nowd=spin(nowd);
		}
		cout<<ans<<endl;
	}
	return 0;
}
