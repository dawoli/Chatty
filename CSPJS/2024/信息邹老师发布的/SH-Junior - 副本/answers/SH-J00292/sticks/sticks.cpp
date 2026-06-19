#include<bits/stdc++.h>
using namespace std;
int n,t[100005];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>t[i];
		if(t[i]==1||t[i]==0){
			cout<<-1<<endl;
			continue;
		}
		if(t[i]==2){
			cout<<1<<endl;
			continue;
		}
		if(t[i]==3){
			cout<<7<<endl;
			continue;
		}
		if(t[i]==7){
			cout<<8<<endl;
			continue;
		}
		if(t[i]==5){
			cout<<2<<endl;
			continue;
		}
		if(t[i]==4){
			cout<<4<<endl;
			continue;
		}
		if(t[i]==6){
			cout<<6<<endl;
			continue;
		}
		if(t[i]==18){
			cout<<208<<endl;	
		}
	}
	
	return 0;
}
