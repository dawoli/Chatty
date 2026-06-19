#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int row, col;
    scanf("%d%d", &row, &col);
    int a[row*col];
    for (int i = 0; i < row*col; i++) {
        scanf("%d", &a[i]);
    }
    int r_score = a[0];
    std::sort(a, a+row*col);
    bool go_down = true;
    int r_row = 1, r_col = 1;
    for (int i = 0; i < row*col; i++) {
        //printf("(%d,%d)", r_col, r_row);
        if (a[row*col-1-i] == r_score) {
            printf("%d %d", r_col, r_row);
            break;
        }
        if (go_down && r_row == row) {
            r_col++;
            go_down = false;
        }
        else if (go_down) {
            r_row++;
        }
        else if (!go_down && r_row == 1) {
            r_col++;
            go_down = true;
        }
        else if (!go_down) {
            r_row--;
        }
    }
    return 0;
}
