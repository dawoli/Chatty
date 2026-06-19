#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i;
    float x,max_height,min_height;
    printf("输入全班同学人数（个）：\n");
    scanf("%d",&n);
    printf("输入第1位同学的身高（cm）：\n");   
    scanf("%f",&x); 
    max_height = x;    //初始化最大身高值
    min_height = x;    //初始化最小身高值
    for(i=1;i<n;i++)
    {
        printf("输入第%d位同学的身高（cm）：\n",i+1);
        scanf("%f",&x);
        if(x>max_height) max_height = x;
        else if(x<min_height) min_height = x;
    }
    printf("全班%d位同学身高最大值：%.2fcm\n",n,max_height);
    printf("全班%d位同学身高最小值：%.2fcm\n",n,min_height);
    system("pause");
    return 0;
}
