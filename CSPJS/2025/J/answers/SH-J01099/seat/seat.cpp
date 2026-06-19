#include <bits/stdc++.h>
using namespace std;

struct student {
    int score, code;
};

bool cmp(student a, student b) {
    return a.score > b.score;
}

int main() {
    freopen("./seat.in", "r", stdin);
    freopen("./seat.out", "w", stdout);

    int line_cnt, row_cnt; cin >> line_cnt >> row_cnt;

    vector<student> all_student(line_cnt * row_cnt + 1);

    for (int i = 0; i < line_cnt * row_cnt; i++) {
        cin >> all_student[i].score;
        all_student[i].code = i;
    }

    sort(all_student.begin(), all_student.end(), cmp);

    int index = 0;
    while(all_student[index].code != 0) index++;

    int local_row = index / line_cnt + 1;
    cout << local_row << " ";
    index = index % (2 * line_cnt) + 1;

    if (index > line_cnt) cout << (2 * line_cnt + 1) - index;
    else cout << index;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
