#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n,r[N],ans;
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&r[i]);
	sort(r+1,r+n+1);
	ans=n;
	for (int i=1,j=1;i<=n;i++)
		if (r[j]<r[i]) j++, ans--;
	printf("%d\n",ans);
	return 0;
}
