#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,t;
struct node{int a,b,c;}a[N];

priority_queue<int> pq;

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;while(!pq.empty()) pq.pop();
		int maxn1=0,maxn2=0,maxn3=0;
		long long ans=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>a[i].b&&a[i].a>a[i].c) maxn1++;
			if(a[i].b>a[i].c&&a[i].b>a[i].a) maxn2++;
			if(a[i].c>a[i].b&&a[i].c>a[i].a) maxn3++;
			ans+=max(a[i].a,max(a[i].b,a[i].c));
		}
		if(maxn1<=n/2&&maxn2<=n/2&&maxn3<=n/2) {
			cout<<ans<<'\n';
			continue;
		}
		if(maxn1>n/2) {
			for(int i=1;i<=n;i++) {
				if(a[i].a>a[i].b&&a[i].a>a[i].c) pq.push(max(-a[i].a+a[i].b,-a[i].a+a[i].c));
			}
			while(pq.size()>n/2) ans+=pq.top(),pq.pop();
		}
		else if(maxn2>n/2) {
			for(int i=1;i<=n;i++) {
				if(a[i].b>a[i].c&&a[i].b>a[i].a) pq.push(max(-a[i].b+a[i].c,-a[i].b+a[i].a));
			}
			while(pq.size()>n/2) ans+=pq.top(),pq.pop();
		}
		else if(maxn3>n/2) {
			for(int i=1;i<=n;i++) {
				if(a[i].c>a[i].b&&a[i].c>a[i].a) pq.push(max(-a[i].c+a[i].a,-a[i].c+a[i].b));
			}
			while(pq.size()>n/2) ans+=pq.top(),pq.pop();
		}cout<<ans<<'\n';
	}
	return 0;
}
