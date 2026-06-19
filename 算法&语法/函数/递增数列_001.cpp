#include<iostream>
using namespace std;
 
int f(int a)
{
	if(a==1)
	return 1;//终止的条件
	if(a>1)
	return a+f((a-1));//不断调用自己，令a减少到1，走到出口
}
int main()
{
	int i;
	cin>>i;
	cout<<f(i);
	return 0;
}
