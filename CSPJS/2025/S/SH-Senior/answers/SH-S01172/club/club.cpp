#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005], c[100005];
int choice[100005];
int n;
long long mxval = 0;
bool special_judge_A = true;
bool special_judge_B = true;

bool cmp(int x, int y) {
	return y < x;
}

void search(int idx, long long val, int cntA, int cntB, int cntC) {
    if (idx == n+1) {
        mxval = max(mxval, val);
        return;
    }

    if (cntA < (n/2)) {
        search(idx+1, val+a[idx], cntA+1, cntB, cntC);
        choice[idx] = a[idx];
    }
    if (cntB < (n/2)) {
        search(idx+1, val+b[idx], cntA, cntB+1, cntC);
        choice[idx] = b[idx];
    }
    if (cntC < (n/2)) {
        search(idx+1, val+c[idx], cntA, cntB, cntC+1);
        choice[idx] = c[idx];
    }
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
    int t;
    cin >> t;
    while (t--) {
    	mxval = 0;
        cin >> n;
        for (int i =  1; i <= n; ++i) {
            cin >> a[i] >> b[i] >> c[i];
            if (b[i] != 0 || c[i] != 0) {
                special_judge_A = false;
            }
            if (c[i] != 0) special_judge_B = false;
        }

		if (special_judge_A) {
            sort(a+1, a+n+1, cmp);
            long long res = 0;
            for (int i = 1; i <= (n/2); ++i) {
                res += a[i];
            }

            cout << res << "\n";
            continue;
        }

        if (special_judge_B) {

        }

        search(1, 0LL, 0, 0, 0);
        cout << mxval << endl;
    }
    
    return 0;
}
