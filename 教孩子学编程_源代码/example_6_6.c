#include <stdio.h>
#include <stdlib.h>
int main(){
    int x;
    printf("输入一个百分制成绩（0~100的整数）：\n");
    scanf("%d",&x);
    switch (x/10)
    {
        case 10:
        case 9: printf("A\n"); break;
        case 8: printf("B\n"); break;
        case 7: printf("C\n"); break;
        case 6: printf("D\n"); break;
        default:printf("E\n"); break;
    }
    system("pause");
    return 0;
}
