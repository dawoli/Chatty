#include <bits/stdc++.h>
using namespace std;
int a[5005], n;
int f(int x){
	long long sum = 1;
	for(int i = 0;i < x;i++){
		sum *= 2;
		sum %= 998244353;
	}
	return sum % 998244353;
}
long long t(int x, int y){
	int sum = 0;
	for(int i = y - 1;i >= 0;i--){
		if(a[i] + a[y] > x){
			sum += (f(i) % 998244353);
		}else{
			sum += t(x - a[y] - a[i], i) % 998244353;
		}
	}
	return sum % 998244353;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	long long sum = 0;
	for(int i = 0;i < n;i++){
		cin >> a[i]; 
	}
	sort(a, a + n);
	for(int i = n - 1;i >= 2;i--){
		for(int j = i - 1;j >= 1;j--){
			sum += t(a[i], j) % 998244353;
		}
	}
	cout << sum % 998244353;
	return 0;
} 
