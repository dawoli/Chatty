#include <stdio.h>
#include <stdlib.h>
#define FILENAME_MAX 1024
int main(){
    char ch;
    FILE *sfp;                              //原文件指针
    FILE *dfp;                              //目标文件指针
    char sname[FILENAME_MAX];            //原文件名
    printf("打开原文件：");   scanf("%s",sname);
    if((sfp = fopen(sname,"r")) == NULL)     //打开原文件
        printf("\a原文件打开失败！\n");
    else {
        dfp = fopen("test10_4.txt","w");
        while((ch=fgetc(sfp))!=EOF){ //读取原文件中的字符
            putchar(ch);               //将字符显示在屏幕上
            fputc(ch,dfp);             //将字符写入目标文件
        }
        fclose(dfp);                   //关闭目标文件
        fclose(sfp);                       //关闭原文件
    }
    system("pause");
    return 0;
}
