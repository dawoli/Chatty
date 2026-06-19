#include <stdio.h>
#include <stdlib.h>
int main()
{
    float a,b,c;
    printf("分别输入三条线段的长度（用空格分隔）：\n");
    scanf("%f %f %f",&a,&b,&c);
    if(a+b<=c||a+c<=b||b+c<=a)
        printf("不能构成三角形\n");
    else
        if((a==b)&&(b==c))
            printf("构成等边三角形\n");
        else 
            if((a*a+b*b==c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a))
                  if((a==b)||(b==c)||(a==c))
                      printf("构成等腰直角三角形\n");
                  else
                      printf("构成直角三角形\n");
            else
                  if((a==b)||(b==c)||(a==c))
                      printf("构成等腰三角形\n");
                  else
                      printf("构成普通三角形\n");
    system("pause");
    return 0;
}
