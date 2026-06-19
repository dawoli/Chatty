#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("color 70");  //设置显示屏前景色7和背景色0
    int i,inner,outer,temp;
    int nums[10];
    printf("排序前：");
    for(i=0;i<10;i++)    //随机生成10个数并输出
    {
		nums[i]=1+rand()%99;
        printf("%d ",nums[i]);
    }
    for(outer=0;outer<9;outer++)   //外层循环
		for(inner=outer+1;inner<10;inner++)  //内层循环
        {
			if(nums[inner]<nums[outer])
            {
				temp=nums[outer];
                nums[outer]=nums[inner];
                nums[inner]=temp;
            }
        }
    printf("\n排序后：");
    for(i=0;i<10;i++)    //输出排序后的数列
        printf("%d ",nums[i]);
	printf("\n");
    system("pause");
	return 0;
}
