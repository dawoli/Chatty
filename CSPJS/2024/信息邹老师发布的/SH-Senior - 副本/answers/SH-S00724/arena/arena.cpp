#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n,m,a0[100001],a[100001],c[100001],k;
int a1[100001];
vector<int>d[21];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a0[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>c[i];
	}
	int mul=1;
	for(int i=1;i<=n;i++)
	{
		if(mul>=n)
		{
			k=i-1;
			break;
		}
		mul*=2;
	}
	for(int i=1;i<=k;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<s.size();j++)
		{
			d[i].push_back(s[j]-'0');
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		int x0,x1,x2,x3;
		cin>>x0>>x1>>x2>>x3;
		for(int i=1;i<=n;i++)
		{
			if(i%4==0)a[i]=a0[i]^x0;
			if(i%4==1)a[i]=a0[i]^x1;
			if(i%4==2)a[i]=a0[i]^x2;
			if(i%4==3)a[i]=a0[i]^x3;
		}
		long long ans0=0;
		for(int i=1;i<=m;i++)
		{
			int mul1=1,k0,ans=0;
			for(int j=1;j<=c[i];j++)
			{
				if(mul1>=c[i])
				{
					k0=j-1;
					break;
				}
				mul1*=2;
			}
			for(int j=1;j<=mul1;j++)
			{
				for(int l=1;l<=c[i];l++)
				{
					a1[l]=a[l];
				}
				for(int l=c[i]+1;l<=mul1;l++)
				{
					a1[l]=0;
				}
				if(j>c[i])a1[j]=100;
				int pos=j,t0=mul1;
				for(int l=1;l<=k0;l++)
				{
					t0/=2;
					for(int l1=1;l1<=t0;l1++)
					{
						if(d[l][l1-1]==0)
						{
							if(a1[2*l1-1]>=l)
							{
								if(pos==2*l1-1)pos=l1;
								else if(pos==2*l1)pos=-1;
								a1[l1]=a1[2*l1-1];
							}
							else
							{
								if(pos==2*l1-1)pos=-1;
								else if(pos==2*l1)pos=l1;
								a1[l1]=a1[2*l1];
							}
						}
						else
						{
							if(a1[2*l1]>=l)
							{
								if(pos==2*l1)pos=l1;
								else if(pos==2*l1-1)pos=-1;
								a1[l1]=a1[2*l1];
							}
							else 
							{
								if(pos==2*l1)pos=-1;
								else if(pos==2*l1-1)pos=l1;
								a1[l1]=a1[2*l1-1];
							}
						}
					}
				}
				if(pos!=-1)ans+=j;
			}
			ans0^=1ll*i*ans;
		}
		cout<<ans0<<endl;
	}
}
