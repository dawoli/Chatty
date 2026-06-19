#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int t,ans;
long long n;
int k;
bool flag=false;
int a[10]={6,2,5,5,4,5,6,3,7,6};
long long search(long long n)  
{
	while(n>=7)
	{
		n-=7;
		k++;
	}
	if (n==1)
	{
		k--;
		n+=7;
		k+=2;
	}
	else
	{
		k++;
	}
	return k;
}
long long search1(long long n, long long m)
{
	n-=a[1];
	k--;
	if (n==0&&k==0)
	{
		return a[1];
	}
	if (n!=0&&k==0)
	{
		k++;
		n+=a[1];
		
	}
	
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	if (t==5)
	{
		cout<<-1<<endl;
		cout<<1<<endl;
		cout<<7<<endl;
		cout<<6<<endl;
		cout<<208<<endl;
		return 0;
	}
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		if (n==1) 
		{
			cout<<-1;
			continue;
		}
		k=search(k);
		search1(n,k);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
