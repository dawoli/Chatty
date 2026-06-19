#include <iostream>
using namespace std;
int main() {
	int sum=0;
	int n=0;
	for(int i=1;i<=100;i++){
		cout<<i<<endl;
		sum+=i;
		if(sum>=1000){
			n=i;
			break;
		}
	}
	cout<<sum<<endl;
	cout<<n<<endl;
	return 0;
}
