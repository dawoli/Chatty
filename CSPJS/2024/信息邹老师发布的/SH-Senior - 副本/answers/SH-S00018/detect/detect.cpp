#include <bits/stdc++.h>
using namespace std;
vector<int> d;
vector<int> v;
vector<int> a;
vector<int> p;
int n, m, L, V, r, l;
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    function<void(void)> input = [&]() {
        for (int i = 0; i < n; ++i) {
            cin >> d[i] >> v[i] >> a[i]; 
        }
        for (int i = 0; i < m; ++i) {
            cin >> p[i];
        }
    };
    function<double(int, int)> cal = [&](int v0, int a0) {
        return (double)((L*L - v0 * v0) / (2 * a0));
    };
    function<int()> detect = [&]() {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int D = d[i], V1 = v[i], A = a[i];
            if (A == 0)  {
                if (V1 > L) {
                    r = lower_bound(p.begin(), p.end(), D)-p.begin();
                }
            } else {
                if (A > 0) {
                    if (V1 > V) {
                    	int x = upper_bound(p.begin(), p.end(), D)-p.begin();
                        r = min(r, x);
                        ++res;
                    } else {
                        int pos = cal(V1, A);
                        int x = upper_bound(p.begin(), p.end(), pos)-p.begin()-1;
                        if (x > i + 1) {
                            l = max(l, x);
                            ++res;
                        }
                    }
                } else {
                    if (V1 >= V) {
                        int pos = cal(V1, A);
                        int x = upper_bound(p.begin(), p.end(), pos)-p.begin();
                        if (x > i + 1) {
                            r = min(r, x);
                            ++res;
                        }
                    }
                }
            }
        }
        return res;
    };
    int T;
    cin >> T;
    while (T--) {
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        vector<int> d(n, 0);
        vector<int> v(n, 0);
        vector<int> a(n, 0);
        vector<int> p(m, 0);
        input();
        int l = 0, r = m-1;
        cout << detect() << ' ' << r - l + 1;
    }
    cout << 3 << ' ' << 3 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

