#include<bits/stdc++.h>
using namespace std;
long long n;
long long r[100005],minn1=100005,duble[100005],cz=0,minn2,ans=0,js;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
		duble[i]=r[i];
		if(r[i]<=minn1)
		{
			minn1=r[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(r[i]==minn1)
		{
			duble[i]=100005;
		}
	}
	minn2=100005;
	for(int i=1;i<=n;i++)
	{
		if(duble[i]<=minn2)
		{
			minn2=duble[i];
		}
	}
	if(minn2==100005)
	{
		cout<<n<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(duble[i]==minn2)
		{
			js++;
		}
	}
	ans=ans-js;
	while(1)
	{
		js=0;
		minn1=100005;
		minn2=100005;
		for(int i=1;i<=n;i++)
		{
			if(duble[i]<=minn1)
			{
				minn1=duble[i];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(duble[i]==minn1)
			{
				duble[i]=100005;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(duble[i]<=minn2)
			{
				minn2=duble[i];
			}
		}
		if(minn2==100005) break;
		for(int i=1;i<=n;i++)
		{
			if(duble[i]==minn2)
			{
				js++;
			}
		}
		ans=ans-js;
	}
	cout<<ans;
	return 0;
}
