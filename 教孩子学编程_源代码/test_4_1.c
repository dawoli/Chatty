/* 求长方形的面积 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	/* 变量声明 */
    system("color 70");  //设置屏幕背景色为白色，前景色为黑色
	int width;  //长方形的长
    int height;     //长方形的宽
    puts("求长方形的面积：");//puts()函数显示后自动换行
    printf("输入长：");     //printf()函数显示后不换行
    scanf("%d",&width);  //从键盘读取十进制整数
    printf("输入宽：");
    scanf("%d",&height);
    printf("面积是：%d。\n",width*height);
    printf("\n");
	system("pause");
	return 0;
}
