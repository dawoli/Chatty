#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
int r[N];
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&r[i]);
	}
	sort(r+1,r+n+1);
	int j=1;
	int ans=n;
	for(int i=1;i<=n;i++) {
		if(r[i]>r[j]) {
			ans--;
			j++;
		}
	}
	cout << ans;
	return 0;
}
