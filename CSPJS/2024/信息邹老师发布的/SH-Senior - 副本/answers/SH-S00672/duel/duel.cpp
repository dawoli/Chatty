#include<bits/stdc++.h>
using namespace std;

int sted[(int)1e5 + 5], abled[(int)1e5 + 5];;
vector<int> inc;

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		sted[x]++;
	}	
	for (int i = 1; i <= 1e5; i++) if (sted[i]) { inc.push_back(i); abled[i] = sted[i]; }
	int ans = 0;
	int alldisabled = 0;
	for (int i = 0; i < inc.size(); i++) {
		int pos = inc[i];
		int sum = 0;
		int j;
		for (j = i + 1; j < inc.size(); j++) {
			sum += abled[inc[j]];
			if (sum >= sted[pos]) {
				abled[inc[j]] = sum - sted[pos];
				break;
			}
			abled[inc[j]] = 0;	
		}	
		if (sum >= sted[pos]) {
			ans += sted[pos];	
		} else ans += sum;
	}
	cout << n - ans << endl;
}
