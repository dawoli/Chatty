#include <stdio.h>
#include <stdlib.h>
int main(){
    system("color 70");
    int back00=10, back90=30, back80=35;
    int *son, *mother, *father;
    son = &back00;     //指针son指向back00
    mother = &back90;  //指针mother指向back90
    father = &back80;  //指针father指向back80
    printf("儿子今年的年龄：%d\n", *son);
    printf("妈妈今年的年龄：%d\n", *mother);
    printf("爸爸今年的年龄：%d\n", *father);
    puts("5年后：");
    *son = 15;    //将指针son指向的对象修改为15
    *mother = 35; //将指针mother指向的对象修改为35
    *father = 40; //将指针father指向的对象修改为40
    printf("儿子的年龄：%d\n", back00);
    printf("妈妈的年龄：%d\n", back90);
    printf("爸爸的年龄：%d\n\n\n", back80);
    system("pause");
    return 0;
}
