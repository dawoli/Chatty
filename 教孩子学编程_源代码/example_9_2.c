#include <stdio.h>
#include <stdlib.h>
struct student{   //声明结构体student用于表示学生信息
	char name[40];      //学生姓名
	float score;       //期末平均成绩
	float cScore;  //班级评议成绩
	int cadre;          //是否班干部（1:是 0:不是）
	int award1,award2,award3;         //竞赛获的三等奖次数
    long int money;     //获得奖学金总额
};
struct student stu; //定义一个student结构体对象stu
/*--主函数--*/
int main(){
    printf("学生姓名：");    	 scanf("%s",stu.name);
    printf("期末平均成绩：");    scanf("%f",&stu.score);
    printf("班级评议成绩：");    scanf("%f",&stu.cScore);
    printf("是否班干部(1:是 0:不是):"); scanf("%d",&stu.cadre);
    printf("竞赛获得一等奖次数：");     scanf("%d",&stu.award1);
    printf("竞赛获得二等奖次数：");     scanf("%d",&stu.award2);
    printf("竞赛获得三等奖次数：");     scanf("%d",&stu.award3);
	stu.money = stu.award1*800 + stu.award2*500 + stu.award3*300;
    if(stu.score>95 && stu.cScore>90)
		stu.money += 2000;
    else
		if(stu.score>90 && stu.cScore>85)
			stu.money += 1500;
        else
			if(stu.score>85 && stu.cScore>80)
				stu.money += 1000;
	if(stu.cadre==1 && stu.cScore>80)
		stu.money += 500;
    printf("%s同学获得奖学金%ld元\n",stu.name,stu.money);
	system("pause");
	return 0;
}
