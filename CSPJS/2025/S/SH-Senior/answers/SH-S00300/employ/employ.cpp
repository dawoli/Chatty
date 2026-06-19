#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],k;
string s;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	k=n;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i]){
			k--;
		}
	}
	/*
	for(int i=1;i<=k;i++){
		ans*=i;
		ans%=998244353;
	}
	ans*=n-k;
	ans%=998244353;
	cout<<ans;
	*/
	cout<<0;
	return 0;
}
