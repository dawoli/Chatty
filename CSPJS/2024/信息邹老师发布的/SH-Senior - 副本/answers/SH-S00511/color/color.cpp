#include <bits/stdc++.h>
using namespace std;

long long a[210000];
int c[210000];
bool vis[210000][3];
long long n,t,ma=0;

void dfs(long long num, int color, long long ad) {
	if ((num-1)==n) {
		ma = max(ma,ad);
		return;
	}
	c[num]=color;
	long long near=0, toadd=0;
	for (long long x=1;x<num;x++) {
		if (c[x]==c[num]) near=x;
	}
	if (near!=0) {
		if (a[num]==a[near]) toadd=a[num];
	}
	dfs(num+1, 1, ad+toadd);
	dfs(num+1, 0, ad+toadd);
}

int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	for (long long z=1;z<=t;z++) {
		ma=0;
		cin >> n;
		for (long long i=1;i<=n;i++) cin >> a[i];
		dfs(1,1,0);
		//dfs(1,0,0);
		cout << ma << endl;
	}
	return 0;
}
