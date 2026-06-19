#include <stdio.h>
#include <stdlib.h>
int main()
{
	int s = 1;
    FILE *fp;
    char name[100];
    double height,weight;

	fp = fopen("test10_2.txt","w");
    printf("请连续输入姓名、身高、体重（空格分隔）并回车。\n");
    printf("结束输入请输入0并回车。\n");
    while(s==1){
		scanf("%s",name);
        if(strcmp(name,"0")==0){
			s=0;
            break;
        }
		scanf("%lf",&height);
		scanf("%lf",&weight);
        fprintf(fp,"%-10s %5.1f %5.1f\n",name,height,weight);
    }
    fclose(fp);

	system("pause");
	return 0;
}
