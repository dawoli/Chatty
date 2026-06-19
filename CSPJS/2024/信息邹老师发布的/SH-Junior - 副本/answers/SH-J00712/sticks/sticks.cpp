#include<bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int T,n,ans=1e9;
void solve0(){
	for(int i=1;i<=n/7;i++) cout<<"8";
	cout<<endl;
}
void solve1(){
	cout<<"10";
	for(int i=1;i<=(n-8)/7;i++) cout<<"8";
	cout<<endl;
}
void solve2(){
	cout<<"1";
	for(int i=1;i<=(n-2)/7;i++) cout<<"8";
	cout<<endl;
}
void solve3(){
	cout<<"22";
	for(int i=1;i<=(n-10)/7;i++) cout<<"8";
	cout<<endl;
}
void solve4(){
	cout<<"20";
	for(int i=1;i<=(n-11)/7;i++) cout<<"8";
	cout<<endl;
}
void solve5(){
	cout<<"2";
	for(int i=1;i<=(n-5)/7;i++) cout<<"8";
	cout<<endl;
}
void solve6(){
	cout<<"6";
	for(int i=1;i<=(n-6)/7;i++) cout<<"8";
	cout<<endl;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=1){
			cout<<"-1"<<endl;
			continue;
		}
		else if(n==2) cout<<"1"<<endl;
		else if(n==3) cout<<"7"<<endl;
		else if(n==4) cout<<"4"<<endl;
		else if(n==5) cout<<"2"<<endl;
		else if(n==6) cout<<"6"<<endl;
		else if(n%7==0) solve0();
		else if(n%7==1) solve1();
		else if(n%7==2) solve2();
		else if(n%7==3) solve3();
		else if(n%7==4) solve4();
		else if(n%7==5) solve5();
		else if(n%7==6) solve6();
	}
	return 0;
}

