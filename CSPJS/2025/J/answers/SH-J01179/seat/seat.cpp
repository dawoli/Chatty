#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n, m;
int a[1110], sa[1110], rnk[1110], r[1110];

int computeX(int i) {
	return ((((i+n-1)/n) % 2 == 0)*(n-1)+(1-2*(((i+n-1)/n) % 2 == 0))*(i+n-1)%n)+1;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i=1;i<=n*m;i++) scanf("%d",&a[i]),sa[i] = a[i];
	for (int i=1;i<=n*m;i++) r[a[i]] = i;
	sort(sa+1, sa+n*m+1, greater<int>());
	for (int i=1;i<=n*m;i++) rnk[r[sa[i]]] = i;
	// cout<<rnk[1]<<endl;
	int reversed = (((rnk[1]+n-1)/n) % 2 == 0);
	printf("%d %d\n",(rnk[1]+n-1)/n,computeX(rnk[1]));
//	for (int i=1;i<=n*m;i++) {
//		cerr<<(i+n-1)/n<<" "<<computeX(i)<<endl;
//		if (i>1 && (i+n-1)/n == (i+n-2)/n) {
//			if ((i+n-1)/n%2 == 0) {if (computeX(i) >= computeX(i-1)) return 101;}
//			else if (computeX(i) <= computeX(i-1)) return 102;
//		} else if (i>1 && ((i+n-1)/n != (i+n-2)/n + 1 || computeX(i) != computeX(i-1))) return 103;
//	}
	return 0;
}
