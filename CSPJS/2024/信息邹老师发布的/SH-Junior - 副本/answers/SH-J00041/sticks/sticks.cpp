#include<bits/stdc++.h>
using namespace std;
int n;	string s;
int T;
int m[15]={-1,-1,1,7,4,2,6,8};
int ans[14286];
int k,d;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(ans,0,sizeof(ans));
		m[6]=6;
		cin>>n;
		if(n<=7) 
		{
			cout<<m[n]<<endl;
			continue;
		}
		if(n%7==0)
		{
			for(int i=0;i<n/7;i++) cout<<8;
			cout<<endl;
			continue;
		}
		k=0;
		int num=n/7+1;
		for(int i=1;i<=n/7;i++) ans[i]=8;
		ans[0]=m[n%7];
		if(n%7==1)
		{
			ans[0]=1;ans[1]=6;
		}
		else 
		{
				for(int j=n%7+1;j<=7;j++)
			{
				if(ans[0]>m[j]) 
				{
					ans[0]=m[j];
					k=j-n%7;
				}
			}
		m[6]=0;
		for(int i=1;i<n/7;i++)
		{
			for(int j=7;j>=2;j--)
			{
				if(ans[i]>m[j]&&k>=7-j)
				{
					ans[i]=m[j];
					k-=7-j;
				}
			}
		}
		ans[n/7]=m[7-k];
		}
		for(int i=0;i<=n/7;i++) cout<<ans[i];
		cout<<endl;
	}
	return 0;
}
