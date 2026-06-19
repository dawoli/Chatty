#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll cnt[509];
ll a[509];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int flag=0;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c=='0'){
			flag=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0ll){
			flag=1;
		}
	}
	if(flag==1){
		cout<<0;
	}
	else {
		ll ans=1ll;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353ll;
		}
		cout<<ans;
	}
	return 0;
}
