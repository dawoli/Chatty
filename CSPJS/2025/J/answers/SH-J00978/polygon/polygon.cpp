#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[6000],ans,maxa,c[6000][6000];
void makec(){
	for(int i=1;i<=5500;i++)c[i][i]=1,c[i][1]=1;
	for(int i=3;i<=n;i++)for(int j=2;j<i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	return;
}
int kpos(int x,int k){
	return (x>>(k-1))&1;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)maxa=max(maxa,a[i]);
	if(maxa==1){
		makec();
		int ans=0;
		for(int i=3;i<=n;i++)ans=(ans+c[n][i])%mod;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=pow(2,n);i++){
		int temp,tmax=LLONG_MIN,tsum=0;
		for(int j=1;j<=20;j++)if(kpos(i,j)==1)temp++;
		if(temp<3)continue;
		for(int j=1;j<=20;j++){
			if(kpos(i,j)==1){
				tsum+=a[n-j+1],tmax=max(tmax,a[n-j+1]);
			}
		}
		//cout<<tmax<<" "<<tsum<<"\n";
		if(tsum>2*tmax){
			ans++;
			if(ans>mod)ans%=mod;
		}
	}
	cout<<ans%mod;
	return 0;
}
