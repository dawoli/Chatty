#include<iostream>
using namespace std;
int n;
int a[10]={6,2,5,5,4,5,6,3,7,6};
void judge(int n){
	if(n==1){
		cout<<-1<<endl;
	}else if(n==2){
		cout<<1<<endl;
	}else if(n==3){
		cout<<7<<endl;
	}else if(n==4){
		cout<<4<<endl;
	}else if(n==5){
		cout<<2<<endl;
	}else if(n==6){
		cout<<6<<endl;
	}else if(n==7){
		cout<<8<<endl;
	}else if(n==8){
		cout<<16<<endl;
	}else if(n==9){
		cout<<18<<endl;
	}else{
		cout<<23<<endl;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("stick.out","w",stdout);
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		if(x%7==0){
			for(int i=1;i<=x/7;i++){
				cout<<8;
			}
			cout<<endl;
		}else if(x%7==1){
			cout<<26;
			for(int i=1;i<x/7;i++){
				cout<<8;
			}
			cout<<endl;
		}else{
			judge(x);
		}
	}
	return 0;
}
