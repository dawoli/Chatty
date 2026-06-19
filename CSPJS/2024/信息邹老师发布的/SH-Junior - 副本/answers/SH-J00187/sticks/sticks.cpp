#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long cost[10]={6,2,5,5,4,5,6,3,7,6};
ll n;
ll T;
long long maxx;
void js(long long num,int st){
	if(st==0){
		maxx=min(maxx,num);
		return;
	}
	else if(st==1){
		return;
	}
//	cout<<num<<endl;
	for(int i=0;i<=9;i++){
		if(i==0&&num==0){
			continue;
		}
		if(cost[i]>st){
			continue;
		}
		js(num*10+i,st-cost[i]);
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		if(n==1){
			cout<<"-1\n";
			continue;
		}
		else if(n<=10){
			maxx=0x3f3f3f3f;
			js(0,n);
			cout<<maxx<<"\n";
		}
		else{
			int mw=(n-1)/7+1;
			int dt=n%7;
			if(dt==0){
				for(int i=1;i<=mw;i++){
					cout<<"8";
				}
				cout<<endl;
			}
			if(dt==1){
				cout<<"10";
				for(int i=1;i<=mw-2;i++){
					cout<<"8";
				}
				cout<<endl;
			}
			if(dt==2){
				cout<<"1";
				for(int i=1;i<=mw-1;i++){
					cout<<"8";
				}
				cout<<endl;
			}
			if(dt==3){
				cout<<"200";
				for(int i=1;i<=mw-3;i++){
					cout<<"8";
				}
				cout<<endl;
			}
			if(dt==4){
				cout<<"20";
				for(int i=1;i<=mw-2;i++){
					cout<<"8";
				}
				cout<<endl;
			}
			if(dt==5){
				cout<<"2";
				for(int i=1;i<=mw-1;i++){
					cout<<"8";
				}
				cout<<endl;
			}
			if(dt==6){
				cout<<"6";
				for(int i=1;i<=mw-1;i++){
					cout<<"8";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
