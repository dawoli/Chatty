#include <bits/stdc++.h>
using namespace std;

int a[10]={6,2,5,5,4,5,6,3,7,6};
int t;
int n;
string ans;

void dfs(int la, string cnt){
	if (la==0){
		if (cnt[0]!='0'){
			if (cnt.size() < ans.size() or ans.size()==0)ans = cnt;
			else if (cnt.size() == ans.size() and cnt < ans) ans = cnt;
		}
		return;
	}
	for (int i = 9; i >= 0; i--) {
		if (a[i] <= la) {
			string k =to_string(i)+cnt;
			if (k.size() > ans.size() and ans != "")return;
			dfs(la-a[i],to_string(i)+cnt);
		}
	}
}

int main () {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		ans = "";
		dfs(n,"");
		if (ans != "")cout << ans;
		else cout << -1;
		cout << endl;
	}
	return 0;
}
