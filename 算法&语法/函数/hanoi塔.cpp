#include<iostream>
using namespace std;
int step=1;//计算step的总数需要定义全局变量，在move的前面
void move(char x,char y)
{
 cout<<step<<x<<"-->"<<y<<endl;
 step++;
}
void hanoi(int n,char a,char b,char c)
{
 if(n==1)
 {
  move(a,c);//调用move函数，将a上唯一盘子移到c
 }
 else
 {
  hanoi(n-1,a,c,b);//将n-1个盘子从a移动到b
  move(a,c);//调用move函数，将a中剩余盘子移动到c
  hanoi(n-1,b,a,c);//将b中n-1个盘子移动到c
 }
}
int main()
{
 int n;
 cout<<"请输入盘子的个数:";
 cin>>n;
 hanoi(n,'a','b','c');
 return 0;
}
