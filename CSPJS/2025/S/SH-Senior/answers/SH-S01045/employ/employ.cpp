#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505]; 
long long ans=1,mod=998244353;
int cnt=0;
string s;
int main(){
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (long long i=1;i<=n;i++){
		cin>>c[i];
		if (c[i]==0) cnt++;
	}
	if (cnt>=n-m){
		cout<<0;
		return 0;
	}
	for (long long i=1;i<=n;i++){
		ans=ans*i;
		ans=ans%mod;
	}
	cout<<ans;
	return 0;
} 
