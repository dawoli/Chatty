#include<bits/stdc++.h>
using namespace std;
long long p(long long a)
{
	long long s=1;
	for(int i=0;i<a;i++)
	{
		s*=10;
	}
	return s;
 } 
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	long long a[10]={6,2,5,5,4,5,6,3,7,6},n,k,x,s,t,a1,b1;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		t=0;
		a1=p(k/7);b1=p(k/2);
		
		for(int j=a1;j<b1;j++)
		{
			x=j;
			s=0;
			while(x>0)
			{
				s+=a[x%10];
				x/=10;
			}
			
			if(s==k)
			{
				printf("%d\n",j);
				t=1;
				break;
			}
		}
		if(!t)
		{
			printf("-1\n");
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
