#include <iostream>
#include <conio.h>
using namespace std;
long long T,n,a,b,c,d,e;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n==1)cout<<-1<<endl;
		else if(n<=30)for(long long i=1;i<100000000;i++)
		{
			e=i;
			while(e>0)
			{
				c=e%10;
				e/=10;
				if(c==0)d+=6;
				else if(c==1)d+=2;
				else if(c==2)d+=5;
				else if(c==3)d+=5;
				else if(c==4)d+=4;
				else if(c==5)d+=5;
				else if(c==6)d+=6;
				else if(c==7)d+=3;
				else if(c==8)d+=7;
				else if(c==9)d+=6;
			}
			
			if(d==n)
			{
				cout<<i<<endl;
				break;
			}
			d=0;
		}
		else
		{
			a=n%7;
			b=(n-a)/7;
			if(a==0)
			{
				while(b--)cout<<8;
				cout<<endl;
			}
			else if(a==1)
			{
				cout<<10;
				b--;
				while(b--)cout<<8;
				cout<<endl;
			}
			else if(a==2)
			{
				cout<<1;
				while(b--)cout<<8;
				cout<<endl;
			}
			else if(a==3)
			{
				cout<<200;
				b-=2;
				while(b--)cout<<8;
				cout<<endl;
			}
			else if(a==4)
			{
				cout<<20;
				b--;
				while(b--)cout<<8;
				cout<<endl;
			}
			else if(a==5)
			{
				cout<<2;
				while(b--)cout<<8;
				cout<<endl;
			}
			else if(a==6)
			{
				cout<<6;
				while(b--)cout<<8;
				cout<<endl;
			}
		}
	}
	return 0;
}
