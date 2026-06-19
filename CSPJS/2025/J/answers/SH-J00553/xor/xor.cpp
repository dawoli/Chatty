#include <iostream>
using namespace std;
int main(){
	long long n,k,a,b;
	cin>>n>>k>>a;
	if(n==1){
		if(k==a) cout<<1;
		else cout<<0;
	}else{
		cin>>b;
		if(k==(a^b)){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
