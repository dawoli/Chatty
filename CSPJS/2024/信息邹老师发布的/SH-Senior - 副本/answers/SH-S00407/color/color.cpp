#include <iostream>
#include <vector>
using namespace std;
int T = 0;
int c[1000001] = {};
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	while(T--) {
		for(int i = 0; i <= 1e6; i++) c[i] = 0;
		int n = 0;
		int ans = 0;
		cin >> n;
		vector<int> b;
		for(int i = 0; i < n; i++) {
			int x = 0;
			cin >> x;
			b.push_back(x);
		}
		
		for(int i = 0; i <= b.size(); i++) {
			c[b[i]]++;
			if(c[b[i]] % 2 == 0) {
				ans += i;
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
