#include<iostream>
using namespace std;
int a[1002][1002];
int len=1;
 void fun(int temp)
{
	for(int i=0;i<=len-1;i++)
	{
		a[temp][i]+=a[temp-1][i]+a[temp-2][i];
		if(a[temp][i]>=10)
		{
			a[temp][i+1]+=a[temp][i]/10;
			a[temp][i]%=10;
		}
	}
	if(a[temp][len])len++;
 
}
int main()
{
	freopen("bee.in","r",stdin);
	freopen("bee.out","w",stdout);
	int n;
	cin>>n;
	a[1][0]=1;
	a[2][0]=2;
	for(int i=3;i<=n;i++)
	{
		fun(i);
	}
	for(int i=len-1;i>=0;i--)
	{
		cout<<a[n][i];
	}
	return 0;
}
