#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
bool could3(int a, int b, int c) {
	int mx = max(max(a,b),c);
	if (a+b+c > mx*2) return true;
	else return false;
}
int main() {
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n==3) {
		if (could3(a[0],a[1],a[2])) cout << 1;
		else cout << 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
