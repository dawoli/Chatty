#include<iostream>
using namespace std;
int main(){
	int n,ans=0;
	cin>>n;
	// 365 365/10=36  36/10=3 3/10=0
	while(n){ //n!=0
		//cout<<n%10<<' ';
		n/=10; //去掉当前的个位
		ans++;
	}
	cout<<ans;
	return 0;
}
