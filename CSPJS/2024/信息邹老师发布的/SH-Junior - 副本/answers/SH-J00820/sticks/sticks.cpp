#include<bits/stdc++.h>
using namespace std;
int t,n;
const int yuzhicai[59]={0,-1,1,7,4,2,6,8,10,18,22,20,28,80,88,108,188,200,208,288,808,888,1088,1888,2288,2088,2888,8088,8888,10888,18888,22888,20888,28888,80888,88888,108888,188888,228888,208888,288888,808888,888888,1088888,1888888,2288888,2088888,2888888,8088888,8888888,10888888};
bool isA(){
	if(n%7==0) return 1;
	return 0;
}
bool isB(){
	if(n%7==1) return 1;
	return 0;
}
void solveDB(){
	cout<<yuzhicai[n]<<endl;
}
void solveA(){
	for(int i=1;i<=n/7;i++) cout<<8;
	cout<<endl;
}
void solveB(){
	cout<<10;
	n-=8;
	for(int i=1;i<=n/7;i++) cout<<8;
	cout<<endl;
}
void solve(){
	if(n%7==2){
		cout<<1;
		n-=2;
		for(int i=1;i<=n/7;i++) cout<<8;
		cout<<endl;
	}else if(n%7==3){
		cout<<22;
		n-=10;
		for(int i=1;i<=n/7;i++) cout<<8;
		cout<<endl;
	}else if(n%7==4){
		cout<<20;
		n-=11;
		for(int i=1;i<=n/7;i++) cout<<8;
		cout<<endl;
	}else if(n%7==5){
		cout<<2;
		n-=5;
		for(int i=1;i<=n/7;i++) cout<<8;
		cout<<endl;
	}else if(n%7==6){
		cout<<80;
		n-=13;
		for(int i=1;i<=n/7;i++) cout<<8;
		cout<<endl;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
  	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=50) solveDB();
		else if(isA()) solveA();
		else if(isB()) solveB();
		else solve();
	}
	return 0;
}
