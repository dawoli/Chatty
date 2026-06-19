#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[600000];
int b[600000];
int sum =0;
int main()
{
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		
	}
	for(int i=0;i<k-1;i++)
	{
		while(a[i]>0)
		{
			if(a[i]%2==a[i+1]%2)
			{
				b[i]=a[i]*10+0;
			}
			else
			{
				b[i]=a[i]*10+1;
			}
			if(b[i]==k)
			{
				sum++;
			}
			a[i]--;
		}		
	}
	cout<<sum;
	return 0;
}
