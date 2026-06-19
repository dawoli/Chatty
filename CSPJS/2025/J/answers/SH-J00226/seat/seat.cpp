#include <iostream>
using namespace std;

int n,m,a1,a,p=1;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> a1;
	for (int i=1;i<n*m;i++) {
		cin >> a;
		if (a>a1) p++;
	}
	int c=(p-1)/n+1;
	int r=p-(c-1)*n;
	if (c%2==0) {
		r=n-r+1;
	}
	cout << c << ' ' << r;
} 
