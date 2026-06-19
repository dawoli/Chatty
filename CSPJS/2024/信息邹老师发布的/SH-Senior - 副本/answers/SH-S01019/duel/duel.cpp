#include<bits/stdc++.h>
using namespace std;
int n,a[100100],x,u[100100],p,sum;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[x]++;
		u[x]++;
	}
	for(int i=1;i<=100000;i++)
	{
		if(p<=i)
			p=i+1; 
		while(a[i]>0)
		{
			if(u[p]<=a[i])
			{
				a[i]-=u[p];
				sum+=u[p];
				p++;
			}
			else if(u[p]>a[i])
			{
				u[p]-=a[i];
				sum+=a[i];
				a[i]=0;
			}
			if(p>=100001)
			{
				break;
			}
		}
		if(p>=100001)
			break;
	}
	cout<<n-sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
