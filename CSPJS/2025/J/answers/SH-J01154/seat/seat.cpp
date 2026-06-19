#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;

int n,m;
int a[N];

bool cmp(int& a,int& b) {
	return a > b;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++) {
		cin >> a[i];
	}
	int s = a[1];
	sort(a+1,a+n*m+1,cmp);
	int i;
	for(i = 1;i <= n*m;i++) {
		if(a[i] == s)
			break;
	}
	int sc = i;
	int c = sc/n+(sc % n == 0 ? 0 : 1), r1;
	if(c % 2 == 1) {
		r1 = (sc%n == 0) ? n : sc%n;
	} else {
		r1 = (sc%n == 0) ? 1 : (n-sc%n+1);
	}
	cout << c << " " << r1 << "\n";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
