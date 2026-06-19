#include <stdio.h>
#include <stdlib.h>

int main(){
	struct student{ //声明结构体student
		char id[5];      //学生学号（四位）
		char name[40];   //学生姓名
		float score;     //期末总成绩
		int num;         //名次
	}stu[100],temp; //定义结构体对象数组stu和临时对象temp
	int i,j,n;
    printf("输入学生人数（1~100）：");
    scanf("%d",&n);
    printf("-----------------------\n");
    for(i=0;i<n;i++){  //输入学生成绩
		printf("学号输入9999则停止输入！\n");
		printf("学号(9999):"); scanf("%s",&stu[i].id);
        if(strcmp(stu[i].id,"9999")==0){
			n=i;
            break;
        }
		printf("姓名：");	scanf("%s",&stu[i].name);
		printf("总成绩：");	scanf("%f",&stu[i].score);
        printf("-----------------------\n");    
    }
	for(i=0;i<n;i++){  //按成绩排序（冒泡法）
		for(j=i+1;j<n;j++)
			if(stu[i].score<stu[j].score){
				temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }         //结构体变量整体交换
        stu[i].num = i+1;
    }
    printf("----------------------------------\n");
    printf("  学号       姓名       成绩  名次\n");
	for(i=0;i<n;i++){  //输出名次
		printf("%+6s",stu[i].id);
		printf("%+12s",stu[i].name);
		printf("%10.2f",stu[i].score);
		printf("%4d\n",stu[i].num);
    }    
    printf("\n\n");
	system("pause");
	return 0;
}
