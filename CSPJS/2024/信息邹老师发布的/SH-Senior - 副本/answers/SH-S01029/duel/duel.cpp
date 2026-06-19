#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	vector<int> monster(n);
	for(int i = 0; i < n; i ++) cin >> monster[i];
	sort(monster.begin(),monster.end());
	for(int i = 0; i < n; i ++) {	
		if(monster[i] != -1) {
			for(int j = i + 1; j < n; j ++) {
				if(monster[j] > abs(monster[i])) {
					monster[i] = -1; 
					monster[j] = -monster[j];
					break; 
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i ++) {
		if(monster[i] != -1) ans ++;
	}
	cout << ans;
	return 0;
}
