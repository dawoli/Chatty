#include <stdio.h>
#include <stdlib.h>
int main(){
    float s,f;
    printf("输入消费额：\n");
    scanf("%f",&s);
    if (s<50)
        f = s;
    else
        if (s<100)
            f = s*0.9;            //9折
        else
            if (s<200)
                f = s*0.8;        //8折
            else
                if (s<300)
                    f = s*0.7;    //7折
                else
                    f = s*0.6;    //6折
    printf("实际付款额为：%.2f元\n",f);
    system("pause");
    return 0;
}
