#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 105;
int n, m, a1, target;
int a[N];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++) {
        cin >> a[i];
    }
    a1 = a[1];
    sort(a+1, a+n*m+1, greater<int>());
    for(int i = 1;i <= n*m;i++) {
        if(a[i] == a1) {
            target = i;
            break;
        }
    }
    int c = ceil(target * 1.0 / n), r = target % n;
    if(r == 0) r = n;
    if(c % 2 == 0) {
        r = n - r + 1;
    }
    cout << c << ' ' << r;
	return 0;
}
