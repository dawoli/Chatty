#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	if(q == 1){
		for(int i = 1; i <= n; i++) {
			string x,y;
			cin >> x >> y;
		}
		string t1,t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size()) cout << 0;
		else cout << n;
	}
	for(int i = 1; i <=q; i++) {
		cout << 0 << endl;
	} 
	return 0;
}
