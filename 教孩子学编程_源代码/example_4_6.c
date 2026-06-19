#include <stdio.h>
#include <stdlib.h>
int main(){
printf("\n“%%10.4f”输出宽度10带4位小数的单精度浮点数：\n\n");
printf("    %10.4f %10.4f\n",-1234.123457,3.14159);
printf("\n“%%15.8lf”输出宽度15带8位小数的双精度浮点数：\n\n");
printf("    %15.8lf %15.8lf\n",-123.123456789,3.14159);
printf("\n“%%10.4s”输出宽度10含4个字符的字符串：\n\n");
printf("    %10.4s %10.4s\n\n\n","ABCDEFGH","enlish");
system("pause");
return 0;
}
