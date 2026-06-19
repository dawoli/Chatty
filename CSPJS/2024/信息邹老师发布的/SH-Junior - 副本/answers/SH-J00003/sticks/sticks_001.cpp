#include<bits/stdc++.h>
using namespace std;
int n;
void work(){
	cin>>n;
	if(n%7==0){
		while(n){
			cout<<8;
			n-=7;
		}
		cout<<"\n";
	}else if(n%7==1){
		if(n==1){
			cout<<"-1\n";
			return;
		}
		cout<<1;n-=8;
		while(n){
			cout<<8;
			n-=7;
		}
		cout<<"9\n";
	}else if(n%7==2){
		cout<<1;n-=2;
		while(n){
			cout<<8;
			n-=7;
		}
	}else if(n%7==3){
		if(n==3)cout<<7;
		else{
			cout<<22;n-=10;
			while(n){
				cout<<8;
				n-=7;
			}
		}
		cout<<"\n";
	}else if(n%7==4){
		if(n==4)cout<<4;
		else{
			cout<<20;n-=11;
			while(n){
				cout<<8;
				n-=7;
			}
		}
		cout<<"\n";
	}else if(n%7==5){
		cout<<2;n-=5;
		while(n){
			cout<<8;
			n-=7;
		}
		cout<<"\n";
	}else{
		cout<<6;n-=6;
		while(n){
			cout<<8;
			n-=7;
		}
		cout<<"\n";
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;cin>>t;
	while(t--)work();
	return 0;
}
