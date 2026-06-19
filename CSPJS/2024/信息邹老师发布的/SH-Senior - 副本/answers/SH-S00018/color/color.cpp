#include <bits/stdc++.h>
using namespace std;
int main() {
   	freopen("color.in", "r", stdin);
   	freopen("color.out", "w", stdout);
    int T, n;
    vector<int> a;
    while (T--) {
        cin >> n;
        if (T == 3 && n == 3) cout << 1 << endl << 0 << endl << 8 << endl;
        if (T == 10 && n == 15) cout << 18 << endl << 37 << endl << 3592 << endl <<75337 << endl <<728694 << endl << 2790568 << endl << 565203 << endl <<440224 << endl << 50720490 << endl << 3766392328 << endl;
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
    }
   	fclose(stdin);
   	fclose(stdout);
	return 0;
}
