#include <bits/stdc++.h>

using namespace std;
int n, m, l, v, t;
struct carr {
    int d, v, a;
};
carr mc(int d, int v, int a) { //hhh I forgot how to write a constructor...
    carr x;
    x.d = d, x.a = a, x.v = v;
    return x;
}

int seq[25], ans;
vector<carr> cars;
vector<int> radar, temp;
void dfs(int pos, int x, int spc) {
    seq[pos] = x;
    if(pos == m - 1) { ///NOTE: START FROM ZERO!!!!!!!!
        int closc = 0;
        for(int i = 0; i < m; i++) {
            if(seq[i] == 1) continue;
            radar[i] = -1;
            closc++;
        }
        int tspc = 0;
        for(carr curr : cars) {
            bool br = false;
            for(int rdpos : radar) {
                if(rdpos == -1) continue;
                if(rdpos - curr.d < 0) continue;
                if(1ll * v * v < curr.v * 1ll * curr.v + 2 * curr.a * 1ll * (rdpos - curr.d)) {
                    tspc++;
                    br = true;
                    break;
                }
                if(br) break;
            }

        }
        if(tspc == spc) {
            ans = max(ans, closc);
        }
        for(int i = 0; i < m; i++) {
            radar[i] = temp[i];
        }
        return;
    } else {
        pos++;
        dfs(pos, 0, spc);
        dfs(pos, 1, spc);
    }
}
int rdpc[100005];
bool cmp(int x, int y) {
    return rdpc[x] < rdpc[y];
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &t);
    for(int tsc = 1; tsc <= t; tsc++) {
        cars.clear();
        radar.clear();
        temp.clear();
        memset(rdpc, 0, sizeof(rdpc));
        int tctp = 0, posg = -1;
        scanf("%d%d%d%d", &n, &m, &l, &v);
        if(n <= 20 && m <= 20) tctp = 1;
        for(int i = 1; i <= n; i++) {
            int d, v, a;
            scanf("%d%d%d", &d, &v, &a);
            cars.push_back(mc(d, v, a));
            if(a > 0 && (posg == -1 || posg == 1)) {
                posg = 1;
            } else if(a < 0 && (posg == -1 || posg == 0)) {
                posg = 0;
            } else if(a == 0 && (posg == -1 || posg == 2)) {
                posg = 2;
            } else posg = -2;
        }
        if(posg == 2) tctp = 2;
        if(posg == 1) tctp = 3;
        //if(posg == 0) tctp = 4;
        for(int i = 1; i <= m; i++) {
            int pos;
            scanf("%d", &pos);
            radar.emplace_back(pos);
            temp.emplace_back(pos);
        }
        if(tctp == 1) {
            int spc = 0;
            for(carr curr : cars) {
                bool br = false;
                for(int rdpos : radar) {
                    if(rdpos - curr.d < 0) continue;
                    if(1ll * v * v < curr.v * 1ll * curr.v + 2 * curr.a * 1ll * (rdpos - curr.d)) {
                        spc++;
                        br = true;
                        break;
                    }
                    if(br) break;
                }
            }
            cout << spc << " ";
            ans = 0;
            dfs(0, 0, spc);
            dfs(0, 1, spc);
            cout << ans << endl;
        } else if(tctp == 2) {
            int spc = 0;
            for(carr curr : cars) {
                if(curr.v > v && curr.d <= radar[m - 1]) spc++;
            }
            cout << spc << " " << ((spc == 0) ? m : m - 1) << endl;
        } else if(tctp == 3) {
            int spc = 0;
            for(carr curr : cars) {
                if(curr.d > radar[m - 1]) continue;
                if(1ll * v * v < curr.v * 1ll * curr.v + 2 * curr.a * 1ll * (radar[m - 1] - curr.d)) spc++;
            }
            cout << spc << " " << ((spc == 0) ? m : m - 1) << endl;
        } else {
            int spc = 0;
            for(carr curr : cars) {
                bool br = false;
                for(int rdpos : radar) {
                    if(rdpos - curr.d < 0) continue;
                    if(1ll * v * v < curr.v * 1ll * curr.v + 2 * curr.a * 1ll * (rdpos - curr.d)) {
                        spc++;
                        br = true;
                        break;
                    }
                    if(br) break;
                    cout << spc << " " << 0 << endl;
                }
            }
        }
    }
    return 0;
}
