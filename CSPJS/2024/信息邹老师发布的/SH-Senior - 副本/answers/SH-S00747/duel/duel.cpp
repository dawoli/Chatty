#include<bits/stdc++.h> //100分 
using namespace std;
const int N = 1e5+10;
int n;
int r[N];
bool atk[N]; //此位置是否发动过攻击 
int main () {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> r[i];
	}
	int ans = 0;
	sort(r+1, r+1+n);
	int pos_max = 1;
	for(int i = 1; i <= n; i ++) {
		int pos_max1=0;
		for(int j = pos_max; j <= n; j ++) {
			if(r[j] >= r[i] || atk[j] == true) pos_max1 = j;
			if(r[j] > r[i] && atk[j] == false) {
				atk[j] = true;
				ans ++;
				//cout << r[j] << '-' << r[i] << endl;
				break;
			} 
		}
		pos_max = max(pos_max, pos_max1);
	}
	
	cout << n-ans;
	
	return 0;
} 
