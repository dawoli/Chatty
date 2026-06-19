#include<bits/stdc++.h>
using namespace std;

int ans[] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88};

void work(int n) {
    if(1 <= n && n <= 14) {
        cout << ans[n] << endl;
        return ;
    }
    if(n % 7 == 0) {
        for(int i = 1; i <= n / 7; i++)
            printf("8");
        cout << endl;
        return ;
    }
    if(n % 7 == 1) {
        cout << 10;
        for(int i = 1; i <= (n - 8) / 7; i++)
            printf("8");
        cout << endl;
    }
    if(n % 7 == 2) {
        cout << 1;
        for(int i = 1; i <= (n - 2) / 7; i++)
            printf("8");
        cout << endl;
    }
    if(n % 7 == 3) {
        cout << 200;
        for(int i = 1; i <= (n - 17) / 7; i++)
            printf("8");
        cout << endl;
    }
    if(n % 7 == 4) {
        cout << 20;
        for(int i = 1; i <= (n - 11) / 7; i++)
            printf("8");
        cout << endl;
    }
    if(n % 7 == 5) {
        cout << 2;
        for(int i = 1; i <= (n - 5) / 7; i++)
            printf("8");
        cout << endl;
    }
    if(n % 7 == 6) {
        cout << 6;
        for(int i = 1; i <= (n - 6) / 7; i++)
            printf("8");
        cout << endl;
    }
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int Q;
    cin >> Q;
    while(Q--) {
        int n;
        cin >> n;
        work(n);
    }
    return 0;
}
