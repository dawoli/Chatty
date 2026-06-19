#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],ans,cha[100005],k[3],violence;
int abss(int b)
{
	if(b>=0)
	{
		return b;
	}
	return -b;
}
void dfs(int d,int choice,int num[3],int res) 
{
	

	res+=a[d][choice];
	num[choice]++;
	if(d==n)
	{
		if(res>=violence)
		{
			violence = res;
		}
		return;
	}
		
	if(num[0] < n/2)
		dfs(d+1,0,num,res);
	if(num[1] < n/2)
		dfs(d+1,1,num,res);
	if(num[2] < n/2)
		dfs(d+1,2,num,res);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int p=1;p<=t;++p)
	{
		ans=0;
		//in
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		
		//2
		if(n==2)
		{
			int l[6]={a[1][0]+a[2][1],a[1][0]+a[2][2],a[1][1]+a[2][0],a[1][1]+a[2][2],a[1][2]+a[2][1],a[1][2]+a[2][0]};
			sort(l,l+6);
			cout<<l[5]<<endl;
		}
		
		//00
		if(a[1][1]==0&&a[1][2]==0)
		{
			for(int i=1;i<=n;++i)
			{
				ans+=a[i][0];
			}
			cout<<ans<<endl;
			continue;
		}
		
		
		//0
		if(a[1][2]==0)
		{
			int n0=0,n1=0;
			for(int i=1;i<=n;++i)
			{
				if(a[i][0]>=a[i][1])
				{
					ans+=a[i][0];
					n0++;
				}
				else
				{
					ans+=a[i][1];
					n1++;
				}
			}
			
			if(n0==n1)
			{
				cout<<ans<<endl;
				continue;
			}
			
			int c=abss(n1-n0);
			c/=2;
			for(int i=1;i<=n;++i)
			{
				cha[i]=abss(a[i][1]-a[i][0]);
			}
			sort(cha,cha+n);
			for(int i=1;i<=c;++i)
			{
				ans-=cha[i];
			}
			cout<<ans<<endl;
			continue;
		}
		
		//voilence
		dfs(1,0,k,0);
		dfs(1,1,k,0);
		dfs(1,2,k,0);
		cout<<violence<<endl;
		continue;
	}
	
	return 0;
}
