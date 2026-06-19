#include <bits/stdc++.h>
using namespace std;

string a[55];
int st[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string ans = "-1";

bool cmp(string s, string t){
	if (s.size() != t.size())
		return s.size() < t.size();
	else
		return s < t;
}

void dfs(int step, int num, string s){
	if (ans != "-1" && cmp(ans, s)) return;
	if (num == 0){
		if (ans == "-1") ans = s;
		else if (cmp(s, ans))
			ans = s;
		return;
	}
	for (int i = 0+(step==1); i <= 9; i++){
		if (num >= st[i]){
			dfs(step+1, num-st[i], s+char(i+'0'));
		}
	}
	return;
}

void solve(){
	int n;
	cin >> n;
	if (a[n] != ""){
		cout << a[n] << endl;
	}
	else if (n % 7 == 0){
		for (int i = 1; i <= n/7; i++)
			cout << 8;
		cout << endl;
	} else if (n % 7 == 1 && n >= 15){
		cout << 10;
		for (int i = 1; i <= n/7-1; i++)
			cout << 8;
		cout << endl;
	} else{
		ans = "-1";
		dfs(1, n, "");
		cout << ans << endl;
		a[n] = ans;
	}
}

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		solve();
	}
	return 0;
}
