#include <bits/stdc++.h>
#define SIZE 100000
using namespace std;
int n, r[SIZE], s = 0, c = 0, last = 0;
struct {
    int val = 0, rest, available;
} arr[SIZE];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> r[i];
    sort(r, r + n);
    arr[0].val = r[0],
    arr[0].rest = arr[0].available = 1;
    for (int i = 1; i < n; i++)
        if (arr[s].val == r[i])
            arr[s].rest++, arr[s].available++;
        else
            s++, arr[s].val = r[i],
            arr[s].rest = arr[s].available = 1;
    s++;
    for (int i = 1; i < s; i++) {
        while (last < i) {
            int available = arr[i].available, rest = arr[last].rest;
            if (available >= rest) {
                arr[last].rest = 0;
                arr[i].available -= rest;
                last++;
            } else {
                arr[last].rest -= available;
                arr[i].available = 0;
                break;
            }
        }
    }
    for (int i = 0; i < s; i++)
        c += arr[i].rest;
    cout << c;
    return 0;
}
