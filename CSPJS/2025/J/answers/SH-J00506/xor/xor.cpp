#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int p[500005];
int t[500005];
vector<int> w[1200005];
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		p[i]=p[i-1]^a[i];
	}
	for(int i=0;i<=n;i++) {
		t[i]=1e9;
	}
	for(int i=0;i<=n;i++) {
		int x=p[i]^k;
		for(int j=0;j<w[x].size();j++) {
			t[w[x][j]]=i;
		}
		w[x].clear();
		w[p[i]].push_back(i);
	}
	int ans=0;
	int lst=n+1;
	for(int i=0;i<=n;i++) {
		if(i==lst) {
			ans++;
			lst=n+1;
		}
		lst=min(lst,t[i]);
		//if(i==4) cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
} 
