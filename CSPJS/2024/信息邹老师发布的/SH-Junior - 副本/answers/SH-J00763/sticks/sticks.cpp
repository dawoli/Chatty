#include<bits/stdc++.h>
using namespace std;
void solve0(int x){
	if(x==0){
		cout<<-1;
	}
	else{
		for(int i=0;i<x;i++){
			cout<<8;
		}
	}
}
void solve1(int x){
	if(x==0){
		cout<<-1;
	}
	else{
		cout<<10;
		for(int i=0;i<x-1;i++){
			cout<<8;
		}
	}
}
void solve2(int x){
	cout<<1;
	for(int i=0;i<x;i++){
		cout<<8;
	}
}
void solve3(int x){
	if(x==0){
		cout<<7;
	}
	else if(x==1){
		cout<<22;
	}
	else{
		cout<<200;
		for(int i=0;i<x-2;i++){
			cout<<8;
		}
	}
}
void solve4(int x){
	if(x==0){
		cout<<4;
	}
	else{
		cout<<20;
		for(int i=0;i<x-1;i++){
			cout<<8;
		}
	}
}
void solve5(int x){
	cout<<2;
	for(int i=0;i<x;i++){
		cout<<8;
	}
}
void solve6(int x){
	cout<<6;
	for(int i=0;i<x;i++){
		cout<<8;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n;
		cin>>n;
		if(n%7==1){
			solve1(n/7);
		}
		else if(n%7==2){
			solve2(n/7);
		}
		else if(n%7==3){
			solve3(n/7);
		}
		else if(n%7==4){
			solve4(n/7);
		}
		else if(n%7==5){
			solve5(n/7);
		}
		else if(n%7==6){
			solve6(n/7);
		}
		else{
			solve0(n/7);
		}
		cout<<endl;
	}
	return 0;
}
