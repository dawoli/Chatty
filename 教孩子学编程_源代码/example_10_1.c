#include <stdio.h>
#include <stdlib.h>
/*--自定义函数：交换两个变量的值--*/
void swap(int a, int b){
    int temp;
    temp = a; a = b; b = temp;
}
/*--主函数--*/
int main(){
    system("color 70");
    int dA, dB;
    puts("请输入两个整数。");
    printf("整数dA：");    scanf("%d",&dA);
    printf("整数dB：");    scanf("%d",&dB);
    swap(dA,dB);
    puts("互换以后的变量值。");
    printf("dA=%d dB=%d\n",dA,dB);
    system("pause");
    return 0;
}
