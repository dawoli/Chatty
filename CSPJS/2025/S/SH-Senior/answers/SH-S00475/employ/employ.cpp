#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,q;
	cin>>n>>q;
	long long int ans=1,cnt=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x==0) cnt++;
		ans*=i;
		ans%=998244353;
	}
	if(cnt+q>n) ans=0;
	cout<<ans;
	return 0;
}
