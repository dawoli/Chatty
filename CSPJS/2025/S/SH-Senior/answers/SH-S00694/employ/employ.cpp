#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		long long t;
		cin>>t;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
