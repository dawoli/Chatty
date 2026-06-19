#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	
	int datas;
	cin >> datas;
	
	for (int _ = 0; _ < datas; _++) {
		int peoplecnt, lenmax, questcount;
		cin >> peoplecnt >> lenmax >> questcount;
		
		vector<int> lists[peoplecnt];
		for (int p = 0; p < peoplecnt; p++) {
			int d;
			cin >> d;
			
			for (int pd = 0; pd < d; pd++) {
				int c;
				cin >> c;
				lists[p].push_back(c);
			}
		}
		
		for (int c = 0; c < questcount; c++) {
			int ql, qe;
			cin >> ql >> qe;
			
			int qei0 = -1;
			int qei1 = -1;
			
			for (int x = 0; x < peoplecnt; x++) {
				for (int y = 0; y < lists[x].size(); y++) {
					if (lists[x][y] == qe) {
						qei0 = x;
						qei1 = y;
						
						goto je;
					}
				}
				
				goto cje;
				je:
					break;
				cje:
					continue;
			}
			
			if (qei0 == -1 || qei1 == -1) {
				cout << 0 << endl;
			}
			else {
				if (ql == 1) {
					int fnl = qei1 + 1;
					cout << ((fnl > lenmax || fnl < 2) ? 0 : 1) << endl;
				}
				else {
					cout << 1 << endl;
				}
			}
		}
	}
	
	return 0;
}