#include <bits/stdc++.h>
using namespace std;

const int maxn=100010;
int r[maxn];
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&r[i]);
	}
	sort(r+1,r+1+n);
    int p=1;
    for (int q=1;q<=n;q++) {
    	if (r[p]<r[q]) {
    		p++;
		}
	}
	printf("%d\n",n-p+1);
	return 0;
}
