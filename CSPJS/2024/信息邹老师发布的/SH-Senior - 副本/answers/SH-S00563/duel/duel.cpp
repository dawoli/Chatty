#include <bits/stdc++.h>
using namespace std;
const int maxn=100009;
int n,r[maxn];
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>r[i];
	sort(r+1,r+1+n);
	int len=1,ans=0;
	for(int i=2; i<=n+1; i++) {
		if(r[i]==r[i-1]) len++;
		else {
			ans=max(ans,len);
			len=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}

