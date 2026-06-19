#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,S;
    int a[100];
    printf("从低到高输入成绩（空格分隔），\n");    
    printf("全部输入后，输入0并回车！\n");
    for(i=0;i<100;i++){    //用for循环给数组元素赋值
        scanf("%d",&a[i]);
        if(a[i]==0) break; //接收到0，则退出循环
    }
    printf("名次查询（输入0结束查询）：\n");
    int L,R,mid,R0=i;
    do{
		printf("输入成绩：");
        scanf("%d",&S);
        if(S==0) break;         //输入0结束查询
        L=1;R=R0;
        while(L<=R){
			mid=(L+R)/2; printf("%d %d %d\n",L,mid,R);
			if(a[mid-1]==S) break;       //找到目标退出循环
            if(a[mid-1]>S) R=mid-1;      //进入左半区间
            else if(a[mid-1]<S) L=mid+1; //进入右半区间
             printf("%d A %d\n\n",L,R);
        }
        if(a[mid-1]==S)
			printf("%d\n",mid); //输出名次
        else
			printf("未找到该成绩！");
    }while(S!=0);
	system("pause");
	return 0;
}
