#include <stdio.h>
#include <stdlib.h>
int main(){
    int a,b,c;
    printf("输入三个整数（空格分割）：");
    scanf("%d %d %d",&a,&b,&c);
    if (a>b)
          if (b>c) printf("%d>%d>%d",a,b,c);
          else  //否定b>c
                if (a>c) printf("%d>%d>%d",a,c,b);
                else      printf("%d>%d>%d",c,a,b);
    else //否定a>b
          if (a>c) printf("%d>%d>%d",b,a,c);
          else  //否定a>c
                if (b>c) printf("%d>%d>%d",b,c,a);
                else      printf("%d>%d>%d",c,b,a);
    system("pause");
    return 0;
}
