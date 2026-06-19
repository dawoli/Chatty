#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n;
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	
	return 0; 
}
