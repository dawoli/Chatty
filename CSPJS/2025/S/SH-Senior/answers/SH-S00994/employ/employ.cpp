#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long ans=1;int n,m;string s;int x;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	x=n;
	cin>>s;
//	cout<<s<<"\n";
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		if(a==0) x--;
	}
//	cout<<x<<" ";
	for(int i=x;i>=1;i--){
		ans=(ans*i)%mod;
//		cout<<ans<<" ";
//cout<<mod;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
