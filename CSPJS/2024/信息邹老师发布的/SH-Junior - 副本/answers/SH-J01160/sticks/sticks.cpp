// J 组T1+T2+暴力分就是1=
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using ui64 = unsigned long long;
#define lym12 return
#define AKIOI 0

const string sv[15] = {
	"", "", "", "", "", "", "", "8", "10", "18", "22", "20", "28", "68", "88"
}; const int q[] = {0, -1, 1, 7, 4, 2, 6};

int n;
void solve(){
	cin >> n;
	if (n <= 6){
		cout << q[n] << '\n';
	}else if (n == 17) cout << "200\n";
	else{
		int x = n % 7; x += 7;
		cout << sv[x];
		for (int i = 0; i < n / 7 - 1; i ++) cout << 8;
		cout << '\n';
	}
}

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cout.tie(0);	
	
	int T;
	cin >> T;
	while (T --) solve();
	
	lym12 AKIOI; // 遗憾离场.cpp 20pts
}
