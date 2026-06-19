#include <iostream>
using namespace std;

const int MAX2N = 500010;
int a[MAX2N];
int b[MAX2N];
char ops[MAX2N];
int n, twoN;
bool found;

void dfs(int L, int R, int pos) {
    if (found) return; // 已找到最小字典序解，立即返回
    if (pos > twoN) {
        // 在 pos == twoN+1 时放置结束符，保证不会覆盖最后一个操作字符
        ops[pos] = '\0';
        printf("%s\n", ops + 1); // ops 从 1 开始存放
        found = true;
        return;
    }

    // 尝试 L（先尝试 L 保证字典序最小）
    b[pos] = a[L];
    if (pos <= n || b[pos] == b[twoN + 1 - pos]) { // 若 pos>n，则检查对称位置
        ops[pos] = 'L';
        dfs(L + 1, R, pos + 1);
        if (found) return;
    }

    // 尝试 R
    b[pos] = a[R];
    if (pos <= n || b[pos] == b[twoN + 1 - pos]) {
        ops[pos] = 'R';
        dfs(L, R - 1, pos + 1);
        if (found) return;
    }

}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        if (scanf("%d", &n) != 1) return 0;
        twoN = 2 * n;
        for (int i = 1; i <= twoN; ++i) scanf("%d", &a[i]);

        found = false;
        dfs(1, twoN, 1);
        if (!found) {
            printf("-1\n");
        }
    }
    return 0;
}