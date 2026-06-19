#include <iostream>
#include <cstdio>
using namespace std;
int n, r, pl[100010], ans, curRight, curRightUsed;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
    	scanf("%d", &r);
        pl[r]++;
    }
    curRight = n;
    for(int i = 1; i <= 100000; i++) {
        curRight -= pl[i];
        curRightUsed = max(0, curRightUsed - pl[i]);
        if(pl[i] > curRight - curRightUsed) {
            ans += curRight - curRightUsed;
            break;
        } else {
            ans += pl[i];
            curRightUsed += pl[i];
        }
    }
    printf("%d\n", n - ans);
    return 0;
}
