#include <stdio.h>
int main(){
    struct student{ //声明结构体student
        char name[40];   //学生姓名
		double height,weight;
    }stu[100],temp; //定义结构体对象数组stu和临时对象temp
    int i,j,n=0;
    FILE *fin, *fout;                      //定义文件指针
    fin = fopen("test10_2.txt","r");     //打开输入文件
    fout = fopen("test10_3.txt","w");   //打开输出文件
    while(fscanf(fin,"%s%lf%lf",stu[n].name,&stu[n].height,&stu[n].weight) == 3){
        n=n+1;
    }
    for(i=0;i<n;i++){        //按成绩排序（冒泡法）
        for(j=i+1;j<n;j++)
            if(stu[i].height<stu[j].height){
                temp=stu[i]; stu[i]=stu[j]; stu[j]=temp;
            }                   //结构体变量整体交换
    }
    for(i=0;i<n;i++){       //逐行输出到文件
        fprintf(fout,"%s ",stu[i].name);
        fprintf(fout,"%.2f ",stu[i].height);
        fprintf(fout,"%.2f\n",stu[i].weight);
        printf("%-10s %6.2f %6.2f\n",stu[i].name,stu[i].height,stu[i].weight);
    }    
    fclose(fin); fclose(fout);             //关闭文件
    return 0;
}
