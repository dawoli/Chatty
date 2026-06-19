#include<bits/stdc++.h>
using namespace std;
int r[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,b=0,c;
	long long k,a;
	bool d=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>r[i];
	} 
	for(;b<n;)
	{
		for(int i=b;i<n;i++)
		{
			for(int j=b;j<=i;j++)
			{
				a^=r[j];
			}
			if(a==k)
			{
				b=i+1;
				c++;
				d=1;
				break;
			}
			a=0;
		}
		a=0;
		d=0;
	}
	cout<<c-1;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
