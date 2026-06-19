#include <stdio.h>
#include <stdlib.h>
#define NUMBER 5

/*--自定义函数：返回拥有n个元素的数组v中的最大值--*/
int Max_of(int v[],int n)
{
	int i,max=0;
	for(i=0;i<n;i++)
		if(v[i]>max) max=v[i];
    return max;
}

/*---主函数---*/ 
int main()
{
	system("color 70");
    int i,eng[NUMBER],math[NUMBER],max_e,max_m;
    printf("请输入%d名学生的成绩。\n",NUMBER);
    for(i=0;i<NUMBER;i++){
		printf("[%d]英语：",i+1);  scanf("%d",&eng[i]);
		printf("   数学：");       scanf("%d",&math[i]); 
    }
    max_e=Max_of(eng,NUMBER);   //调用Max_of函数
    max_m=Max_of(math,NUMBER);  //调用Max_of函数
    printf("英语最高分=%d\n",max_e);
    printf("数学最高分=%d\n",max_m);
    system("pause");
    return 0;
}

