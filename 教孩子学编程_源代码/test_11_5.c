#include <stdio.h>
#include <stdlib.h>
#define FILENAME_MAX 1024
int main(){
    char ch;
    int lines=0;
    FILE *sfp;                              //
    char sname[FILENAME_MAX];            //原文件名
    printf("打开原文件：");   scanf("%s",sname);
    if((sfp = fopen(sname,"r")) == NULL)     //打开原文件
        printf("\a原文件打开失败！\n");
    else {
        while((ch=fgetc(sfp))!=EOF){ //读取原文件中的字符
            putchar(ch);               //将字符显示在屏幕上
            if(ch=='\n') lines += 1;   //统计行数
        }
        lines += 1;  //计入最后一行
        printf("\n文件%s共有%d行。\n",sname,lines);
 
        fclose(sfp);                       //关闭原文件
    }
    system("pause");
    return 0;
}
