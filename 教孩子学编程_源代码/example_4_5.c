#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("\n“+”标志输出右对齐的带符号数据：\n\n");
    printf("%+10d %+10.2f %+10s\n",56,-809.56,"American");
    printf("%+10d %+10.2f %+10s\n",5668,-23.5,"USA");
    printf("\n“-”标志输出左对齐的数据：\n\n");
    printf("%-10d %-10.2f %-10s\n",56,-809.56,"American");
    printf("%-10d %-10.2f %-10s\n",5668,-23.5,"USA");
    printf("\n“#”标志输出带前缀的八进制数和十六进制数：\n\n");
    printf("    %#o %#x\n",0546,0x5B);
    printf("\n输出不带前缀的八进制数和十六进制数：\n\n");
    printf("    %o %x\n\n\n ",0546,0x5B);
    system("pause");
    return 0;
}
