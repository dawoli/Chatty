#include <stdio.h>
#include <stdlib.h>

struct student{ //声明结构体student
	int id;         //学生学号（四位）
	float ch;       //语文成绩
	float ma;       //数学成绩
	float en;       //英语成绩
	float score;     //总成绩
	int num;         //名次
}stu[100],temp; //定义结构体对象数组stu和临时对象temp

void swap(struct student a,struct student b){
	temp = a;
    a = b;
    b = temp;
}
int main(){
	int i,j,n;
    printf("输入学生人数（1~100）：");
    scanf("%d",&n);
    printf("-----------------------\n");
    for(i=0;i<n;i++){  //输入学生成绩
		printf("学号输入0则停止输入！\n");
		printf("学号(9999):"); scanf("%d",&stu[i].id);
        if(stu[i].id==0){
			n=i;
            break;
        }
		printf("语文成绩：");	scanf("%f",&stu[i].ch);
		printf("数学成绩：");	scanf("%f",&stu[i].ma);
		printf("英语成绩：");	scanf("%f",&stu[i].en);
		stu[i].score = stu[i].ch + stu[i].ma + stu[i].en;
        printf("总成绩：%.2f\n",stu[i].score);
        printf("-----------------------\n");    
    }
	for(i=0;i<n;i++){  //按成绩排序（冒泡法）
		for(j=i+1;j<n;j++)
			if(stu[i].score<stu[j].score){
                swap(stu[i],stu[j]);
            }else {
				if(stu[i].score==stu[j].score && stu[i].ch<stu[j].ch){
					swap(stu[i],stu[j]);
                }else {
					if(stu[i].score==stu[j].score && stu[i].ch==stu[j].ch && stu[i].ma<stu[j].ma){
						swap(stu[i],stu[j]);
                    }else {
						if(stu[i].score==stu[j].score && stu[i].ch==stu[j].ch && stu[i].ma==stu[j].ma && stu[i].en<stu[j].en){
							swap(stu[i],stu[j]);
                        }else {
							if(stu[i].score==stu[j].score && stu[i].ch==stu[j].ch && stu[i].ma==stu[j].ma && stu[i].en==stu[j].en && stu[i].id<stu[j].id){
								swap(stu[i],stu[j]);
                            }
                        }
                    }
                }
            }
        stu[i].num = i+1;
    }
    printf("------------------------------------\n");
    printf("学号  语文  数学  英语  总成绩  名次\n");
	for(i=0;i<n;i++){  //输出名次
		printf("%04d",stu[i].id);
		printf("%6.2f",stu[i].ch);
		printf("%6.2f",stu[i].ma);
		printf("%6.2f",stu[i].en);
		printf("%8.2f",stu[i].score);
		printf("%4d\n",stu[i].num);
    }    
    printf("\n\n");
	system("pause");
	return 0;
}
