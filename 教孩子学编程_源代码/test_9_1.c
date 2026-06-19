#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	struct person{
		char name[20];
		int count;
	}cand[3] = {"tony",0,"peter",0,"anny",0};
	char temp[20];
    int i,j;
    //for(i=1;i<=10;i++){
	printf("输入“0”结束计票！\n");
    do {
        printf("输入被投票候选人名字：");
        scanf("%s",temp);
        for(j=0; j<3; j++)
			if(strcmp(temp,cand[j].name)==0)
				cand[j].count++;
    }while(!strcmp(temp,"0")==0);
	//}
    for(i=0; i<3; i++)
		printf("%s：%d\n",cand[i].name,cand[i].count);
	system("pause");
	return 0;
}
