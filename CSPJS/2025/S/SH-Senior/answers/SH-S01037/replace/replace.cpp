#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
struct
{
	string p,q;
}a[100005],b[1000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].p>>a[i].q;
	}
	for(int j=1;j<=m;j++)
	{
		cin>>b[j].p>>b[j].q;
		long long ji=-1,lu=-1,le;
		for(int i=0;i<b[j].p.size()-1;i++)
		{
			if(b[j].p[i]!=b[j].q[i])
			{
				if(ji==-1)
				{
					ji=i;
					lu=i;
				}
				else
				{
					lu=i;
				}
			}
		}
		le=lu-ji+1;
		for(int i=1;i<=n;i++)
		{
			if(a[i].p.size()-1<le)
			{
			}
			else
			{
				for(int k=0;k<b[j].p.size()-1-(a[i].p.size()-1);k++)
				{
					bool t=0;
						for(int o=0;o<a[i].p.size()-1;o++)
						{
							if(a[i].p[o]!=b[j].p[k+o]||a[i].q[o]!=b[j].q[k+o])
							{
								t=1;
								break;
							}
						}
						if(t==0)
						{
							sum++;
							break;
						}
					}
				}
			}
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
