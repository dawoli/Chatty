#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		int k;
		cin>>n;
		if(n%7==1){
			k=n/7-1;
			if(k<0) cout<<-1;	
			else cout<<"10";
		}
		else if(n%7==2){
			cout<<"1";
			k=n/7;
		}
		else if(n%7==3){
			k=n/7-2;
			if(k==-1) cout<<22;
			else if(k==-2) cout<<7;
			else cout<<"200";
		}
		else if(n%7==4){
			k=n/7-1;
			if(k<0) cout<<4;
			else cout<<"20";
		}
		else if(n%7==5){
			cout<<2;
			k=n/7;
		}
		else if(n%7==6){
			cout<<6;
			k=n/7;
		}
		else k=n/7;
		for(int i=1;i<=k;i++) cout<<8;
		cout<<endl;
	}
	return 0;
}

