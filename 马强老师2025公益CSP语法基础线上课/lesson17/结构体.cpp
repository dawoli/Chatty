/*
int 4 
float
double
char 
bool
string
long long
long                   
short int
void  空类型
 */
#include<bits/stdc++.h>
using namespace std;
int sum(){
	return 0;
}
struct student{
	int number;//学号
	int s;// 男：1，male；女：0，female
	int age;
	string name;
};
student a,t[51];
signed main(){
	a.name="zihan";
	a.age=12;
	a.number=102001;
	a.s=1;
	for(int i=1;i<=10;i++)
		cin>>t[i].number>>t[i].age>>t[i].name>>t[i].s;
	
	return 0;
}
