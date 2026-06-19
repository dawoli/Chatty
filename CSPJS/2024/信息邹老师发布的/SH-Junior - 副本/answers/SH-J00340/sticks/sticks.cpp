#include<bits/stdc++.h>
using namespace std;
int num;
void stick(int n){
	if(n<=1) cout<<-1;
	else if(n==2) cout<<1;
	else if(n==3) cout<<7;
	else if(n==4) cout<<11;  
	else if(n==5) cout<<5;
	else if(n==6) cout<<6;
	else if(n==10) cout<<22;
	else if(n==11) cout<<48;
	else if(n%7==0){
		for(int i=1;i<=(n/7);i++) cout<<8;
	}
	else if(n%7==1){
		cout<<10;
		for(int i=2;i<=(n/7);i++) cout<<8;
	}
	else if(n%7==2){
		cout<<1;
		for(int i=1;i<=(n/7);i++) cout<<8;
	}
	else if(n%7==3){
		cout<<200;
		for(int i=3;i<=(n/7);i++) cout<<8;
	}
	else if(n%7==4){
		cout<<20;
		for(int i=2;i<=(n/7);i++) cout<<8;
	}
	else if(n%7==5){
		cout<<2;
		for(int i=1;i<=(n/7);i++) cout<<8;
	}
	else{
		cout<<6;
		for(int i=1;i<=(n/7);i++) cout<<8;
	}
	cout<<'\n';
}
//num   stick_num
//1     2  v
//2     5  v
//3     5
//4     4  v
//5     5
//6     6  v
//7     3  v
//8     7  v
//9     6
//0     6  v 
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>num;
	for(int i=1;i<=num;i++){
		int a;
		cin>>a;
		stick(a);
	}
	return 0;
}
