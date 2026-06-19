#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int n, cnt, ans;
int nL[MAXN], cntL[MAXN], cntLM[MAXN];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> nL[i];
    sort(nL, nL + n);
    cntL[1]++;
    int p = 1;
    for (int i = 1; i < n; i++) {
        if (nL[i] != nL[i - 1]) p++;
        cntL[p]++;
    }
    for (int i = 1; i <= p; i++) {
    	cntLM[i] = cntL[i];
	}
    for (int i = 1; i < p; i++) {
    	for (int j = i + 1; j <= p; j++) {
    		if (cntL[i] - cntLM[j] <= 0) {
    			cntL[i] = 0;
    			cntLM[j] -= cntL[i];
    			break;
			}
			else {
				cntL[i] -= cntLM[j];
				cntLM[j] = 0;
			}
		}
		ans += cntL[i];
    }
    cout << ans + cntL[p];
    return 0;
}
