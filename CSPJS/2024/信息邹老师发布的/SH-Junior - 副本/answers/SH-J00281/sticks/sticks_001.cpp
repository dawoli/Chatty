#include<bits/stdc++.h>
using namespace std;
int t,n;
int sticks[8][3]={{-1},{-1},{1},{7},{4},{2,3,5},{0,6,9},{8}};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		if(n<2) cout<<-1<<endl;
		else if(n==6) cout<<6<<endl;
		else if(2<=n&&n<=7&&n!=6) cout<<sticks[n][0]<<endl;
		else{
			if(n%7==0){
				for(int j=0;j<n/7;j++) cout<<8;
			}
			if(n%7==1){
				cout<<10;
				for(int j=0;j<n/7-1;j++) cout<<8;
			}
			if(n%7==2){
				cout<<1;
				for(int j=0;j<n/7;j++) cout<<8;
			}
			if(n%7==3){
				cout<<22;
				for(int j=0;j<n/7-1;j++) cout<<8;
			}
			if(n%7==4){
				cout<<20;
				for(int j=0;j<n/7-1;j++) cout<<8;
			}
			if(n%7==5){
				cout<<2;
				for(int j=0;j<n/7;j++) cout<<8;
			}
			if(n%7==6){
				cout<<6;
				for(int j=0;j<n/7;j++) cout<<8;
			}
			cout<<endl;
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
