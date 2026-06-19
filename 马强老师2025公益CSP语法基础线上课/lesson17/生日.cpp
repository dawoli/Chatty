#include<bits/stdc++.h>
using namespace std;
struct student{
	string name;
	int year,month,day;
}a[101];
int n;//全局变量默认都是0
bool cmp(student x,student y){
	if(x.year!=y.year)
		return x.year<y.year;
	else if(x.month!=y.month)
		return x.month<y.month;
	else return x.day<y.day;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].name>>a[i].year>>a[i].month>>a[i].day;
	sort(a+1,a+1+n,cmp);//a 默认指向的0 a==a[0]地址
	for(int i=1;i<=n;i++)
		cout<<a[i].name<<endl;	
	return 0;
}
