#include<bits/stdc++.h>
using namespace std;

int n,T,p;
int f[22]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,80,88,108,188,202,208,288,808,888};

void doit(int n){
	if(n%7==0){
		for(int i=1;i<=n/7;i++){
			cout<<'8';
		}
	}
	else if(n%7==1){
		cout<<10;
		n-=8;
		for(int i=1;i<=n/7;i++){
			cout<<'8';
		}
	}
	else if(n%7==2){
		cout<<1;
		n-=9;
		for(int i=1;i<=n/7;i++){
			cout<<'8';
		}
	}
	else if(n%7==3){
		cout<<200;
		n-=17;
		for(int i=1;i<=n/7;i++){
			cout<<'8';
		}
	}
	else if(n%7==4){
		cout<<20;
		n-=11;
		for(int i=1;i<=n/7;i++){
			cout<<'8';
		}
	}
	else if(n%7==5){
		cout<<28;
		n-=12;
		for(int i=1;i<=n/7;i++){
			cout<<'8';
		}
	}
	else if(n%7==6){
		cout<<80;
		n-=13;
		for(int i=1;i<=n/7;i++){
			cout<<'8';
		}
	}
} 


int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int u=1;u<=T;u++){
		cin>>p;
		if(p>=22){
			doit(p);
		}
		else{
			cout<<f[p];
		}
		cout<<endl;
	}
	return 0;
}
