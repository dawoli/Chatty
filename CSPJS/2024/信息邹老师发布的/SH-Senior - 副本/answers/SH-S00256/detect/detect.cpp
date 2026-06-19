#include<bits/stdc++.h>
#define INF 1e6 + 20
using namespace std;

const int MAXM = 1e5 + 10;
int T, n, m, l, v, cnt1, cnt2;
double pL[MAXM], cntL[MAXM]; 

struct CAR {
    double d, v, a, maxL;
    vector <int> over_num;
    
    void solve_max() {
    	over_num.clear();
    	if (a >= 0) maxL = INF;
    	else maxL = v * v / 2 / -a + d;
	}

    void print_over() {
        for (int i = 0; i < over_num.size(); i++) cout << over_num[i] << " ";
        cout << endl;
    }
} cL[MAXM];

bool solve(int c, int pI) {
	CAR car = cL[c];
    if (pL[pI] - car.d < 0) return false;
    if (pL[pI] > car.maxL and car.a < 0) return false;
    double cur_v = sqrt(car.v * car.v +  2 * car.a * (pL[pI] - car.d));
    if (cur_v > v) {
    	// cout << c << " " << cur_v << endl;
    	return true;
	}
    return false;
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
    cin >> T;
    for (int t = 0; t < T; t++) {
    	cnt1 = 0;
        cin >> n >> m >> l >> v;
        for (int i = 0; i < n; i++) {
        	cin >> cL[i].d >> cL[i].v >> cL[i].a;
        	cL[i].solve_max();
		}
        for (int i = 0; i < m; i++) cin >> pL[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (solve(i, j) == true) {
                	// cout << i << " " << j << " " << pL[j] << endl;
                	cL[i].over_num.push_back(j);
				}
            }
        }
        for (int i = 0; i < n; i++) {
        	// cL[i].print_over();
        	if (cL[i].over_num.size() != 0) cnt1++;
		}
		cout << cnt1 << " " << m - 1 << endl;
    }
    return 0;
}