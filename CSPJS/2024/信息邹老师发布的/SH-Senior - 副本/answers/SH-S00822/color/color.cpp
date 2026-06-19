#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 114514
int n;
bool fl[N];//0À¶1ºì 
int a[N];
ll maans;
void dfs(int p) {
	if(p>n) {
		int pr=0,pb=0;
		ll ans=0;
		for(int i=1;i<=n;i++) {
			if(fl[i]) {
				ans+=(a[pr]==a[i])*a[i];
				pr=i;
			}
			else {
				ans+=(a[pb]==a[i])*a[i];
				pb=i;
			}
		}
		maans=max(maans,ans);
		return;
	}
	dfs(p+1);
	fl[p]=true;
	dfs(p+1);
	fl[p]=false;
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		maans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=25) {
			dfs(1);
			cout<<maans<<"\n";
		}
	}
	return 0;
}

