#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    int ans = n;
    priority_queue<int> attack, defence;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        attack.push(a);
        defence.push(a);
    }
    while(!attack.empty() && !defence.empty()) {
        int curratt = attack.top();
        attack.pop();
        while(true) {
            if(defence.empty()) break;
            int cd = defence.top();
            defence.pop();
            if(cd < curratt) {
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
