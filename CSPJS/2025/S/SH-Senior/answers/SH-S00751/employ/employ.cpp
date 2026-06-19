#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,l,mod=998244353;
	long long ans=1;
	string s;
	cin>>n>>m>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]!='1'){
			cout<<m;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans;
	return 0;
}

