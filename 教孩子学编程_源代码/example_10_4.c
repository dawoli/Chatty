#include <stdio.h>
#include <stdlib.h>
/*--自定义函数：将指针px、py指向的变量的值进行互换--*/
void swap(int *px, int *py){
    int temp = *px;
    *px = *py;
    *py = temp;
}
/*--主函数--*/
int main(){
    system("color 70");
    int dA, dB;
    puts("请输入两个整数：");
    printf("整数dA：");    scanf("%d",&dA);
    printf("整数dB：");    scanf("%d",&dB);
    swap(&dA, &dB);
    puts("互换以后的变量值：");
    printf("    dA = %d\n",dA);
    printf("    dB = %d\n\n",dB);
    system("pause");
    return 0;
}

