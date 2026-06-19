#include <bits/stdc++.h>
using namespace std;
int T, n;
int make(int s){
    int List[8] = {0, 10000000, 1, 7, 4, 2, 6, 8}, r0, r8;
    if (s <= 7) {
        return List[s];
    }else {
        r0 = make(s - 6) * 10;
        r8 = make(s - 7) * 10 + 8;
        return min(r0, r8);
    }
}
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> T;
	while (T --) {
        cin >> n;
        if (n == 0 || n == 1) {cout << -1; continue;}
        cout << make(n) << endl;
	}
	return 0;
}
