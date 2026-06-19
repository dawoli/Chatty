#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int NNN = 1005;
ll n ,m;
ll seats[NNN][NNN];
ll source[NNN];
int r ,c;
int tmp_j = -1;
bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;

    for (int i=0; i< n*m; i++) {
        cin >> source[i];
//        cout << r << " " << c << " "<< source[i]<<  endl;
    }
//    cout <<  endl;
    int R = source[0];

    sort(source, source+n*m, cmp);
//	for (int i=0; i< n*m; i++) {
//        cout << r << " " << c << " "<< source[i]<<  endl;
//    }

    for (int i =0; i<n; i++) {
        c++;
        for (int j = 0; j<m; j++) {
            tmp_j++;
            r++;
            if (r >n) {
                r = 1;
            }
//            cout << r << " " << c << " "<< source[tmp_j]<<  endl;
            seats[r][c] = source[tmp_j];

        }
    }

    // find
    for (int x=1; x<=n; x++) {
        for (int y = 1; y<=m; y++) {
            if (seats[x][y] == R) {
                cout << y << " " << x << endl;
            }
        }
    }

    return 0;

}
