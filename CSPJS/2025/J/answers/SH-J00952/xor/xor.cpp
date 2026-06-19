#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0;
int jydg[500005];
bool check(int p) {
	for (int i=1;i<=n;i++) {
		if (a[i]!=1) {
			return false;
		}
	}
	return true;
}
void cs(int r) {
	for (int i=1;i<=r;i++) {
		cout << jydg[i] << " ";
	}
	return;
}

int dfs(int l) {
	if (jydg[l]==-1) {
		if (l>n) {
			return 0;
		}
		int cnt=0,pos=0,ss=0;
		bool f=false,f2=false;
		for (int i=l;i<=n;i++) {
			if (cnt!=k) {
				cnt = cnt^a[i];
				f2=true;
			} if (cnt == k && f2==true) {
				f=true;
				pos = i;
				break;
			}
		}
		if (f == true) {
		ss = dfs(pos+1)+1;
		}
		jydg[l] = max(ss,dfs(l+1));
	} 
	return jydg[l];
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
	memset(jydg,-1,sizeof(jydg));
	if (check(n)) {
		ans = n/2;
	} else {
		ans = dfs(1);
		//cs(n);
	}
	cout << ans;
	return 0;
}
