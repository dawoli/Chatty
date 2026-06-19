#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
const ll M=209;
ll T,n,a[N][5],f[M][M][M],t[N],mxer[5],xer[N];
bool flag[5];
void init55(){
	for(ll i=0;i<=n;i++)
		for(ll j=0;j<=n;j++)
			for(ll k=0;k<=n;k++)
				f[i][j][k]=0;
}
void solve55(){
	init55();
	for(ll i=1;i<=n;i++)
		for(ll j=0;j<=min(i,n/2);j++)
			for(ll k=0;k<=min(i-j,n/2);k++) if(i-j-k<=n/2){
				if(i-j-k>=1) f[i][j][k]=f[i-1][j][k]+a[i][3];
				if(j>=1) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
				if(k>=1) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
			}
	ll ans=0;
	for(ll j=0;j<=n;j++)
		for(ll k=0;k<=n-j;k++)
			ans=max(ans,f[n][j][k]);
	cout<<ans<<endl;
}
void solveA(){
	ll ans=0;
	for(ll i=1;i<=n;i++) t[i]=a[i][1];
	sort(t+1,t+1+n);
	for(ll i=n/2+1;i<=n;i++) ans+=t[i];
	cout<<ans<<endl;
}
void swaper(ll u,ll v){
	for(ll i=1;i<=n;i++){
		xer[i]=a[i][u]; a[i][u]=a[i][v]; a[i][v]=xer[i];
	}
}
void solve(){
	mxer[1]=mxer[2]=mxer[3]=0;
	for(ll i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) mxer[1]++;
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) mxer[2]++;
		else mxer[3]++;
	}
	if(mxer[1]<=n/3) ;
	else if(mxer[2]<=n/3) swaper(1,2);
	else swaper(1,3);
	ll ans=0;
	for(ll i=1;i<=n;i++) ans+=a[i][1],a[i][3]-=a[i][1],a[i][2]-=a[i][1];
	for(ll i=1;i<=n;i++) a[i][2]=max(a[i][2],0LL),a[i][3]=max(a[i][3],0LL);
	for(ll i=1;i<=n;i++) t[i]=a[i][3]-a[i][2],ans+=a[i][2];
	sort(t+1,t+1+n);
	for(ll i=n/2+1;i<=n;i++) ans+=t[i];
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		flag[1]=flag[2]=flag[3]=true;
		cin>>n;
		for(ll i=1;i<=n;i++) for(ll j=1;j<=3;j++) cin>>a[i][j];
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++) if(a[i][j]!=0) flag[j]=false;
		}
		if(n<=200) solve55();
		else if(flag[2]==true&&flag[3]==true) solveA();
		else solve();
	}
	return 0;
}

