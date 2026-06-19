#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;  
	int a=n/100;     
	int b=n/10%10;  
	int c=n%10;     
	int d=c*100+b*10+a;
	cout<<d<<endl;
	return 0;
}
