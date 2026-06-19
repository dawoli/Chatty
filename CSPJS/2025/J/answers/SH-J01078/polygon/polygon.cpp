#include <bits/stdc++.h>
using namespace std;
int n;
int lim;
int a[5007];
int p;
int lq;
long long ans;
long long pos;
struct xdc{
	long long sc;
	int kn;
}qe[30000007];
long long mod = 998244353;
void dfqe(int hi){
	if(hi == lim) return;
	int co = p; 
	for(int i = 1;i<=co;i++){
		p++;
		qe[p].sc = qe[i].sc + a[hi];
		qe[p].kn = qe[i].kn + 1;
	}
	dfqe(hi + 1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a + 1,a + n + 1);
	if(n == 3){
		if(a[1] + a[2] + a[3] > 2 * a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i = 3;i<=n;i++){
		memset(qe,0,sizeof(qe));
		p = 1;
		pos = 0;
		qe[1].sc = 0;
		qe[1].kn = 0;
		lim = i;
		dfqe(1);
		for(int li = 1;li<=p;li++){
			if(qe[li].sc + a[i] > 2*a[i] && qe[li].kn >= 2) pos++; 
		}
		ans += pos%mod;
		ans %= mod;
	}
	cout<<ans;
	return 0;
} 

