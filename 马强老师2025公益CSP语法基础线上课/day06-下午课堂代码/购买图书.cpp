#include<iostream>
using namespace std;
double a[6]={0,28.9,32.75,45.6,78.0,35.7};
int main(){
	int m; //代表购买5种图书的本数
	double sum=0;
	for(int i=1;i<=5;i++){
		scanf("%d",&m);	
		sum+=m*a[i];
	}
	printf("%.2f",sum);
	return 0;
}
//\t tab    \n换行
