#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int k;
	cin>>k;
	for(int i=1;i<=k;i++){
	int n;
	cin>>n;
	if(n%7==0){
	for(int i=1;i<=n/7;i++)
	cout<<8;
	cout<<endl;}
	if(n==1)
	cout<<-1<<endl;
	if(n==2)
	cout<<1<<endl;
	if(n==3)
	cout<<7<<endl;
	if(n==4)
	cout<<4<<endl;
	if(n==5)
	cout<<5<<endl;
	if(n==6)
	cout<<6<<endl;
	if(n>7&&(n%7)!=0){
		int cnt,res;
		cnt=max(0,n-14)/6;
		res=n-cnt*6;
		if(res>14){
			res-=6;
			cnt++;
		}
		if(res==1){
			cnt--;
			res+=12;
			cout<<8;
			for(int i=1;i<=cnt;i++)
			cout<<0;
			cout<<0<<endl;
		}
		if(res==2){
			cout<<1;
			for(int i=1;i<=cnt;i++)
			cout<<0;
			cout<<endl;
		}
		if(res==3){
			cout<<7;
			for(int i=1;i<=cnt;i++)
			cout<<0;
			cout<<endl;
		}
		if(res==4){
			cout<<4;
			for(int i=1;i<=cnt;i++)
			cout<<0;
			cout<<endl;
		}
		if(res==5){
			cout<<5;
			for(int i=1;i<=cnt;i++)
			cout<<0;
			cout<<endl;
		}
		if(res==6){
			cout<<6;
			for(int i=1;i<=cnt;i++)
			cout<<0;
			cout<<endl;
		}
		if(res==7){
			cout<<8;
			for(int i=1;i<=cnt;i++)
			cout<<0;
			cout<<endl;
		}
		if(res==8){
			cout<<1;
			for(int i=1;i<=cnt;i++)
			cout<<0;
			cout<<0<<endl;
		}
		if(res==9){
			cout<<1;
			for(int i=1;i<=cnt;i++)
			cout<<0;
			cout<<8;
			cout<<endl;
		}
		if(res==10){
			cout<<2;
			for(int i=1;i<=cnt;i++)
			cout<<0;
			cout<<2;
			cout<<endl;
		}
		if(res==11){
			cout<<2;
			for(int i=1;i<=cnt;i++)
			cout<<0;
			cout<<0;
			cout<<endl;
		}
		if(res==12){
			cout<<2;
			for(int i=1;i<=cnt;i++)
			cout<<0;
			cout<<8;
			cout<<endl;
		}
		if(res==13){
			cout<<8;
			for(int i=1;i<=cnt;i++)
			cout<<0;
			cout<<0;
			cout<<endl;
		}
		if(res==14){
			cout<<8;
			for(int i=1;i<=cnt;i++)
			cout<<0;
			cout<<8;
			cout<<endl;
		}
	}}
	return 0;
}
