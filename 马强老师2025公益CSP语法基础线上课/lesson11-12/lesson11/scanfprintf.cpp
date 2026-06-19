/*
  c++兼容c语言
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	scanf("%d:%d:%d",&a,&b,&c);
	int x,y,z;
	scanf("%d:%d:%d",&x,&y,&z);
	int t1=a*3600+b*60+c;
	int t2=x*3600+y*60+z;
	int t=t2-t1;//
	//1,1,2  3600+60+2
	printf("%02d:%d:%d",t/3600,(t%3600)/60,t%60);
	return 0;
}
