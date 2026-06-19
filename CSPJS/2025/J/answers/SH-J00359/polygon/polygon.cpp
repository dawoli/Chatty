#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5009;
const ll MOD=998244353;
ll a[N];
ll f(int x){
	if(x==0)return 1;
	else return x*f(x-1)%MOD;
}
ll C(int n,int m){
	return ((f(m)/f(m-n))/f(n))%MOD;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,sum=0;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sum=C(3,n)%MOD;
	for(int i=4;i<=n;i++)sum=(sum+C(i,n))%MOD;
	cout<<sum%MOD; //max a[i]=1
	return 0;
}
