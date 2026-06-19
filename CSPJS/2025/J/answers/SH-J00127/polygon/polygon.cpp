#include<iostream>
#include<algorithm>
#define M 998244353
using namespace std;

int n, maxai = 0;
int a[10000] = {0};

long long twopower(int k){
	if(k >= 2){
		if(k % 2 == 1){
			long long tmp = twopower(k / 2);
			return (2 * tmp * tmp) % M;
		}else{
			long long tmp = twopower(k / 2);
			return (tmp * tmp) % M;
		}
	}
	if(k == 1) return 2;
	return 1;
}

int dfs(int depth, int suma, int maxa, int k){
	if(depth == n + 1){
		if(k <= 2) return 0;
		if(maxa * 2 >= suma) return 0;
		return 1;
	}
	if(suma > 2 * maxa){
		return twopower(n - depth + 1);
	} 
	return (dfs(depth + 1, suma + a[depth], max(maxa, a[depth]), k + 1) + dfs(depth + 1, suma, maxa, k)) % 998244353;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxai = max(maxai, a[i]);
	}
	sort(a + 1, a + n + 1, greater<int>() );
	if(maxai == 1){
		long long o = (n * (n - 1) / 2) % M + n + 1, p = twopower(n);
		cout << (p - o) % M;
	}else{
		cout << dfs(1, 0, 0, 0);
	}
	
	return 0;
}
