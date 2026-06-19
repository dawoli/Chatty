#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

int t, n, digits, a[15000], x[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, y[8] = {0, 0, 1, 7, 4, 2, 0, 8};
void solve(int n) {
    if (n == 1) {cout << -1 << endl; return;}
    digits = (n + 6) / 7;
    for (int i = 0; i < digits; i++) a[i] = i == 0 ? (n % 7 == 0 ? 7 : n % 7) : 7;
    for (int i = 0; i < digits; i++) for (int goal = i == 0 ? 1 : 0; goal < 10; goal++) {
        int d = a[i] - x[goal];
        if (d == 0) break;
        else if (d < 0) {
            int b[15000];
            for (int j = i + 1; j < digits; j++) {
                b[j] = a[j];
                if (d + a[j] < 2) {a[j] = 2; d += a[j] - 2;}
                else {a[j] += d; d = 0;}
            }
            if (d == 0) {a[i] = x[goal]; break;}
            else for (int j = i + 1; j < digits; j++) {a[j] = b[j];}
        } else if (d > 0) {
            int b[15000];
            for (int j = i + 1; j < digits; j++) {
                b[j] = a[j];
                if (d + a[j] > 7) {a[j] = 7; d += a[j] - 7;}
                else {a[j] += d; d = 0;}
            }
            if (d == 0) {a[i] = x[goal]; break;}
            else for (int j = i + 1; j < digits; j++) {a[j] = b[j];}
        }
    }
    for (int i = 0; i < digits; i++) cout << (i == 0 && a[i] == 6 ? 6 : y[a[i]]); cout << endl;
    return;
}
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
    cin >> t; while (t--) {cin >> n; solve(n);}
	return 0;
}