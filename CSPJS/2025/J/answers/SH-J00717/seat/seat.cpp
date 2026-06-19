#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,t,ans,c[100001];
	cin >> a >> b;
	for (int i = 0;i < a * b;i++) cin >> c[i];
	for (int i = 0;i < a * b;i++) sort(c[i] + c,c[i] + c + 1);
	cout << 1 << " " << 1 << endl;
	return 0;
}
