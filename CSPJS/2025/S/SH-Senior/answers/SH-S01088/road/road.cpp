#include<bits/stdc++.h>
using namespace std;
int n,m,k,l[10100],x,y,z,c[15],flag,d[10100],n0;
long long ans=100000000000000001,sum;
vector<int> a[10100];
vector<int> b[10100];
bool p[100],use1[10100];
long long tr()
{
	long long ans0=sum,mino,minn;
	memset(d,1000000001,sizeof(d));
	memset(use1,0,sizeof(use1));
	if(k)
	{
		for(int i=1;i<=k;i++)
			use1[n+i]=p[i];
	}
	for(int i=1;i<=n0;i++)
	{
		if(i==1)
		{
			mino=1;
			minn=0;
		}
		else
		{
			minn=1000000001;
			for(int j=1;j<=n+k;j++)
			{
				if(!use1[j])
				{
					if(d[j]<minn)
					{
						minn=d[j];
						mino=j;
					}
				}
			}
		}
		ans0+=minn;
		use1[mino]=1;
		for(int j=0;j<l[mino];j++)
		{
			if(!use1[a[mino][j]])
				if(d[a[mino][j]]>b[mino][j])
					d[a[mino][j]]=b[mino][j];
		}
		if(ans0>=ans)
			return ans0;
	}
	return ans0;
}
void kk(int step)
{
	if(step==k)
	{
		ans=min(ans,tr());
		return;
	}
	kk(step+1);
	p[step+1]=1;
	sum-=c[step+1];
	n0--;
	kk(step+1);
	n0++;
	sum+=c[step+1];
	p[step+1]=0;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		a[x].push_back(y);
		b[x].push_back(z);
		a[y].push_back(x);
		b[y].push_back(z);
		l[x]++;
		l[y]++;
	}
	if(k)
	{
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			sum+=c[i];
			if(!flag)
			{
				flag=c[i];
			}
			for(int j=1;j<=n;j++)
			{
				cin>>x;
				a[j].push_back(n+i);
				b[j].push_back(x);
				a[n+i].push_back(j);
				b[n+i].push_back(x);
				l[j]++;
				l[n+i]++;
			}
		}
	}
	n0=n+k;
	if(k>=6||(n>1000&&k>=1))
		ans=tr();
	else if(k==0)
		ans=tr();
	else
		kk(0);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
