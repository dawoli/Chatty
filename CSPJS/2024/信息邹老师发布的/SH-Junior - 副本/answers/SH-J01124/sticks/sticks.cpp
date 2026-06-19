#include<bits/stdc++.h>
using namespace std;
long long T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		if(n%7==0){
			n/=7;
			for(int i=0;i<n;i++) cout<<8;
			}
		}
		else while(n>0)
		     else if(n>=7){cout<<8;n-=7;}
		     else if(n>=5){cout<<2;n-=5;}
		     else if(n>=4){cout<<4;n-=4;}
		     else if(n>=3){cout<<7;n-=3;}
		     else if(n>=2){cout<<1;n-=2;}
		     else if(n>=6) {cout<<0;n-=6;}
		     else{cout<<-1;return 0;}
	}
	
	
	
	return 0;
} 
