#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> getanswer(int tgt) {
	vector<vector<int>> ans;
	if (tgt < 2) return ans;
	if (tgt >= 2 && tgt <= 7) {
		vector<int> t;
		t.push_back(tgt);
		ans.push_back(t);
	}
	else {
		for (int first = 2; first <= 7; first++) {
			for (vector<int> post : getanswer(tgt - first)) {
				vector<int> tb;
				tb.push_back(first);
				for (int data : post) tb.push_back(data);
				ans.push_back(tb);
			}
		}
	}
	
	return ans;
}

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	int datas;
	cin >> datas;
	
	for (int _ = 0; _ < datas; _++) {
		int tgt;
		cin >> tgt;
		
		if (tgt < 2) {
			cout << -1 << endl;
			continue;
		}
		
		vector<vector<int>> d = getanswer(tgt);
		vector<vector<int>> tgtSolu;
	
		int minle = 2147483647;
		for (auto a : d) {
			if (a.size() < minle) minle = a.size();
		}
	
		for (auto a : d) {
			if (a.size() == minle) tgtSolu.push_back(a);
		}
	
		int answer = 2147483647;
		for (auto solu : tgtSolu) {
			vector<char> c;
			bool canZero = false;
			for (auto solui : solu) {
				if (solui == 2) c.push_back('1');
				if (solui == 3) c.push_back('7');
				if (solui == 4) c.push_back('4');
				if (solui == 5) c.push_back('2');
				if (solui == 6) {
					if (canZero) c.push_back('0');
					else {
						c.push_back('6');
						canZero = true;
					}
				}
				if (solui == 7) c.push_back('8');
			
				canZero = true;
			}
		
			int cc = stoi(string(c.data()));
			if (cc < answer) {
				answer = cc;
			}
		}
	
		cout << answer << endl;
	}
	
	return 0;
}
