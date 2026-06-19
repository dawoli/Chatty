#include <bits/stdc++.h>
using namespace std;
//8
int s[10]={6,2,5,5,4,5,6,3,7,6};
int u[8]={-1,-1,1,7,4,2,6,8};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;cin>>n;
	while(n--){
		int m;cin>>m;
		if(m<8){
			cout<<u[m]<<endl;
			continue;
		}
		if(m%7==0){
			for(int i=1;i<=m/7;i++){
				cout<<8;
			}
			cout<<endl;
		}else if(m%7==1){
			cout<<10;
			for(int i=1;i<=(m-8)/7;i++){
				cout<<8; 
			}
			cout<<endl;
		}else if(m%7==2){
			cout<<1;
			for(int i=1;i<=(m-2)/7;i++){
				cout<<8;
			} 
			cout<<endl;
		}else if(m%7==3){
			if(m==10){
				cout<<22<<endl;
				continue;
			}
			cout<<200;
			for(int i=1;i<=(m-17)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}else if(m%7==4){
			cout<<20;
			for(int i=1;i<=(m-11)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}else if(m%7==5){
			cout<<2;
			for(int i=1;i<=(m-5)/7;i++){
				cout<<8;
			}
			cout<<endl;
		}else if(m%7==6){
			cout<<6;
			for(int i=1;i<=(m-6)/7;i++){
				cout<<8;
			} 
			cout<<endl;
		}
	}
} 
