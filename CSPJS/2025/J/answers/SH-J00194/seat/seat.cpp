#include<bits/stdc++.h>
using namespace std;
int n,m;
struct scr{
	int sc;
	bool check;
} a[101];
bool cmp(scr a, scr b) {
	return a.sc > b.sc;
}
int main() {
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	a[0].check = true;
	for (int i = 0; i < n*m; i++) cin >> a[i].sc;
	sort(a,a+n*m,cmp);
	for (int i = 0; i < n*m; i++) {
		if (a[i].check) {
			int st = i/m+1;
			if (st%2 == 1) cout << st << " " << i%m+1;
			else cout << st << " " << m-i%m;
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
