#include<bits/stdc++.h>
#define int uint64_t
using namespace std;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	int a[n];for(int i=0;i<n;i++) cin>>a[i];
	int ans=0;
	for(int i=0;i<(1ull<<n);i++){ 
		int mx=0,cnt=0,sum=0;
		for(int j=0;j<n;j++) if((i>>j)%2)
			cnt++,mx=max(mx,a[j]),sum+=a[j];
		if(sum>2*mx&&cnt>2)ans++,ans%=998244353;
	}
	cout<<ans;
	return 0;
} 
