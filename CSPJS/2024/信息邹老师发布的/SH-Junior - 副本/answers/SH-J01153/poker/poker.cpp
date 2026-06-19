#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


int n,cnt=0;
char a[200],b[200];

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	cnt=n;
	for(int i =1;i<=n*2;i++)
	{
		cin>>a[i];	
	}
	if(n==1)
	{
		cout<<51;
		return 0;
	}
	for(int i =1;i<=n*2-2;i+=2)
	{
		for(int j=i+2;j<=n*2;j+=2)
		{
			if(a[i]!=b[j]&&a[i]!=b[j+1])
				if(a[i]==a[j]&&a[i+1]==a[j+1])
				{
					b[j]=a[j];
					b[j+1]=a[j+1];
					cnt--;
				}
		}
	}
	cout<<52-cnt;
	return 0;
}
