#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	string s;
	cin >> n >> m;
	cin >> s;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	long long sum = 1;
	for(int i = n;i > 0;i--){
		sum *= i % 998244253l;
	}
	cout << sum;
	return 0;
}
