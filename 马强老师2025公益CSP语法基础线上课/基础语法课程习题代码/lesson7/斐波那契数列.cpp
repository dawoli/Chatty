#include <iostream>
using namespace std;
int main() {
	int k,a=1,b=1,c; 
	cin>>k;
	cout<<a<<" "<<b<<' ';
	for(int i=3;i<=k;i++){
		c=a+b;
		cout<<c<<" ";
		a=b;
		b=c;
	}
	return 0;
}

