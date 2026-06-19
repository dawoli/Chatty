#include <stdio.h>
#include <stdlib.h>
struct date{   //声明结构体date用于表示日期
	int year,month,day;
};
/*--自定义函数：比较两个日期A和B，A早则返回1，否则返回0--*/
int compare(struct date A,struct date B){
	if(A.year<B.year)return 1;
    if(A.year==B.year && A.month<B.month)return 1;
	if(A.year==B.year && A.month==B.month && A.day<B.day)return 1;
    return 0;
}
/*--主函数--*/
int main(){
	struct date x,y;  //定义两个date结构体对象x和y
    printf("输入日期X（yyyy-mm-dd）:");
    scanf("%d-%d-%d",&x.year,&x.month,&x.day);
    printf("输入日期Y（yyyy-mm-dd）:");
    scanf("%d-%d-%d",&y.year,&y.month,&y.day);
    if(compare(x,y)) 
		printf("日期X比较早！");
    else
		printf("日期Y比较早！");
	system("pause");
	return 0;
}
