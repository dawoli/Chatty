#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n[55];
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n[i];
	}
	for(int i=0;i<t;i++){
		if(n[i]%7==0){
			for(int j=0;j<n[i]/7;j++){
				cout<<8;
			}
		}
		else if(n[i]%7==1){
			cout<<10;
			for(int j=0;j<(n[i]-8)/7;j++){
				cout<<8;
			}
		}
		else if(n[i]%7==2){
			cout<<1;
			for(int j=0;j<(n[i]-2)/7;j++){
				cout<<8;
			}
		}
		else if(n[i]%7==3){
			cout<<22;
			for(int j=0;j<(n[i]-10)/7;j++){
				cout<<8;
			}
		}
		else if(n[i]%7==4){
			cout<<20;
			for(int j=0;j<(n[i]-11)/7;j++){
				cout<<8;
			}
		}
		else if(n[i]%7==5){
			cout<<2;
			for(int j=0;j<(n[i]-5)/7;j++){
				cout<<8;
			}
		}
		else if(n[i]%7==6){
			cout<<6;
			for(int j=0;j<(n[i]-6)/7;j++){
				cout<<8;
			}
		}
		else if(n[i]<7){
			if(n[i]==1) cout<<-1;
			else if(n[i]==2) cout<<1;
			else if(n[i]==3) cout<<7;
			else if(n[i]==4) cout<<4;
			else if(n[i]==5) cout<<2;
			else if(n[i]==6) cout<<6;
		}
		if(i!=t-1){
			cout<<endl;
		}
	}
	return 0;
}
