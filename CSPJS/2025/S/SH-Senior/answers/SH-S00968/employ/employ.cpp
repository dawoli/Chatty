#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
signed main(){
	freopen("emlpoy.in","r",stdin);
	freopen("emlpoy.out","w",stdout);
	int n,m,num=0;
	cin>>n>>m;
	string tf;
	cin>>tf;
	int l[n];
	for (int i=0;i<n;i++){
		cin>>l[i];
		if (l[i]==0){
			num++;
		}	
	}
	if (n-num<m){
		cout<<0;
		return 0;
	}
	int ans=1;
	for (int i=1;i<=n;i++){
		ans=ans*i;
		ans=ans%mod;
	}
	cout<<ans;
	return 0;
}
