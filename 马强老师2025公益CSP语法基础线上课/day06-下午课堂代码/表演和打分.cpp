#include<iostream>
using namespace std;
int main(){
	int sum=0,max=0,min=100,m;
	for(int i=1;i<=10;i++){
		cin>>m;//老师的打分
		sum+=m;
		if(max<m)	max=m;
		if(min>m)	min=m;
	}
	printf("%.3lf",(sum-max-min)/8.0);
	return 0;
}
