#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,mod=998244353,ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	ans=ans*i%mod;
	cout<<ans;
	return 0;
}
