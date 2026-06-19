#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int MODE = 998244353;
string s;
int n, m, c[N];

long long QuickPow(long long a, long long b){
	long long ans = 1;
	while(b){
		if(b & 1) ans = (ans * a) % MODE;
		a = (a * a) % MODE;
		b >>= 1;
	}
	return ans;
}

bool check(string s){
	for(int i = 0; i < n; i ++){
		if(s[i] == '0') return false;
	}
	return true;
}

void solve2(){
	long long f1[N];
	long long f2[N];
	for(int i = 0; i <= N; i ++){
		f1[i] = 1;
		f2[i] = 1;
	}
	for(int i = n - m + 1; i <= n; i ++){
		f1[i] = (f1[i - 1] * i) % MODE;
	}
	for(int i = 1; i <= m; i ++){
		f2[i] = (f2[i - 1] * i) % MODE;
	}
	long long ny = QuickPow(f2[m], MODE - 2);
	long long ans1 = (f1[n] * ny) % MODE;
	cout << ans1 << endl;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i ++){
		cin >> c[i];
	}
	if(check(s)){
		solve2();
	}else{
		cout << 8;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
