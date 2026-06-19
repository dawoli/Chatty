#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;

int T,n;
priority_queue<int,vector<int>,greater<int>/**/> pq;
int ca=0,cb=0,cc=0;
int a[MAXN][10]={};
int m[MAXN]={};
int f[MAXN]={};
long long ans=0;

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		ca=0; cb=0; cc=0;
		for(register int i=1;i<=n;i++) {
			m[i]=-1;
		}
		while(!pq.empty()) {
			pq.pop();
		}
		
		for(register int i=1;i<=n;i++) {
			for(register int j=1;j<=3;j++) {
				cin>>a[i][j];
				m[i]=max(m[i],a[i][j]);
			}
			if(m[i]==a[i][1]) {
				f[i]=1; ca++;
			}
			else if(m[i]==a[i][2]) {
				f[i]=2; cb++;
			}
			else if(m[i]==a[i][3]) {
				f[i]=3; cc++;
			}
		}
		int ans=0;
		for(register int i=1;i<=n;i++) {
			ans=ans+a[i][f[i]];
		}
		if(ca>n/2) {
			int k=ca-n/2;
			for(register int i=1;i<=n;i++) {
				if(f[i]==1) {
					pq.push(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
				}
			}
			for(register int i=1;i<=k;i++) {
				ans=ans-pq.top();
				pq.pop();
			}
		}
		if(cb>n/2) {
			int k=cb-n/2;
			for(register int i=1;i<=n;i++) {
				if(f[i]==2) {
					pq.push(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
				}
			}
			for(register int i=1;i<=k;i++) {
				ans=ans-pq.top();
				pq.pop();
			}
		}
		if(cc>n/2) {
			int k=cc-n/2;
			for(register int i=1;i<=n;i++) {
				if(f[i]==3) {
					pq.push(min(a[i][3]-a[i][2],a[i][3]-a[i][1]));
				}
			}
			for(register int i=1;i<=k;i++) {
				ans=ans-pq.top();
				pq.pop();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
