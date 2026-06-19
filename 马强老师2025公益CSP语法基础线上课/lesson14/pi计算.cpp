/*
  计算π
  分子：4
  分母：1,3,5,7,9,11……
  运算符：+-+-+-
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	double sum=0;
	int b=1,flag=1;
	for(int i=1;i<=500000;i++){
		sum+=flag*4.0/b;
		b+=2;
		flag=-flag;
	}
	cout<<fixed<<setprecision(6)<<sum<<endl;
	return 0;
}
