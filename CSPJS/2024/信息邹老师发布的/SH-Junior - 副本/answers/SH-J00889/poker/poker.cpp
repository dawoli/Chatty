#include <iostream> 
#include <cstdio>
#include <algorithm>
using namespace std;

struct pok {
	char col,poi;
}a[57];

bool cmp(pok a,pok b) {
	if (a.col != b.col) {
		return a.col<b.col;
	} else {
		return a.poi<b.poi;
	}
}

int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++) {
		string x;
		cin >> x;
		a[i].col = x[0];
		a[i].poi = x[1];
	}
	sort(a+1,a+n+1,cmp);
	int ans=52;
	for (int i=1;i<=n;i++) {
		if ((a[i].col == a[i-1].col) && (a[i].poi == a[i-1].poi)) {
			continue;
		} else {
			ans --;
		}
	}
	cout << ans;
	return 0;
}
