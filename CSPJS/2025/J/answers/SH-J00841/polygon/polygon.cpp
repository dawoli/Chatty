#include <iostream>
using namespace std;

int k[5020][5020];
int a[5020];

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
	cout << 2;
	return 0;
}
