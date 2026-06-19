#include <bits/stdc++.h>
using namespace std;

const int maxnm = 100010;

int T;
int n, m, L, V;
int d, v, a;
int p;

float lArray[maxnm], rArray[maxnm];
int detected1[maxnm];
vector<int> detects[maxnm]; 

int ans1, ans2;

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> T;
	for (int _ = 0; _ < T; _++){
		cin >> n >> m >> L >> V;
		
		ans2 = 0;
		
		for (int i = 0; i < n; i++){
			cin >> d >> v >> a;
			
			float accL, accR; // > accL, < accR 
			
			if (a == 0){
				if (v > V){
					accL = d - 0.0001 * (v != V);
					accR = L + 1;
				}
				else{
					accL = -1;
					accR = -1;
				}
				lArray[i] = accL;
				rArray[i] = accR;
				
				continue;
			}
			float accelP = (V * V - v * v) / (2 * a + 0.0) + d;
			if (a >= 0){
				accL = accelP;
				accR = L + 1;
			}
			else{
				accL = d - 0.0001 * (v != V);
				accR = accelP;
			}
			
			lArray[i] = accL;
			rArray[i] = accR;
		}
		for (int i = 0; i < m; i++){
			cin >> p;
			for (int j = 0; j < n; j++){
				if (lArray[j] < p && rArray[j] > p){
					ans1 += (detected1[j] == 0);
				    detected1[j]++;
				    detects[i].push_back(j);
				}
		    }
		}
		cout << ans1 << " ";
		for (int i = 0; i < m; i++){
			bool flag = true;
			for (int j : detects[i]){
				if (detected1[j] <= 1){
					flag = false;
					break;
				}
			}
			if (flag){
				ans2++;
				for (int j : detects[i]){
					detected1[j]--;
				}
			}
		}
		cout << ans2 << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
