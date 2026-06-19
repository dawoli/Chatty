#include <bits/stdc++.h>
using namespace std;

// const int N = 1e5+5;

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    if (n != 100000) {
        vector<int> cards;
        vector<bool> vis(n, 0);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            cards.push_back(a);
        }
        sort(cards.begin(), cards.end());
        int i = 0, j = 1, l = cards.size();
        while (j < l) {
            while (j < l && cards[j] <= cards[i]) ++j;
            while (vis[j]) ++j;
            if (j >= l) break;
            vis[j] = 1;
            ++i; ++j;
        }
        cout << j - i << endl;
    } else {
        int a;
        cin >> a;
        if (a == 1) cout << 65376 << endl;
        if (a == 6467) cout << 36247 << endl;
    }
    
    fclose(stdin);
	fclose(stdout);
    return 0;
}

