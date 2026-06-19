#include <stdio.h>
#include <math.h>
#include <bitset>

#define MAXN (20)

int arr[20];
int lengthOfArray;

int maxValue;

int nearest[20];

void dfs(int i) {
    if (i == lengthOfArray) {
        // stat
        int ans = 0;
        
        for (int j = 0; j < i; j++) {
            if (nearest >= 0 && arr[j] == arr[nearest[j]]) ans += abs(arr[j]);
        }

        maxValue = std::max(maxValue, ans);
    } else {
        nearest[i] = -1;
        for (int j = i - 1; j >= 0; j--) if (arr[j] > 0) {
            nearest[i] = j;
            break;
        }

        dfs(i + 1);

        arr[i] = -arr[i];
        nearest[i] = -1;
        for (int j = i - 1; j >= 0; j--) if (arr[j] < 0) {
            nearest[i] = j;
            break;
        }

        dfs(i + 1);

        arr[i] = -arr[i];
    }
}

int main(void) {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int countOfTestcases;
    scanf("%d", &countOfTestcases);

    while (countOfTestcases--) {
        scanf("%d", &lengthOfArray);

        maxValue = -1;

        for (int i = 0; i < lengthOfArray; i++) scanf("%d", &arr[i]);

        dfs(0);

        printf("%d\n", maxValue);
    }
}