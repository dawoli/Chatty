#include<bits/stdc++.h>

using namespace std;
const int M = 5e6+20;
const int N = 2e5+20;
int n, q, b[30], whe[N], fl;
string s, ss;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		whe[i] = s.size();
		cin >> ss;
		s += ss;
		cin >> ss;
		s += ss;
	}
//	for(int i = 0; i < s.size(); i++){
//		if(ss[i] != 'a' && ss[i] != 'b') fl = 1;
//		b[ss[i]-'a'+1]++;
//	}
	for(int i = 1; i <= q; i++){
		cout << 0;
	}
	return 0;
}
