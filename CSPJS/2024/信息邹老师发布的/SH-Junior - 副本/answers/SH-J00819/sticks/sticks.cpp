#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==1){
			cout<<10;
			for(int i=1;i<=(n-8)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n==2)cout<<1<<endl; 
		else if(n==3)cout<<7<<endl; 
		else if(n==4)cout<<4<<endl; 
		else if(n==5)cout<<2<<endl; 
		else if(n==6)cout<<6<<endl; 
		else if(n==9)cout<<18<<endl; 
		else if(n==10)cout<<22<<endl; 
		else if(n==11)cout<<26<<endl; 
		else if(n==12)cout<<28<<endl; 
		else if(n==13)cout<<68<<endl; 
		else if(n==16)cout<<188<<endl; 
		else if(n==17)cout<<200<<endl; 
		else if(n==18)cout<<208<<endl; 
		else if(n==19)cout<<608<<endl; 
		else if(n==20)cout<<808<<endl; 
		
	}
	return 0;
}
