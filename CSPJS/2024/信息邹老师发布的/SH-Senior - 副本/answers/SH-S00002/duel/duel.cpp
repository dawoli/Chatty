#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

int n, ans;
long long cache;
int h[maxn];
int minVal = 10e6;

int find_nxt_run(int idx){
	for (int i = idx + 1; i < maxn; i++){
		if (h[i] > 0){
			return i;
		}
	}
	return -1;
}

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	ans = n;
	
	for (int i = 0; i < n; i++){
		int r;
		cin >> r;
		minVal = min(minVal, r);
		h[r]++;
	}
	
	int idx = minVal;
	
	while(idx != -1){
		int nxtIdx = find_nxt_run(idx);
		if (nxtIdx == -1){
			break;
		}
		cache += h[idx];
		if (h[nxtIdx] > cache){
			h[nxtIdx] -= cache;
			ans -= cache;
			cache = 0;
		}
		else{
			cache -= h[nxtIdx];
			ans -= h[nxtIdx];
		}
		idx = nxtIdx;
	}
	
    cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
    return 0;
} 
