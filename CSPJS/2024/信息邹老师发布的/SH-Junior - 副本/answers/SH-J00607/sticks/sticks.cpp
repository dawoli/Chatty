#include<bits/stdc++.h>
using namespace std;
int T,n,t8;
void op(int p){
	if(p==1)
		if(t8>=1){
			t8--;
			cout<<10;
		}
		else
			cout<<-1;
	else if(p==2)
		cout<<1;
	else if(p==3)
		if(t8>=2){
			t8-=2;
			cout<<100;
		}
		else if(t8>=1){
			t8--;
			cout<<22;
		}
		else
			cout<<7;
	else if(p==4)
		if(t8>=1){
			t8--;
			cout<<20;
		}
		else
			cout<<4;
	else if(p==5)
		cout<<2;
	else
		cout<<6;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		t8=n/7;
		n%=7;
		op(n);
		for(int i=1;i<=t8;i++)
			cout<<8;
		cout<<endl;
	}
	return 0;
}
