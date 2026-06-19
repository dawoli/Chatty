#include<iostream>
using namespace std;
int main(){
	double r,a,b;
	//年利率为r 本金a元钱 将会超过b元
	scanf("%lf%lf%lf",&r,&a,&b);//cin>>r>>a>>b;
	int y=0;
	while(a<=b){
		a+=a*(r/100);
		y++;
	}
	printf("%d %.2lf",y,a);
	//%lf double %d int %lld long long 
	//%c char 
	return 0;
}
//4141
