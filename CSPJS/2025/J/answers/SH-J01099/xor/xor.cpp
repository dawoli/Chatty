#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("./xor.in", "r", stdin);
    freopen("./xor.out", "w", stdout);

    int llength, targetn, plan_cnt = 0; cin >> llength >> targetn;
    vector<int> larr(llength), pref(llength);

    for (int i = 0; i < llength; i++)  cin >> larr[i];

    pref[0] = larr[0];
    for (int i = 1; i < llength; i++) pref[i] = pref[i-1] ^ larr[i];

    for (int i = 0; i < llength; i++) {
        for (int j = i; j < llength; j++) {
            if (i == 0) {
                if (pref[j] == targetn) {
                    plan_cnt++;
                    i = j + 1;
                    break;
                }
            } else {
                if (pref[j] ^ pref[i-1] ==  targetn) {
                    plan_cnt++;
                    i = j + 1;
                    break;
                }
            }
        }
    }

    cout << plan_cnt;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
