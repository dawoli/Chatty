#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1000005;
int n, k;
ll a[N];
int cnt = 0;
int tmp;


int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    for (int i= 1; i<=n; i++) cin >> a[i];

    for (int i = 1; i<=n-1; i++) {
        for (int j = 1; j<i; j++) {
            tmp=a[j];
            tmp = tmp^a[j+1];
        }

        if (tmp == a[n]) {
            cnt ++;
        }
    }

    cout << cnt << endl;
    return 0;
}

