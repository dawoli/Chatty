#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
ll n, m, a[N];
string s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.size();
	s = " " + s;
	for(ll i = 1; i <= n; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++m] = s[i] - '0';
		}
	}
	sort(a+1, a+m+1);
	for(ll i = m; i >= 1; i--){
		cout << a[i];
	}
	cout << endl;
	return 0;
}
