#include<bits/stdc++.h>
using namespace std;
int n,a[5005],f[5005][10005],sum[5005][5005],ans,pw[5005];
#define MOD 998244353
#define int long long
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(false);
	pw[0]=1;
	for(int i=1;i<=5000;i++)pw[i]=(pw[i-1]<<1)%MOD;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		f[i][0]=1;sum[i][0]=1;
		for(int j=1;j<=5000;j++){
			if(j>=a[i])f[i][j]=(f[i-1][j]+f[i-1][j-a[i]])%MOD;
			else f[i][j]=f[i-1][j];
			sum[i][j]=(sum[i][j-1]+f[i][j])%MOD;
			//cout<<f[i][j]<<" ";
		}
		//cout<<endl;
		//cout<<ans<<endl;
		if(i>1)ans=((ans+pw[i-1])%MOD-sum[i-1][a[i]]+MOD)%MOD;
		//if(ans<0)cout<<ans<<" "<<pw[i-1]<<" "<<sum[i-1][a[i]]<<endl;
	}
	cout<<ans;
}
/*
done at 2h

will it win?
it will win.

I WANNA AK CSP-J
I WANNA CSP-S 1=

__int128 rp;
while(true)rp++;

2025CSP-J is so water
I hope 2025CSP-S is water too

why are you looking at these ****ing words?

\o/ccf\o/ccf\o/ccf\o/ccf\o/ccf\o/
*/ 
