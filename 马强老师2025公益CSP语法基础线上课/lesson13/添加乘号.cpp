/*
 2147483647 
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	char c;
	long long x=10,flag=0;
	long long b,a,a1,a2;
	cin>>b>>c>>a;
	while(1) {
		a1=a/x;
		a2=a%x;
		if(a1==0) break;
		if(a1*a2==b){
			flag=1;
			break;
		}
		x=x*10;
	}	
	if(flag==0) cout<<"Impossible"<<endl;
	else printf("%d=%d*%d",b,a1,a2);
	return 0;
}
