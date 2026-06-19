#include<bits/stdc++.h>
using namespace std;
const int N = 998244353;
int n, m;
string s;
int h;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++) cin >> h;
	int res = 1;
	for(int i = 1; i <= n; i++){
		res = (res % N) * i;
		res %= N;
	}
	cout << res << endl;
	return 0;
}
