#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,total=0;
    int a[100];
    for(i=0;i<100;i++)             //用for循环给数组元素赋值
    {
        printf("输入第%d个数：",i+1);
        scanf("%d",&a[i]);      
    }
    for(i=99;i>=0;i--)                //用for循环遍历数组
    {
        printf("%d ",a[i]);           //按下标倒序输出数组元素
        if(a[i]%2==0) total+=a[i];   //累加偶数元素        
    }
    printf("\n所有偶数之和total=%d\n",total);
    system("pause");
    return 0;
}
