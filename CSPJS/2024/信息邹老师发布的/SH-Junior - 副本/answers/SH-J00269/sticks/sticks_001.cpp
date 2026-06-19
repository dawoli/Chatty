#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,j,t,n,zz;
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(zz=1;zz<=t;zz++)
	{
		cin>>n;
		if(n%7==0)
		{
			for(i=1;i<=n/7;i++) cout<<8;
			cout<<endl;
		}
		if(n%7==1&&n>=8)
		{
			cout<<1<<0;
			for(i=1;i<n/7;i++) cout<<8;
			cout<<endl;
		}
		if(n%7==2)
		{
			cout<<1;
			for(i=1;i<=n/7;i++) cout<<8;
			cout<<endl;
		}
		if(n%7==3&&n>=17)
		{
			cout<<2<<0<<0;
			for(i=1;i<=(n-14)/7;i++) cout<<8;
			cout<<endl;
		}
		if(n%7==4&&n>=11)
		{
			cout<<2<<0;
			for(i=1;i<n/7;i++) cout<<8;
			cout<<endl;
		}
		if(n%7==5)
		{
			cout<<2;
			for(i=1;i<=n/7;i++) cout<<8;
			cout<<endl;
		}
		if(n%7==6)
		{
			cout<<6;
			for(i=1;i<=n/7;i++) cout<<8;
			cout<<endl;
		}
		if(n==1) cout<<-1<<endl;
		if(n==3) cout<<7<<endl;
		if(n==4) cout<<4<<endl;
		if(n==10) cout<<22<<endl;
	}
	return 0;
}
