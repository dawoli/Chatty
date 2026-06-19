#include <stdio.h>
#include <string.h>
#include <algorithm>

#ifndef DEBUG
#define fprintf
#endif

int main(void) {

    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    int countOfMonsters;

    int sourceData[100008];

    int unattackedMonsters[100008];
    int remainMonsters[100008];

    scanf("%d", &countOfMonsters);

    memset(unattackedMonsters, 0, sizeof(unattackedMonsters));
    memset(remainMonsters, 0, sizeof(remainMonsters));

    for (int i = 0; i < countOfMonsters; i++) {
        int monsterValue;
        scanf("%d", &monsterValue);

        sourceData[monsterValue]++;
    }

    int differentNumberCount = 1;

    for (int i = 1; i <= 100002; i++) {
        if (sourceData[i]) {
            unattackedMonsters[differentNumberCount] = sourceData[i];
            remainMonsters[differentNumberCount] = sourceData[i];
            differentNumberCount++;
        }
    }

    int i = 1, j = 1;

    while (j <= differentNumberCount + 2) {
        while (!remainMonsters[i] && i <= differentNumberCount + 2) i++;
        if (i >= differentNumberCount + 1) break;
        j = i + 1;

        while (!unattackedMonsters[j] && j <= differentNumberCount + 2) j++;
        if (j >= differentNumberCount + 1) break;

        if (remainMonsters[i] > unattackedMonsters[j]) {
            fprintf(stderr, "%d attacks %d\n", j, i);
            remainMonsters[i] -= unattackedMonsters[j];
            unattackedMonsters[j] = 0;
        } else {
            fprintf(stderr, "%d attacks %d\n", j, i);
            unattackedMonsters[j] -= remainMonsters[i];
            remainMonsters[i] = 0;
        }
    }

    int ans = 0;
    for (int i = 1; i <= differentNumberCount + 2; i++) if (remainMonsters[i]) ans += remainMonsters[i];

    printf("%d", ans); 

    return 0;
}