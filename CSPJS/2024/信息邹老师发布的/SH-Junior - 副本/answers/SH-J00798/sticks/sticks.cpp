#include<iostream>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(t-=1;t>=0;t--)
	{
		int n;
		cin>>n;
		if(n<2) cout<<-1;
		else if(n==2) cout<<1;
		else if(n==3) cout<<7;
		else if(n==4) cout<<4;
		else if(n==5) cout<<2;
		else if(n==6) cout<<6;
		else if(n==7) cout<<8;
		else if(n==8) cout<<10;
		else if(n==9) cout<<18;
		else if(n==10) cout<<22;
		else if(n==11) cout<<20;
		else if(n==12) cout<<28;
		else if(n==13) cout<<68;
		else
		{
			if(n%7==0) cout<<88;
			if(n%7==1) cout<<108;
			if(n%7==2) cout<<188;
			if(n%7==3) cout<<200;
			if(n%7==4) cout<<208;
			if(n%7==5) cout<<288;
			if(n%7==6) cout<<688;
			for(int i=(n-n%7)/7-2;i>0;i--) cout<<8;
		}
		cout<<endl;
	}
	return 0;
}
