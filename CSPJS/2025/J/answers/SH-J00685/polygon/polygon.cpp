#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;
const int mod=998244353;
int n,a[N],sum,cnt2,cnt,maxx,ans1,ans2,ans;

int c(int x,int y){
	ans1=ans2=1;
	y=min(y,x-y);
	for(int i=1;i<=y;++i){
		ans1*=(n-i);
	}
	for(int i=1;i<=y;++i){
		ans2*=i;
	}
	return ans1/ans2%mod;
}

int solve2(){
	for(int i=3;i<=n;++i){
		ans+=c(n,i);
		ans%=mod;
	}
	return ans;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[n]==1&&n>=500){
		cout<<solve2();
		return;
	}
	for(int i=1;i<(1<<n);++i){
		sum=cnt2=maxx=0;
		for(int j=0;j<n;++j){
			if(i&(1<<j)){
				sum+=a[j+1];
				cnt2++;
				maxx=max(maxx,a[j+1]);
			}
		}
		if(cnt2<=2) continue;
		if(sum>maxx*2){
			cnt++;
			cnt%=mod;
		}
	}
	cout<<cnt;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
