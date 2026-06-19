#include<bits/stdc++.h>
using namespace std;
int T,n;
const int num[11]={6,2,5,5,4,5,6,3,7,6};
int ans[15]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n==2){
			cout<<1<<endl;
			continue;
		} 
		if(n==3){
			cout<<7<<endl;
			continue;
		} 
		if(n==4){
			cout<<4<<endl;
			continue;
		}
		if(n==5){
			cout<<2<<endl;
			continue;
		} 
		if(n==6){
			cout<<6<<endl;
			continue;
		} 
		if(n==7){
			cout<<8<<endl;
			continue;
		} 
		string s;
		while(n>13){
			s+='8';
			n-=7;
		}
		cout<<ans[n]<<s<<endl;
	}
	return 0;
}
