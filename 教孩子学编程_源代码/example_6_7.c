#include <stdio.h>
#include <stdlib.h>
int main(){
    int year,month;
    printf("请输入年份和月份（两个整数，空格分隔）：\n");
    scanf("%d %d",&year,&month);
switch (month)
{
        case 4: 
        case 6: 
        case 9:
        case 11:printf("%d年%d月有30天。\n",year,month); break;
        case 1: case 3: case 5: case 7: case 8: case 10:
        case 12:printf("%d年%d月有31天。\n",year,month); break;
        case 2:if((year%400==0)||((year%4==0)&&(year%100!=0)))
                    printf("%d年%d月有29天。\n",year,month); 
                else
                    printf("%d年%d月有28天。\n",year,month); 
                break;
        default:printf("输入有误！\n");
    }
    system("pause");
    return 0;
}
