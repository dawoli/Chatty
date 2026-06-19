#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	cout<<n;
	while(n!=1){
		if(n%2==0){ //偶数 则除以2
			n/=2; //n=n/2;
		}else{
			n=n*3+1; //奇数 则乘3加1
		}
		cout<<' '<<n;
	}
	return 0;
}
