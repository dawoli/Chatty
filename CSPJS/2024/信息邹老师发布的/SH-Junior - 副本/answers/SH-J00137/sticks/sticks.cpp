#include <bits/stdc++.h>
using namespace std;
#define int long long
int T,n;
int stick[10] = {6,2,5,5,4,5,6,3,7,6};
int OutPut[100010];

// bool DFS(int depth,int sum) {
//     if (sum == n) {
//         for (int i=1; i<=depth; ++i) {
//             printf("%d",OutPut[i]);
//         }
//         printf("\n");
//         return true;
//     } else if (sum > n) {
//         return false;
//     }
//     for (int i=0; i<=n; ++i) {
//         if (i == 0 and depth == 1) {
//             continue;
//         }
//         OutPut[depth] = i;
//         if (DFS(depth+1, stick[i])) {
//             return true;
//         }
//     }
// }

signed main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld",&n);
        if (n < 2) {
            printf("-1\n");
            continue;
        } else if (n <= 20) {
            for (int i=1; ; ++i) {
                int j = i, sum = 0;
                while (j) {
                    sum += stick[j % 10];
                    j /= 10;
                }
                if (sum == n) {
                    printf("%lld\n",i);
                    break;
                }
            }
            continue;
        }
        switch (n % 7) {
            case 0 : {
                while (n > 0) {
                    printf("8");
                    n -= 7;
                }
                printf("\n");
                break;
            }
            case 1 : {
                printf("10"), n -= 8;
                while (n > 0) {
                    printf("8");
                    n -= 7;
                }
                printf("\n");
                break;
            }
            case 2 : {
                printf("1"), n -= 2;
                while (n > 0) {
                    printf("8");
                    n -= 7;
                }
                printf("\n");
                break;
            }
            case 3 : {
                printf("200"), n -= 17;
                while (n > 0) {
                    printf("8");
                    n -= 7;
                }
                printf("\n");
                break;
            }
            case 4 : {
                printf("20"), n -= 11;
                while (n > 0) {
                    printf("8");
                    n -= 7;
                }
                printf("\n");
                break;
            }
            case 5 : {
                printf("2"), n -= 5;
                while (n > 0) {
                    printf("8");
                    n -= 7;
                }
                printf("\n");
                break;
            }
            case 6 : {
                printf("6"), n -= 6;
                while (n > 0) {
                    printf("8");
                    n -= 7;
                }
                printf("\n");
                break;
            }
        }
    }
    return 0;
}