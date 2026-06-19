#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("\n\n\n");
    printf("    ╔══════ C语言关机程序════╗\n");
    printf("    ║                                  ║\n");
    printf("    ║ ※ 1.实现10分钟内的定时关闭计算机║\n");
    printf("    ║ ※ 2.立即关闭计算机              ║\n");
    printf("    ║ ※ 3.注销计算机　                ║\n");
    printf("    ║ ※ 0.退出系统                    ║\n");
    printf("    ║                                  ║\n");
    printf("    ╚═════════════════╝\n\n");
    printf("     请选择输入（0-3），然后回车：");
    int ss;
    scanf("%d",&ss);
    printf("\n\n\n");
    system("pause");
    return 0;
}
