#include <stdio.h>
#include <stdlib.h>
int main(){
    int age;
    float weight;
    char Name[15]; 
    printf("\n请输入您的姓名：");
    scanf("%s",Name);
    printf("请输入您的年龄：");
    scanf("%d",&age);
    printf("请输入您的体重（公斤）：");
    scanf("%f",&weight);
    printf("\n以下是您输入的个人信息：\n");
    printf("姓名：%s\n",Name);
    printf("年龄：%d\n",age);
    printf("体重：%.2f公斤\n",weight);
    system("pause");
    return 0;
}
