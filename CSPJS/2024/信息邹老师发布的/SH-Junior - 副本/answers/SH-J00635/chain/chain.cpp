#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin >> T;
	while (T--){
		int n,k,q;
		set <int> s;
		for (int i = 1;i <= n;i++){
			int l;
			for (int j = 1;j <= l;j++){
				int x;
				cin >> x; 
				s.insert(x);
			}
		}
		for (int i = 1;i <= q;i++){
			int x,y;
			cin >> x >> y;
			if (s.find(y) == s.end()) cout << 0 << endl;
			else cout << 1 << endl;
		}
	}
	return 0;
}
