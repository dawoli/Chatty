#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,t,s,sum=0;
	cin>>m>>t>>s;
	while(s>=t){
		sum++;
		s=s-t;
	}
	if(s!=0){
		int t=m-sum-1;
		if(t<=0) 
			cout<<0<<endl;
		else
    		cout<<t<<endl;
	}
		
	else{//s==0
		int t=m-sum;
		if(t<=0) 
			cout<<0<<endl;
		else
			cout<<t<<endl;

	}		
	return 0;
}

