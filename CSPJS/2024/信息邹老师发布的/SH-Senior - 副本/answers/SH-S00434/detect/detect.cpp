#include<bits/stdc++.h>
using namespace std;
int n, m, L, V, T;
int dList[3009], vList[3009], aList[3009], pList[3009];
bool sList[3009][3009], io[3009], os[3009];
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t = 0;
	cin >> T;
	while (t < T){
		cin >> n >> m >> L >> V;
		for (int d, v, a, i = 0; i < n; i++){
			cin >> d >> v >> a;
			dList[i] = d;
			vList[i] = v;
			aList[i] = a;
			os[i] = 0;
			for (int j = 0; j < m; j++){
				sList[j][i] = 0;
				io[j] = 0;
			}
		}
		for (int p, i = 0; i < m; i++){
			cin >> p;
			pList[i] = p;
		}
		// ----- main -----
		int oscn = 0;
		for (int c = 0; c < n; c ++){
			if (vList[c] <= V && aList[c] <= 0)
				continue;
			else if (vList[c] > V && aList[c] == 0){
				for (int p = 0; p < m; p ++){
					if (pList[p] < dList[c])
						continue;
					sList[p][c] = 1;
				}
				oscn ++;
				continue;
			}
			bool isos = 0;
			for (int p = 0; p < m; p ++){
				if (pList[p] < dList[c])
					continue;
				int s = pList[p] - dList[c];
				if (V * V >= vList[c] * vList[c] + 2 * aList[c] * s)
					continue;
				sList[p][c] = 1;
				os[c] = 1;
				isos = 1;
			}
		
			if (isos){
				oscn ++;
			}
		}
		cout << oscn << ' ';
		
		
		for (int c = 0; c < n; c ++){
			int sum = 0;
			for (int p = 0; p < m; p ++){
				sum += sList[p][c];
				//cout << sList[p][c] <<' ';
			}
			//cout<<endl;
			//cout<<sum<<' ';
			if (sum == 1){
				for (int p = 0; p < m; p ++){
					if (sList[p][c])
						io[p] = 1;
				}
				//cout<<p<<' ';
			}
		}
		for (int c = 0; c < n; c ++){
			if (os[c] == 0)
				continue;
				int max = 0, sum = 0, maxP = 0;
			for (int p = 0; p < m; p ++){
				
				if (io[p] == 1 && sList[p][c]){
					break;
				}
				else if (sList[p][c]){
					sum += sList[p][c];
					//cout << sum;
					if (sum < max){
						max = sum;
						maxP = p;
					}
				}
				io[maxP] = 1;
			}
		}
		
		int sum = 0;
		for (int p = 0; p < m; p ++){
			if (io[p] == 0)
			sum++;
		}
		cout << sum << endl;
		t ++;
	}
	return 0;
}


