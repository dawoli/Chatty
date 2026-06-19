#include<bits/stdc++.h>
using namespace std;

// 于是转身向山里走去 
const long long MOD=998244353;
long long jiecheng(int x) {
	long long ans=1;
	for(int i=2; i<=x; i++)ans=(ans*i)%MOD;
	return ans;
}

int a[5005], mx=0;
long long sum=0, ans=0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		mx=max(mx, a[i]);
		sum+=a[i];
	}
	if(n<3) {
		cout<<0;
		return 0;
	}
	if(n==3) {
		if(sum>2*mx)cout<<1;
		else cout<<0;
		return 0;
	}
	if(mx==1) {
		int cnt=0;
		long long ans=0;
		for(int i=1; i<=n; i++) {
			if(a[i]==1)cnt++;
		}
		long long jccnt=jiecheng(cnt);
		for(int i=3; i<cnt; i++) {
			ans+=(jccnt/(jiecheng(cnt-i)*jiecheng(i)));
		}
		ans++;
		cout<<ans%MOD;
		return 0;
	}
	for(int i=1; i<n-1; i++) {
		for(int j=i+2; j<=n; j++) {
			int pmx=0;
			long long psum=0;
			for(int k=i; k<=j; k++) {
				pmx=max(pmx, a[k]);
				psum+=a[k];
			}
			if(psum>2*pmx)ans++;
		}
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}
// 于是转身向大海走去 
