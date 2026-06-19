#include<bits/stdc++.h>
#define N 100002
using namespace std;
typedef long long ll;
ll t,n,a[N][4],f[2][4][N],b[N],ans,c[N],cnt1,cnt2,cnt3;
bool A=1,A1=1,A2=1;
void dfs(ll k){
	if(k>n){
		ll t=0;
		for(ll i=1;i<=n;++i)t+=a[i][c[i]];
		ans=max(ans,t);
		return;
	}
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2)return;
	++cnt1;
	c[k]=1;
	dfs(k+1);
	--cnt1;
	++cnt2;
	c[k]=2;
	dfs(k+1);
	--cnt2;
	++cnt3;
	c[k]=3;
	dfs(k+1);
	--cnt3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(ll i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]||a[i][3])A=0;
			if(a[i][1]||a[i][3])A1=0;
			if(a[i][1]||a[i][2])A2=0;
		}
		if(n==2)cout<<max(max(max(a[1][1]+a[2][2],a[1][1]+a[2][3]),max(a[1][2]+a[2][1],a[1][2]+a[2][3])),max(a[1][3]+a[2][1],a[1][3]+a[2][2]))<<'\n';
		else if(A||A1||A2){
			for(ll i=1;i<=n;++i){
				if(A)b[i]=a[i][1];
				else if(A1)b[i]=a[i][2];
				else b[i]=a[i][3];
			}
			sort(b+1,b+n+1);
			for(ll i=n;i>n/2;--i)ans+=b[i];
			cout<<ans<<'\n';
		}else if(n<=10){
			dfs(1);
			cout<<ans<<'\n';
		}else{
			for(ll i=1;i<=n;++i)ans+=max(max(a[i][1],a[i][2]),a[i][3]);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
