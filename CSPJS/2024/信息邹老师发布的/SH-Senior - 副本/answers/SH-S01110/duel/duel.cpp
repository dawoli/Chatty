#include<bits/stdc++.h>
using namespace std;
const int N=100002;
int n,a[N],sum=0,ans,ke[N],cun[N];
int cnt=1;
void dfs(int i)
{
	int f=0;
	for(int m=1;m<=n;m++)
	{
		if(cun[m]==1 and m!=i)  
		{
			f=1;
			break;
		}
	}
	if(f==0)
	{
	    ans=min(sum,ans);
	    sum++;
		return;
	}
    int p=0;
	for(int j=1;j<=n;j++)
	{
		if(j==i or cun[j]==0)  continue;
		if(a[i]>a[j])
		{
			p=1;
			sum--;
			cun[j]=0;
			ke[i]=0;
			for(int k=1;k<=n;k++)
			{
				if(cun[k]==0 or ke[k]==0)  continue;
				dfs(k);			
			}
			cun[j]=1;
			ke[i]=1;
			sum++;
	     	ans=min(sum,ans);
	    }
	} 
	return;
}
int main()
{
	freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	  } 
	for(int i=1;i<=n;i++)  
	{
		for(int j=1;j<=n;j++)
		{
			ke[j]=1;
			cun[j]=1;
		}
		sum=n;
		dfs(i);		
	}
	cout<<ans-1<<endl;
	return 0;
}
