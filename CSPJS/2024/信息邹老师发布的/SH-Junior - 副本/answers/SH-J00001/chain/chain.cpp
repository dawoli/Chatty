#include <bits/stdc++.h>
using namespace std;

int T;
int n, k, q;
int r, c;

bool foundAns;
bool has[200010];

vector<vector<int>> s;

void test(int lastP, int start, int depth){
	if (foundAns){
		return;
	}
	if (depth > r){
		return;
	}
	for (int p = 0; p < n; p++){
		if (p == lastP){
			continue;
		}
		for (int i = 0; i < s[p].size() - 1; i++){
			if (s[p][i] == start){
				if (depth == r){
					for (int j = 1; j < k; j++){
						foundAns = s[p][i + j] == c;
						if (foundAns) {
							return;
						}
					}
				}
				else{
					for (int j = 1; j < k && i + j < s[p].size(); j++){
						test(p, s[p][i + j], depth + 1);
						if (foundAns){
							return;
						}
					}
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	
	cin >> T;
	
	for (int _ = 0; _ < T; _++){
		cin >> n >> k >> q;
		
		memset(has, 0, sizeof(has));
		
		s.clear();
		s.reserve(n);
		
		for (int i = 0; i < n; i++){
			int l;
			cin >> l;
			vector<int> nxtS;
			nxtS.reserve(l);
			s.push_back(nxtS);
			for (int j = 0; j < l; j++){
				int nxtS;
				cin >> nxtS;
				has[nxtS] = true;
				s[i].push_back(nxtS);
			}
		}
		

		for (int i = 0; i < q; i++){
			cin >> r >> c;
			if (!has[c]){
				cout << 0 << endl;;
			}
			else{
				foundAns = 0;
				test(-1, 1, 1);
				cout << foundAns << endl;
			}

		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
