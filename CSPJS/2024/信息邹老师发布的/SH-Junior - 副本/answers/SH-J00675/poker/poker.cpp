#include<bits/stdc++.h>
using namespace std;
set<string> s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		string ss;
		cin >> ss;
		s.insert(ss);
	}
	int ans = 52 - s.size();
	cout << ans;
	return 0;
} 
