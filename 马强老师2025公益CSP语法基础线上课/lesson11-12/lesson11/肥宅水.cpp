/*
  
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int a=1,b=2;
	while(n>=b){
		cout<<a<<' '<<b<<endl;
		n-=b;
		a++;
		b+=2;
	}
	return 0;
}
