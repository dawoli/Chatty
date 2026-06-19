#include<iostream>
using namespace std;
int n, a[1001];
void pan(int k)
{
	if(k!=0)
	{
		if(k>7)
		{
		int as=k%7;
		if(as>=1&&as<=6)
		{
			k-=6;
			cout<<"0";
		}
		else
		{
			k-=7;
			cout<<"8";
		}
		return pan(k);
		}
		else
		{
			if(k==2)cout<<"1";
			if(k==3)cout<<"7";
			if(k==4)cout<<"4";
			if(k==5)cout<<"2";
			if(k==6)cout<<"0";
			if(k==7)cout<<"8";
		}
	}
	return;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			cout<<"-1"<<endl;
		}
		else if(a[i]==6)
		{
			cout<<"6"<<endl;
		}
		else 
		{
			int as=a[i]%7;
			if(a[i]>7)
			{
			if(as>=1&&as<=2)
			{
				a[i]-=2;
				cout<<"1";
			}
			if(as>=3&&as<=5)
			{
				a[i]-=5;
				cout<<"2";
			}
			if(as==6)
			{
				a[i]-=6;
				cout<<"6";
			}
			if(as==7)
			{
				a[i]-=7;
				cout<<"8";
			}
		}
			pan(a[i]);
			cout<<endl;
		}
	}
	return 0;
}
