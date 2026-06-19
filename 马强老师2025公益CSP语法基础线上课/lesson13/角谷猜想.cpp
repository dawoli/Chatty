/*
  
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,cnt=0;
	cin>>n;
	while(n!=1){//角谷猜想
		if(n%2==0)	n=n/2;
		else		n=n*3+1;
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
