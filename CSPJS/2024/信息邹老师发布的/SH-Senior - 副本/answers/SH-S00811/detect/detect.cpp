#include<bits/stdc++.h>
//#define int long long
using namespace std;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t; 
	for(int ssss=1;ssss<=t;ssss++)
	{
		int n,m,l,v1,cnt=0;
		cin>>n>>m>>l>>v1;
		int d[n+1],v[n+1],a[n+1],f[m+1],x[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>f[i];
			x[i]=0;
		}
		sort(f+1,f+1+m);
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if(v[i]>v1)
				{
					int k=false;
					for(int j=1;j<=m;j++)
					{
						if(f[j]>=d[i])
						{
							k=true;
							x[j]++;
							break;
//							cout<<i<<endl;
						}
					}
					if(k==true)
					{
						cnt++;
					}
				}
			}
			else 
			if(a[i]>0)
			{
				int len=(v1*v1-v[i]*v[i])/(2*a[i])+d[i];
//				cout<<i<<" "<<len<<endl;
					int k=false;
				for(int j=1;j<=m;j++)
				{
					if(f[j]>len)
					{
						k=true;
//						cout<<i<<endl;
						x[j]++;
						break;
					}
				}
				if(k==true)
				{
					cnt++;
				}
			}
			else
			{
				int len=(v1*v1-v[i]*v[i])/(2*a[i])+d[i];
//				cout<<i<<" "<<len<<endl;
				int k=false;
				for(int j=1;j<=m;j++)
				{
					if(f[j]>=d[i]&&f[j]<len)
					{
						k=true;
//						cout<<i<<endl;
						x[j]++;
						break;
					}
				}
				if(k==true)
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<" ";
		int sum=0;
		for(int i=1;i<=m;i++)
		{
			if(x[i]==0)
			{
				sum++;
			}
		}
		cout<<sum;
		cout<<endl;
	}
	return 0;
}
