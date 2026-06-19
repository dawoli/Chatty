#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,S;
    int a[100];
    printf("从高到低输入成绩（空格分隔），\n");    
    printf("全部输入后，输入0并回车！\n");
    for(i=0;i<100;i++){    //用for循环给数组元素赋值
        scanf("%d",&a[i]);
        if(a[i]==0) break; //接收到0，则退出循环
    }
    printf("名次查询（输入0结束查询）：\n");
    do{
		printf("输入成绩：");
        scanf("%d",&S);
        i=0;
        if(S==0) break;         //输入0结束查询
        while(a[i]!=0){
			if(a[i]==S) break;  //找到目标退出循环
            i++;
        }
        if(a[i]==S)
			printf("%d\n",i+1); //输出名次
        else
			printf("未找到该成绩！");
    }while(S!=0);
	system("pause");
	return 0;
}
