#include<iostream>
using namespace std;
	int t=0,i;
	int n[60];
	int num[7]={6,2,5,4,6,3,7};
	int k[7]={0,1,2,4,6,7,8};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n[i];
	}
	for(int j=0;j<i;j++){
		if(n[j]>7){
			if(n[j]==8){
			cout<<10<<endl;	
			}
			if(n[j]==9){
			cout<<18<<endl;	
			}
			if(n[j]==10){
			cout<<22<<endl;	
			}
			if(n[j]==11){
			cout<<20<<endl;	
			}
			if(n[j]==12){
			cout<<28<<endl;	
			}
			if(n[j]==13){
			cout<<68<<endl;	
			}
			if(n[j]==14){
			cout<<88<<endl;	
			}
			if(n[j]==15){
			cout<<108<<endl;	
			}
			if(n[j]==16){
			cout<<188<<endl;	
			}
			if(n[j]==17){
			cout<<200<<endl;	
			}
			if(n[j]==18){
			cout<<208<<endl;	
			}
			if(n[j]==19){
			cout<<288<<endl;	
			}
			if(n[j]==20){
			cout<<688<<endl;	
			}
			if(n[j]==21){
			cout<<888<<endl;	
			}
			
		}
		else if(n[j]==2){
			cout<<1<<endl;
		}
		else if(n[j]==3){
			cout<<7<<endl;
		}
		else if(n[j]==4){
			cout<<4<<endl;
		}
		else if(n[j]==5){
			cout<<2<<endl;
		}
		else if(n[j]==6){
			cout<<6<<endl;
		}
		else if(n[j]==7){
			cout<<8<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
