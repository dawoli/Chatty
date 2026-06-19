#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=5e3+10;
const ll mod=998244353;
ll dp[maxn][maxn],cnt=0,ans=0;
int n,a[maxn],u;

ll qp(int a,int b){
	ll po=1ll*a;
	ll a0=1;
	while(b>0){
		if(b&1){
			a0*=po;
			a0%=mod;
		}
		po*=po;
		po%=mod;
		b>>=1;
	}
	return a0;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	u=a[n];
	for(int i=0;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=0;
		}
	}
	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=u;j++) dp[i][j]+=dp[i-1][j];
		for(int j=a[i];j<=u;j++){
			dp[i][j]+=dp[i-1][j-a[i]];
			dp[i][j]%=mod;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i][a[j]]+=(mod-1);
			dp[i][a[j]]%=mod;
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=u;j++){
			cout<<dp[i][j]<<" ";
		}cout<<"\n";
	}*/
	for(int i=n;i>3;i--){
		ll x=qp(2,i-1);
		x-=i;
		//cout<<x<<"\n";
		ll sum=0;
		for(int j=1;j<=a[i];j++){
			sum+=dp[i-1][j];
			sum%=mod;
		}
		x-=sum;
		x+=mod;
		x%=mod;
		//cout<<i<<" "<<x<<"\n";
		ans+=x;
		ans%=mod;
	}
	if(a[1]+a[2]>a[3]){
		ans++;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
