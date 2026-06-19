#include<bits/stdc++.h>
using namespace std;
long long n,a[5],cnt0,cnt1,cnt2;
multiset<long long> d[6];
void init() {
	cnt0=cnt1=cnt2=0;
	d[0].clear();
	d[1].clear();
	d[2].clear();
}
void solve() {
	init();
	cin>>n;
	long long ans=0;
	long long test=0;
	for(int i=1;i<=n;i++) {
		cin>>a[1]>>a[2]>>a[3];
		test+=max(a[1],max(a[2],a[3]));
		if(a[1]>=a[2]&&a[1]>=a[3]) {
			ans+=a[1];
			cnt0++;
			d[0].insert(min(a[1]-a[2],a[1]-a[3]));
		}
		else if(a[2]>=a[1]&&a[2]>=a[3]) {
			ans+=a[2];
			cnt1++;
			d[1].insert(min(a[2]-a[1],a[2]-a[3]));
		}
		else {
			ans+=a[3];
			cnt2++;
			d[2].insert(min(a[3]-a[1],a[3]-a[2]));
		}
		//cout<<ans<<" "<<test<<"\n";
	}
	if(cnt0>n/2) {
		auto it=d[0].begin();
		int tmp=cnt0-n/2;
		while(tmp--) {
			ans-=*it;
			it++;
		}
	}
	else if(cnt1>n/2) {
		auto it=d[1].begin();
		int tmp=cnt1-n/2;
		while(tmp--) {
			ans-=*it;
			it++;
		}
	}
	else if(cnt2>n/2) {
		auto it=d[2].begin();
		int tmp=cnt2-n/2;
		while(tmp--) {
			ans-=*it;
			it++;
		}
	}
	cout<<ans<<"\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		solve();
	}
	return 0; 
}
//15:02лгак 
