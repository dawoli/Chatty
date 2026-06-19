#include<bits/stdc++.h>
using namespace std;
int times;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>times;
	for(int i=1;i<=times;i++){
		int t;
		cin>>t;
		if(t<2){
			cout<<-1<<endl;
			continue;
		}
		else if(t%7==0){
			for(int k=1;k<=(t/7);k++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		else if((t-1)%7==0){
			cout<<10;
			for(int k=1;k<=(t-1)/7-1;k++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		else if(t==2){
			cout<<1<<endl;
			continue;
		}
		else if(t==3){
			cout<<7<<endl;
			continue;
		}
		else if(t==4){
			cout<<4<<endl;
			continue;
		}
		else if(t==5){
			cout<<2<<endl;
			continue;
		}
		else if(t==6){
			cout<<6<<endl;
			continue;
		}
		else if(t==7){
			cout<<8<<endl;
			continue;
		}
		else if(t==8){
			cout<<10<<endl;
			continue;
		}
		else if(t==9){
			cout<<18<<endl;
			continue;
		}
		else if(t==18){
			cout<<208<<endl;
			continue;
		}
		else if(t==10){
			cout<<22<<endl;
			continue;
		}
		else if(t==11){
			cout<<20<<endl;
			continue;
		}
		else if(t==12){
			cout<<27<<endl;
			continue;
		}
		else if(t==13){
			cout<<70<<endl;
			continue;
		}
		else if(t==16){
			cout<<188<<endl;
			continue;
		}
		else if(t==17){
			cout<<200<<endl;
			continue;
		}
		else if(t==19){
			cout<<288<<endl;
			continue;
		}
		else if(t==20){
			cout<<688<<endl;
			continue;
		}
		else if(t%7==5){
			cout<<2;
			for(int k=1;k<=t/7;k++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
	}
	return 0;
} 
