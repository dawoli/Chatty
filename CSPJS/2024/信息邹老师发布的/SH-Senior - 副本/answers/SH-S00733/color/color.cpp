#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1005],b[1005],bn;
int choice[1005],ans=0;
int check()
{
	int sum=0;
	for(int i=2;i<=bn;i++)
	{
		for(int j=i-1;j>0;j--)
		{
			if(choice[i]==choice[j]&&b[i]==b[j])
			{
				sum+=b[i];
				break;
			}
		}
	}
	return sum;
}
void f(int k)
{
	if(k==bn+1)
	{
		ans=max(ans,check());
		return ;
	}
	choice[k]=1;
	f(k+1);
	choice[k]=0;
	f(k+1);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int g=1;g<=T;g++)
	{
		int t[1005]={0};
		int n;
		ans=0;
		scanf("%d",&n);
		bn=0;

		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			t[a[i]]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(t[a[i]]>1)
			{
				b[++bn]=a[i];
			}
		}
		f(1);
		printf("%d\n",ans);
	}
	return 0;
 } 
