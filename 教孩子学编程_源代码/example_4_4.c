#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("\n\n");
    printf("  计算学生的总分和平均分：\n\n");
    float maths,english,chinese;
    float average,sum;
    char stuName[]="王小石";
    maths=94.5;
    english=96;
    chinese=88;
    sum=maths+english+chinese;
    printf("    %s同学的总分：%.1f\n",stuName,sum);
    printf("    %s同学的平均分：%.2f\n",stuName,sum/3);
    printf("\n\n\n");
    system("pause");
    return 0;
}
