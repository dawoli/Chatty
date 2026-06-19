#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	int cnt;
	cin >> cnt;
	
	uint32_t hist[cnt];
	
	for (int _ = 0; _ < cnt; _++) {
		char a, b;
		cin >> a >> b;
		
		hist[_] = ((uint32_t) a) * 1024 + ((uint32_t) b);
	}
	
	vector<uint32_t> final;
	
	for (int data = 0; data < cnt; data++) {
		for (int dd : final) {
			if (dd == hist[data]) goto je;
		}
		
		final.push_back(hist[data]);
		
		je:
			continue;
	}
	cout << 52 - final.size();
	return 0;
}