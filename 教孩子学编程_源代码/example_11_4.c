#include <stdio.h>
int main(){
    struct student{ //声明结构体student
        char id[5];       //学生学号（四位）
        char name[40];   //学生姓名
        float score;     //期末总成绩
        int num;          //名次
    }stu[100],temp; //定义结构体对象数组stu和临时对象temp
    int i,j,n;
    FILE *fin, *fout;                      //定义文件指针
    fin = fopen("scoreIn.txt","r");     //打开输入文件
    fout = fopen("scoreOut.txt","w");   //打开输出文件
    fscanf(fin,"%d\n",&n);  //读取学生人数
    for(i=0;i<n;i++){        //逐行读取学生信息
        fscanf(fin,"%s",stu[i].id);
        fscanf(fin,"%s",stu[i].name);
        fscanf(fin,"%f\n",&stu[i].score);
    }
    for(i=0;i<n;i++){        //按成绩排序（冒泡法）
        for(j=i+1;j<n;j++)
            if(stu[i].score<stu[j].score){
                temp=stu[i]; stu[i]=stu[j]; stu[j]=temp;
            }                   //结构体变量整体交换
        stu[i].num = i+1;
    }
    for(i=0;i<n;i++){       //逐行输出到文件
        fprintf(fout,"%s ",stu[i].id);
        fprintf(fout,"%s ",stu[i].name);
        fprintf(fout,"%.2f ",stu[i].score);
        fprintf(fout,"%d\n",stu[i].num);  //输出名次
    }    
    fclose(fin); fclose(fout);             //关闭文件
    return 0;
}
