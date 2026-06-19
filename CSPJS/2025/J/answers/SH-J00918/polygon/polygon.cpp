#include<bits/stdc++.h>
using namespace std;

long long a[5009],vst[5009],cnt=0;
int n;
long long MOD=998244353;

void dfs (int x, int c) {
	if (c==n+1) {
		long long last=0,ans=0; 
		for (int i=1; i<=n; i++) {
			if (vst[i]==1) {
				ans+=a[i];
				last=a[i];
			}
		}
		if (ans>last*2) {
			cnt=(cnt+1)%MOD;
		}
		return;
	}
	
	vst[x]=1;
	dfs(x+1,c+1);
	vst[x]=0;
	dfs(x+1,c+1);
}

int main ()
{
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);

	cin>>n;

	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	sort (a+1,a+n+1);

	dfs(1,1);

	cout<<cnt%MOD;
	
	return 0;
}
