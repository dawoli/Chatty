#include<iostream>
using namespace std;
int main(){
	int n,m=0; //m:存储反转之后的数字
	cin>>n;//-380
	while(n!=0){
		m=m*10+n%10; //-83
		n/=10; //-38 -3 0
	}
	cout<<m;
	return 0;
}
