#include <bits/stdc++.h>

using namespace std;

int n;

const int N = 100005;

int arr[N][3]{};
int sel[3]{};
int sensi;

int ssist = 0;

void dfs(int x) {
    if (x == n) {
        ssist = max(ssist, sensi);
        return;
    }

    for (int i = 0; i < 3; i++) {
        // cout << i << ": SEL+" << sel[i] << endl;
        dfs(x + 1);
        if ((sel[i]*2) >= n) continue;
        sel[i]++;
        sensi += arr[x][i];
        dfs(x + 1);
        sensi -= arr[x][i];
        sel[i]--;
    }
}

int main() {
    ifstream in("club.in");
    ofstream out("club.out");
    int t;
    in >> t;
    while (t-->0) {
        ssist = 0;
        in >> n;
        for (int i = 0; i < n; i++) {
            in >> arr[i][0] >> arr[i][1] >> arr[i][2];
        }
        dfs(0);
        cout << ssist << endl;
    }
}