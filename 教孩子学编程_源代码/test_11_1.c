#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,i,j,m,n;
    FILE *fp;
    fp = fopen("test10_1.txt","w");
    printf("输入行数（<20）："); scanf("%d",&m);
    printf("输入列数（<20）："); scanf("%d",&n);
    if (m>20) m = 20;
    if (n>20) n = 20;
    for(i=1;i<=m;i++)
    {
		for(j=1;j<=n;j++)
        {
			a = 10*i+j;
            printf("%-4d ",a);
            fprintf(fp,"%-4d ",a);
        }
        printf("\n");
        fprintf(fp,"\n");
    }
    fclose(fp);
	system("pause");
	return 0;
}
