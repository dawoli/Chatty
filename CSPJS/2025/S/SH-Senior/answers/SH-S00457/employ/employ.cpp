#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n=0,ans=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%MOD;
	}
	cout<<ans%MOD;
	return 0;
}
