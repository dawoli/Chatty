#include<iostream>
using namespace std;
int main(){
	int n,sum=0;
	cin>>n;
	while(n){ //数位分离
		sum+=n%10;	
		n/=10;
	}
	cout<<sum;
	return 0;
}
