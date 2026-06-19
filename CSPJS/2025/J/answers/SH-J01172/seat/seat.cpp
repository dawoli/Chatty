#include <bits/stdc++.h>
using namespace std;
int n, m, k, col, row;
struct student {int score; bool r;} students[101];
bool operator>(const student& s1, const student& s2) {return s1.score > s2.score;}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m, students[1].r = 1;
    for (int i = 1; i <= n * m; i++) cin >> students[i].score;
    sort(students + 1, students + n * m + 1, greater<student>());
    for (int i = 1; i <= n * m; i++) if (students[i].r) {k = i; break;}
    col = (k + n - 1) / n;
    row = col % 2 ? (k - 1) % n + 1 : n - (k - 1) % n;
    cout << col << " " << row << endl;
    return 0;
}