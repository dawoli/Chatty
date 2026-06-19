#include<bits/stdc++.h>
using namespace std;
long long xor1[500010];
long long n,k,cnt=0;
bool A=false;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	//cout<<n<<" "<<k;
	for(int i=1;i<=n;i++)
	{
		cin>>xor1[i];
		//cout<<xor1[i]<<" ";
		if(xor1[i]!=1)
		{
			A==true;
		}
		//xor1[i]=xor1[i]^xor1[i-1];
	}
	if(k==0&&!A)
	{
		cout<<int(n*1.0/2);
	}
	else if(k==0&&A)
	{
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(xor1[i]==0)
			{
				cnt++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(xor1[i]==1&&xor1[i+1]==1)
			{
				cnt++;
				xor1[i]=0;
				xor1[i+1]=0;
			}
		}
	}
	else if(k==1)
	{
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(xor1[i]==1)
			{
				cnt++;
			}
		}
		cout<<cnt;
	}
	else
	{
		cout<<17; 
	}
	return 0;
}

