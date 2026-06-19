#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m; cin>>n>>m;
	string s; cin>>s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x; 
	} long long ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		} 
	
	
	cout<<ans;
} 
