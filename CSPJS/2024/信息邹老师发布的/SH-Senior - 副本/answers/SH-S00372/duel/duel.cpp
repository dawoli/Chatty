#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,r[N];
bool all12() {
	for (int i=1;i<=n;++i) {
		if (r[i]!=1&&r[i]!=2) return false;
	}
	return true;
}
namespace get12{
	void solve() {
		int cnt1=0,cnt2=0;
		for (int i=1;i<=n;++i) {
			if (r[i]==1) ++cnt1;
			else ++cnt2;
		}
		printf("%d",max(cnt1,cnt2));
	}
}
namespace all {
	bool alive[N];
	void solve() {
		for (int i=1;i<=n;++i) {
			alive[i]=true;
		}
		sort(r+1,r+n+1);
		int dead=0;
		for (int j=2;j<=n;++j) {
			if (!alive[j]) continue; 
			if (r[j]>r[dead+1]) {
				++dead;
				alive[dead]=false;
			}
		}
		int res=0;
		for (int i=1;i<=n;++i) {
			res+=alive[i];
		}
		printf("%d",res);
	}
}
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		scanf("%d",&r[i]);
	}
	all::solve();
	return 0;
}

