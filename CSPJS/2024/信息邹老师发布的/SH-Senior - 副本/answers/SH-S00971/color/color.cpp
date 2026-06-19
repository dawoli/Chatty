#include<bits/stdc++.h>
using namespace std;
int t,n,a[200001],b[16],ans,ans1;
int do2();
int dfs(int i);
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
		do2();
	return 0;	
} 

int do2()
{
	memset(a,0,200001);
	cin>>n;
	ans=0;
	ans1=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=15)
	{
		memset(b,0,16);
		dfs(1);;
		cout<<ans1<<endl;
		return 0;
	} 
	return 0;
}

int dfs(int i)
{
	if(i>n)
	{
		for(int p=1;p<=n;p++)
		{
			int s=false;
			for(int q=p-1;q>=1;q--)
				if(s==false && b[p]==b[q])
				{
					if(a[p]==a[q]) ans+=a[p];
					s=true;
				}
		}
		if(ans>ans1) ans1=ans;
		ans=0;
		return 0;
	}	
	for(int j=1;j<=2;j++)
	{
		b[i]++;
		dfs(i+1);
	}
	b[i]=0;
	return 0;
}
