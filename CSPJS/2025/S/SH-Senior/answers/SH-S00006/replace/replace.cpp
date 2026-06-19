#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	int N, Q;
	cin >> N >> Q;
	vector<string> S1(N + 1), S2(N + 1);
	for(int i = 1; i <= N; i++) {
		cin >> S1[i] >> S2[i];
	}
	vector<int> Ans(Q + 1); 
	for(int i = 1; i <= Q; i++) {
		string s, tank;
		cin >> s >> tank;
		for(int j = 1; j <= N; j++) {
			int pos = -1;
			while((pos = s.find(S1[j], pos + 1)) != -1) {
				string x = s.substr(0, pos);
				string y = s.substr(pos + S1[j].size());
				string panzer = x + S2[j] + y;
				cout << '{' << panzer << '}';
				if(panzer == tank) {
					Ans[i]++;
				}
			}
		}
	}
	for(int i = 1; i <= Q; i++) {
		cout << Ans[i] << '\n';
	}
	return 0;
}
