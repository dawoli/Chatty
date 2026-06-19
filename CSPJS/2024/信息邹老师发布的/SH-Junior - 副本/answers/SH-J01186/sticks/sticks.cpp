#include<bits/stdc++.h>
using namespace std;
int T,l,m,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0){
			for(int j=1;j<=n/7;j++) cout<<8;
			cout<<endl;
			continue;
		} 
		l=(n+6)/7;
		m=7-n%7;
		if(m==6){
			l-=2;
			cout<<10;
		}
		else if(m==5){
			l-=1;
			cout<<1;
		}
		else if(m==4){
			if(l==1){
				l-=1;
				cout<<7;
			}
			else if(l==2){
				l-=2;
				cout<<22;
			}
			else{
				l-=3;
				cout<<200;
			}
		}
		else if(m==3){
			if(l==1){
				l-=1;
				cout<<4;
			}
			else{
				l-=2;
				cout<<20;
			}
		}
		else if(m==2){
			l-=1;
			cout<<2;
		}
		else{
			l-=1;
			cout<<6;
		}
		for(int j=1;j<=l;j++) cout<<8;
		cout<<endl;
	}
	return 0;
}
