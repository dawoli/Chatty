#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

string s1[N], s2[N];
bool replace[N];

int main() {
	int n, q;
	cin>>n>>q;
	for (int i = 1; i <= n; i ++) {
		cin>>s1[i]>>s2[i];
	}
	while(q--) {
		string t1, t2;
		cin>>t1>>t2;
		if (t1.size()!=t2.size()) {
			cout<<"0\n";
			continue;
		}
		for (int j = 0; j < t1.size(); j ++) {
			for (int k = 1; )
		}
	}
	return 0;
}
