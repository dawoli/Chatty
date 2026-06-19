#include<bits/stdc++.h>
#define int long long
using namespace std;
int C(int n,int k){
	int _n=n,ret=1;
	for(int i=1;i<=k;i++){
		ret*=_n;
		_n--;
	}
	for(int i=k;i>=1;i--){
		ret/=i;
	}
	return ret;
}
signed main(){
	freopen("test.in","r",stdin);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=C(n,i);
	}
	cout<<ans;
	return 0;
}