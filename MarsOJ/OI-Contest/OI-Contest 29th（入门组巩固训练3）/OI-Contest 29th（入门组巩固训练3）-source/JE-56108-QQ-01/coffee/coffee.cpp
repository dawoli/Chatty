#include <bits/stdc++.h>
using namespace std;
pair<int, vector<int> > read() {
    vector<int> mc(5, 0);
    int wm = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 8; ++j) {
            string c;
            cin >> c;
            if (c == "math") {
                mc[i]++;
                wm++;
            }
        }
    }
    return make_pair(wm, mc);
}
long long cl(int s, int fd, int wm, const vector<int>& mc) {
    int fw = s / 7;
    int d = s % 7;

    long long c = fw * wm;

    for (int i = 0; i < d; ++i) {
        int cd = (fd + i - 1) % 7;
        if (cd < 5) {
            c += mc[cd];
        }
    }

    return c;
}

int main() {
	freopen("coffee.in", "r", stdin);
    freopen("coffee.out", "w", stdout); 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int wc;
        vector<int> mc;
        pair<int, vector<int> > result = read();
        wc = result.first;
        mc = result.second;
        int s, d;
        cin >> s >> d;
        long long r = cl(s, d, wc, mc);
        cout << r << "\n";
    }
}
