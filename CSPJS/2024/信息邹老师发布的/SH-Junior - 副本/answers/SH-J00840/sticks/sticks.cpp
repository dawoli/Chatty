#include<bits/stdc++.h>
using namespace std;
int t,n,wei,f; 
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1 ; i<=t ; i++)
	{
		f=0;
		cin>>n;
		if(n==1)
		{
			cout<<"-1";
			f=1;
		} 
		if(n==2)
		{
			cout<<1;
			f=1;
		}  
		if(n==3) 
		{
			cout<<7;
			f=1;
		} 
		if(n==4) 
		{
			cout<<4;
			f=1;
		} 
		if(n==5) 
		{
			cout<<2;
			f=1;
		} 
		if(n==6) 
		{
			cout<<6;
			f=1;
		} 
		if(n==7) 
		{
			cout<<8;
			f=1;
		} 
		if(f==0)
		{
			if(n%7==0) for(int j=1 ; j<=n/7 ; j++) cout<<8;
			if(n%7==1)
			{
				cout<<"10";
				for(int j=1 ; j<=(n-8)/7 ; j++) cout<<8;
			}
			if(n%7==2)
			{
				cout<<"1";
				for(int j=1 ; j<=(n-2)/7 ; j++) cout<<8;
			}
			if(n%7==3)
			{
				cout<<"22";
				for(int j=1 ; j<=(n-10)/7 ; j++) cout<<8;
			}
			if(n%7==4)
			{
				cout<<"20";
				for(int j=1 ; j<=(n-11)/7 ; j++) cout<<8;
			}
			if(n%7==5)
			{
				cout<<2;
				for(int j=1 ; j<=(n-5)/7 ; j++) cout<<8;
			}
			if(n%7==6)
			{
				cout<<6;
				for(int j=1 ; j<=(n-6)/7 ; j++) cout<<8;
			}
		}
	}
}

