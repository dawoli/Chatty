#include<iostream>
using namespace std;
int main(){
	int h1,h2,m1,m2,s1,s2;
	scanf("%d:%d:%d",&h1,&m1,&s1);
	scanf("%d:%d:%d",&h2,&m2,&s2);
	int a1=h1*3600+m1*60+s1;
	int a2=h2*3600+m2*60+s2;
	int t=a2-a1; //两个时间的差值(秒)
	int h3=t/3600; 
	int m3=t/60%60;
	int s3=t%60;
	printf("%02d:%02d:%02d",h3,m3,s3);
	return 0;
}
//
