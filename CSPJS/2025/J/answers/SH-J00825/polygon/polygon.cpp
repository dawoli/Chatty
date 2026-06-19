#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,ans;
int a[5003];
void solve(int mx,int sum,int i,int num) {
	if(i>n+1) return ;
	if(num>=3&&sum>mx*2) {
		ans++;
		ans%=998244353;
//		cout<<sum<<" "<<mx<<" "<<i<<" "<<num<<endl;
		solve(max(mx,a[i]),sum+a[i],i+1,num+1);
	}
	else {
		solve(mx,sum,i+1,num);
		solve(max(mx,a[i]),sum+a[i],i+1,num+1);	
	}
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool A=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	solve(0,0,1,0);
	cout<<ans;
	return 0;
}
