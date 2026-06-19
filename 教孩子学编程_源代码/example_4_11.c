#include <stdio.h>      //包含头文件stdio.h
#include <string.h>     //包含头文件string.h
#include <stdlib.h>     //包含头文件stdlib.h
int print(){  //自定义函数
printf("\n\n\n");
printf("    ╔══════ C语言关机程序════╗\n");
printf("    ║                                  ║\n");
printf("    ║ ※ 1.实现10分钟内的定时关闭计算机║\n");
printf("    ║ ※ 2.立即关闭计算机              ║\n");
printf("    ║ ※ 3.注销计算机　                ║\n");
printf("    ║ ※ 0.退出系统                    ║\n");
printf("    ║                                  ║\n");
printf("    ╚═════════════════╝\n\n");
printf("     请选择输入（0-3），然后回车：");
return 0;
}
void main(){
system("title C语言关机程序");         //设置cmd窗口标题
system("mode con cols=48 lines=25");//设置窗口宽度高度
system("color 0B");  //设置窗口内背景色和前景色
system("date /T");   //显示当前日期
system("TIME /T");   //显示当前时间
char cmd[20]="shutdown -s -t ";
char t[5]="0";
print();  //调用自定义函数print()
int c;
//scanf("%d",&c);      //获取键盘输入
c=getchar();            //获取键盘输入的一个字符
switch(c){
case 1:printf("您想多少秒后自动关机？（0~600）\n");
scanf("%s",t);
system(strcat(cmd,t));break;     //连接两个字符串
case 2:system("shutdown -p");break;    //自动关机
case 3:system("shutdown -l");break;    //自动注销
case 0:break;
default:printf("Error!\n");
}
system("pause");    //锁定屏幕
exit(0);             //退出程序
}
