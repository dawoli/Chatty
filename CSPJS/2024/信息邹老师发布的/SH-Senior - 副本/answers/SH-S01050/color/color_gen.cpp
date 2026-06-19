#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("color.in","w",stdout);
    printf("10\n");
    for (int i=1;i<=10;i++) {
        printf("%d\n",200000-i);
        for (int j=1;j<=200000-i;j++) {
            printf("1000000");
            if (j==200000-i) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
