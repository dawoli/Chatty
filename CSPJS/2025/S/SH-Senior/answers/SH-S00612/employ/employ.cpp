#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	char c[n];
	for(int i=0;i<n;i++) cin>>c[i];
	/*
	for(int i=0;i<n;i++) cout<<c[i]<<" ";
	*/
	int nx[n];
	int ans;
	for(int i=0;i<n;i++) cin>>nx[i];
	if(m==1) ans=n;
	else{
		ans=m*(m+1)/2;
	}
	cout<<ans%MOD;
	return 0;
}
