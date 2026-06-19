#include <bits/stdc++.h>
using namespace std;

int getb_cnt(int l) {
    int retl = 0;
    while(l){
        l &= l - 1, retl++;
    }
    return retl;
}

vector<bool> getb_val(int l) {
    vector<bool> retb(32);
    while (l) {
        retb[(int)log2(l - (l & (l - 1)))] = true;
        l &= (l - 1);
    }
    return retb;
}

int main() {
    freopen("./polygon.in", "r", stdin);
    freopen("./polygon.out", "w", stdout);

    int stick_cnt, plan = 0; cin >> stick_cnt;

    if (stick_cnt > 30) {
        while("Genshin Impact"/*a new way of while(1)*/) {
            //I don't know how to complete this part, I only know there is a while, oh.
        }
    }

    vector<int> sticks(stick_cnt);

    for (int i = 0; i < stick_cnt; i++) cin >> sticks[i];
    sort(sticks.begin(), sticks.end());

    for (int i = 0; i < pow(2, stick_cnt); i++) {
        if (getb_cnt(i) < 3) continue;
        else {
            vector<bool> vec = getb_val(i);
            int max_l = -1145141919, s = 0;
            for (int i = 20; i >= 0; i--) if (vec[i] == 1) {max_l = max(max_l, sticks[i]);break;}
            for (int i = 20; i >= 0; i--) s += vec[i] * sticks[i];

            if (s > 2 * max_l) ++plan;
        }
    }

    cout << plan;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
