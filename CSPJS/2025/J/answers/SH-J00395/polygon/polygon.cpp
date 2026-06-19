#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5009,MOD=998244353;
int n;
ll a[N+10];
ll f[N+10];
ll g[N+10],ans; //g[i][j]表示 在a[1~i]中有多少个子集之和<=j
ll qpow(ll a,ll b){
	ll t=b,num=a,ans=1;
	while(t){
		if(t%2==1) ans=ans*num%MOD;
		num=num*num%MOD;
		t/=2;
	}
	return ans;
}
ll cal(){ //在a[1~pos-1]中有多少个子集之和<=a[pos]
	for(int i=0;i<=N;i++) g[i]=1;
	for(int i=1;i<=n-1;i++){
		g[0]=1;
		for(int j=N;j>=1;j--){
			if(j-a[i]>=0) g[j]=(g[j]+g[j-a[i]])%MOD;
		}
		ans=(ans-g[a[i+1]]+MOD)%MOD;
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ans=(qpow(2,n)-2+MOD)%MOD;
	cal();
	cout<<ans;
	return 0;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10
*/

