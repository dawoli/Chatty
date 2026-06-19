#include<bits/stdc++.h>
using namespace std;
int seat[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,key;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>seat[i];
		if(i==1)
		{
			key=seat[i];
		}
	}
	sort(seat+1,seat+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		if(seat[i]==key)
		{
			key=n*m-i+1;
			break;
		}
	}
	long long h,l;
	l=(key-key%n)/n;
	h=key%n;
	if(h!=0)
	{
		l++;
	}
	if(h==0)
	{
		if(l%2==0)
		{
			cout<<l<<" "<<1;
		}
		else
		{
			cout<<l<<" "<<n;
		}
	}
	else
	{
		if(l%2==0)
		{
			cout<<l<<" "<<n-h+1;
		}
		else
		{
			cout<<l<<" "<<h;
		}
	}
	return 0;
}

