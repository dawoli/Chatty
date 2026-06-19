#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int st[5005],n;
long long ans=0;
long long H(int a,int b){
	long long asw;
	long long ajc=1,bjc=1;
	for(int i=a;i>a-b;i--){
		ajc*=i;
		ajc%=MOD;
	}
	for(int i=1;i<=b;i++){
		bjc*=i;
		bjc%=MOD;
	}
	asw=(ajc/bjc)%MOD;
	return asw;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>st[i];
	if(n<=3){
		if(n<3)
			cout<<0;
		else{
			sort(st,st+n);
			if(st[0]+st[1]>st[2]) cout<<1;
			else cout<<0;
		}
	}
	else{
		for(int x=3;x<=n-3;x++) ans=(ans+H(n,x)*2)%MOD;
		ans=(ans+n*(n-1)/2+n+1)%MOD;
		cout<<ans;
	}
	return 6&1;
}
