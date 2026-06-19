#include<bits/stdc++.h>
using namespace std;
long long n[1000002];
long long m[1000002]; 
long long x[1000002];
long long y[1000002];
string za[100000002];
bool pd[1000002];
long long bu[100002];
long long fx[100002];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,cnt=0,f=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>m[i]>>bu[i];
		cin>>x[i]>>y[i]>>fx[i];
		for(int h=0;h<n[i];h++)
			{
				for(int s=0;s<m[i];s++)
				{
					cin>>za[f];
					if(za[f]==".")
					{
						pd[h]==1;
					}
					else
					{
						pd[h]==0;
					}
					f++;
				}
			}
		for(int j=0;j<bu[i];j++)
		{
			
			
			if(fx[i]==0)
			{
				if((x[i]+1)<n[i])
				{
					if(pd[x[i]+1]==1)
					{
						x[i]++;
						cnt++;
					}
					else
					{
						fx[i]++;
						break;
					}
				}
				else
				{
					fx[i]++;
					break;
				}
			}
			else
				{
					fx[i]++;
					break;
				}
			if(fx[i]==1)
			{
				if((y[i]-1)<m[i])
				{
					if(pd[y[i]-1]==1)
					{
						y[i]--;
						cnt++;
					}
					else
					{
						fx[i]++;
						break;
					}
				}
				else
				{
					fx[i]++;
					break;
				}
			}
			else
				{
					fx[i]++;
					break;
				}
			if(fx[i]==2)
			{
				if((x[i]-1)<n[i])
				{
					if(pd[x[i]-1]==1)
					{
						x[i]--;
						cnt++;
					}
					else
					{
						fx[i]++;
						break;
					}
				}
				else
				{
					fx[i]++;
					break;
				}
			}
			else
				{
					fx[i]++;
					break;
				}
			if(fx[i]==3)
			{
				if((y[i]+1)<m[i])
				{
					if(pd[y[i]+1]==1)
					{
						y[i]++;
						cnt++;
					}
					else
					{
						fx[i]++;
						break;
					}
				}
				else
				{
					fx[i]++;
					break;
				}
			}
			else
				{
					fx[i]++;
					break;
				}
				
			
		}
		cout<<cnt<<endl;
	}	
	return 0;
 } 
