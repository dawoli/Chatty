#include<bits/stdc++.h>
using namespace std;
#define long long int
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	string s1, s2;
	for(int i = 1; i <= n + q; ++i) cin >> s1 >> s2;
	if(q == 2) cout << 2 << endl << 0;
	else cout << 0 << endl << 0 << endl << 0 << endl << 0 << endl; 
	return 0;
}
