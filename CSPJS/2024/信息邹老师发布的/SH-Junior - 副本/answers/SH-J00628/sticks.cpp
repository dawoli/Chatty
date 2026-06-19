#include<bits/stdc++.h>
using namespace std;
long fh(long num,long ws){
	long a;
	if(num==1) return -10; 
	if(num>6&&num%6!=3){
		return (fh(num-6,ws+1)+0)*10^(ws-1);
	}
	else if(num>6&&num%6==3){
		return (fh(num-5,ws+1)+2)*10^(ws-1);
	}
	else if(num==7){
		a=8;
		for(int i=0;i<ws;i++){
			a*=10;
		}
		return a;
	}
	else if(num==6){
		a=6;
		for(int i=0;i<ws;i++){
			a*=10;
		}
		return a;
	}
	else if(num==5){
		a=2;
		for(int i=0;i<ws;i++){
			a*=10;
		}
		return a;
	}
	else if(num==4){
		a=4;
		for(int i=0;i<ws;i++){
			a*=10;
		}
		return a;
	}
	else if(num==3){
		a=7;
		for(int i=0;i<ws;i++){
			a*=10;
		}
		return a;
	}
	else if(num==2){
		a=1;
		for(int i=0;i<ws;i++){
			a*=10;
		}
		return a;
	}
}
int main(){
	long all,num,ans[100],ws=1;
	cin>>all;
	for(int i=0;i<all;i++){
		cin>>num;
		ans[i]=fh(num,ws);
	}
	for(int i=0;i<all;i++){
		cout<<ans[i]/10<<endl;
	}
}
