#include<bits/stdc++.h>

using namespace std;
const int N = 550;
char s[N];
int cc[N], n, m, ss[N], a[N];
long long sum, mod = 998244353;
int if0, fl;
long long ans, b[20], v[20];

void dfs(int dep){
	if(dep == n){
		fl = 0;int sumsum = 0;
		for(int i = 1; i <= n; i++){
			if(sumsum >= cc[i]){
				sumsum++;
			}else{
				fl++;
			}
		}
		if(fl >= m) ans++;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(v[i]) continue;
		b[dep] = cc[i];
		v[i] = 1;
		dfs(dep+1);
		v[i] = 0;
	}
	return;
}


int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> cc[i];
		if(cc[i] == 0) if0++;
		if(cc[i] == n) sum++;
	}
	sort(cc+1, cc+n+1);
	for(int i = 0; i < n; i++){
		ss[i+1] = s[i]-'0';
		sum += ss[i+1];
		a[i+1] = a[i]+ss[i+1];
	}
	if(n-if0 < m){
		cout << 0;
		return 0;
	}
	if(sum < m){
		cout << 0;
		return 0;
	}
	if(sum == n){
		long long sum2 = 1;
		for(int i = 1; i <= n; i++){
			sum2 *= i;
			sum2 %= mod;
		}
		cout << sum2;
		return 0;
	}
	if(n <= 18){
		dfs(1);
		cout << ans;
		return 0;
	}
	if(m == n){
		if(if0){
			cout << 0; return 0;
		}
		if(sum < n){
			cout << 0; return 0;
		}
	}
	if(m == 1){
		if(if0 == n){
			cout << 0; return 0;
		}
	}
	sum = 1;
	for(int i = 1; i <= n; i++){
		sum *= i; sum %= mod;
	}
	cout << sum;
	return 0;
}
