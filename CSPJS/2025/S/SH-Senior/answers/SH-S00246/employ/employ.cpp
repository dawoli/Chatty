#include <bits/stdc++.h>
using namespace std;
#define debug cout<<"RecNana37mi"<<endl
#define ll long long

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ3.in","r",stdin);
	int n,m,r;
	ll t=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>r;
		if(r!=0){
			t++;
		}
	}
	if(t==0){
		cout<<0<<endl;
		return 0;
	}
	ll ans=1;
	for(ll i=t-m+1;i<=t;i++){
		ans=ans*i%998244353;
	}
	cout<<ans%998244353;
	return 0;
}

