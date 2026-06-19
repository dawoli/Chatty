#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num = 0;
    FILE *fp1,*fp2;
    char name[100];
    double height,weight,hSum=0.0,wSum=0.0;
    if((fp1 = fopen("fin.txt","r")) == NULL)
		printf("\a文件fin.txt打开失败！\n");
    else{
		fp2 = fopen("fout.txt","w");
        while(fscanf(fp1,"%s%lf%lf",name,&height,&weight) == 3){
			printf("%-10s %5.1f %5.1f\n",name,height,weight);
            fprintf(fp2,"%-10s %5.1f %5.1f\n",name,height,weight);
        	num++;
			hSum += height;
            wSum += weight;
		}
		printf("----------------------\n");
        printf("平均       %5.1f %5.1f\n",hSum/num,wSum/num);
        fprintf(fp2,"----------------------\n");
        fprintf(fp2,"平均       %5.1f %5.1f\n",hSum/num,wSum/num);
        fclose(fp1); fclose(fp2);
    }
	system("pause");
	return 0;
}
