#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,r[N],bkt[N],p[N],ab[N],nP;
void solve() {
	if (nP==1) {
		printf("%d\n",n);
		return;
	}
	int pos=1,ptr=2;
	int cnt=0;
	while (1) {
		if (ab[ptr]==0) ptr++;
		if (ptr==pos) ptr++;
		if (ptr>nP) break;
		if (ab[ptr]>=p[pos]) {
			ab[ptr]-=p[pos];
			cnt+=p[pos];
			p[pos]=0;
			pos++;
		} else {
			p[pos]-=ab[ptr];
			cnt+=ab[ptr];
			ab[ptr]=0;
			ptr++;
		}
	}
	printf("%d\n",n-cnt); 
}
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&r[i]),bkt[r[i]]++;
	int ans=n;
	sort(r+1,r+1+n);
	r[0]=-10000;
	for (int i=1;i<=n;++i)
		if (r[i]!=r[i-1]) p[++nP]=bkt[r[i]],ab[nP]=p[nP];
//	for (int i=1;i<=nP;++i) cout<<p[i]<<" ";puts("");
	solve();
	return 0;
}
//易错：问的是存活而不是死了几个！！ 
