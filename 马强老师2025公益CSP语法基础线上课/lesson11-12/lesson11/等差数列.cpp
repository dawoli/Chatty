/*
  5-2=8-5=11-8
  首项=2，前后项的差=3
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a1=2,sum=0,n;
	cin>>n;
	int i=1;
	int an=a1+(n-1)*3;
	sum=(a1+an)*n/2;
	/*
	while(i<=n){
		sum+=a;
		a=a+3;
		i++;
	}*/
	cout<<sum<<endl;
	
	return 0;
}
