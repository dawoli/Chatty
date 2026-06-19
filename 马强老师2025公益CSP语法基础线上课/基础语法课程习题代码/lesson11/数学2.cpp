/*
  2 5 5/2=2 2+1
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,t,s,sum=0;
	cin>>m>>t>>s;
	if(s%t==0) sum=s/t;
	else sum=s/t+1;
	if(m>=sum)
		cout<<m-sum<<endl;
	else 
		cout<<0<<endl;
	return 0;
}
