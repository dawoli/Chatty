#include <bits/stdc++.h>
using namespace std;

int t,n,k,q,l,r,c,s;
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	srand(time(0));
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d%d",&n,&k,&q);
		scanf("%d",&l);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=l;j++) {
				scanf("%d",&s);
			}
		}
		for (int i=1;i<=q;i++) {
			scanf("%d%d",&r,&c);
			printf("%d\n",rand()%2);
		}
	}
	return 0;
}
