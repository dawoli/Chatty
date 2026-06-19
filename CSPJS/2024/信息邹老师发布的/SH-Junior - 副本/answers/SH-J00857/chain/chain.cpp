#include <bits/stdc++.h>
using namespace std;
int rand(int a, int b) {
	a = (a % (b + 2)) * (a % (b + 1));
	a %= b;
	return a % 2;
}
int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int T;
	cin>>T;
	for (int i = 1; i <= T; ++i) cout<<rand(rand(4571, i * (i + 10)) * rand(3545, (i + 10) * (i + 15)), rand(3842, i * (i + 5)) + i * (i + 10))<<endl; 
	return 0;
}
