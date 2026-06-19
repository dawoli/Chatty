#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int M=998244353;
int inp[5005],n;
long long ans=0;
vector<int> a;
int jc(int sz) {
	if (sz==0 || sz==1) {
		return 1;
	} else {
		return sz*jc(sz-1);
	}
}
int zuhe(int zong,int xuan) {
	long long fenzi=jc(zong);
	long long fenmu=(jc(xuan)*jc(zong-xuan))%M;
	return (fenzi/fenmu)%M;
}
bool check(int n) {
	for (int i=0;i<n;i++) {
		if (inp[i]!=1) {
			return false;
		}
	}
	return true;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++) {
		cin >> inp[i];
	}
	if (check(n)) {
		for (int i=3;i<=n;i++) {
			ans = (ans+zuhe(n,i))%M;
		}
		cout << ans;
	} else {
		long long len=1<<(n+1);
		for (long long i=1;i<len;i++) {
			int cnt=0;
			for (int j=n-1;j>=0;j--) {
				if ((i>>j) & 1 == 1) {
					cnt++;
					a.push_back(inp[j]);
				}
			}
			if (cnt>=3) {
				long long ss=0,maxn=-1;
				for (int i:a) {
					ss+=i;
					if (i>maxn) {
						maxn = i;
					}
				}
				if (ss>2*maxn) {
					ans = ans%M+1;
				}
			}
			a.clear();
		}
		cout << ans/2;
	}
	return 0;
}
