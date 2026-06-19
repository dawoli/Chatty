#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50],a1[100100],c[100100],b[100100],K,k[100100],ans[100100],ans1,x[10],t;
bool g[20][1000100],win[20][1000100],win1[20][1000100];
string p;
long long xr(long long m,long long n)
{
	long long ans=0;
	int c=0;
	if(m<n)
	swap(m,n);
	while(n>0)
	{
		if(m%2!=n%2)
			ans+=1*a[c];
		m/=2;
		n/=2;
		c++;
	}
	return ans+m*a[c];
}
int fi(int p)
{
	for(int i=0;;i++)
		if(a[i]>=p)
			return i;
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	for(int i=1;i<=1000000;i++)
		win1[0][i]=1;
	a[0]=1;
	for(int i=1;i<=40;i++)
		a[i]=2*a[i-1];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a1[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&c[i]);
		k[i]=fi(c[i]);
	}
	K=fi(n);
	for(int i=1;i<=K;i++)
	{
		cin>>p;
		for(int j=1;j<=a[K-j];j++)
			g[i][j]=p[j-1]-'0';
	}
	cin>>t;
	for(int t1=1;t1<=t;t1++)
	{
		scanf("%d%d%d%d",&x[0],&x[1],&x[2],&x[3]);
		for(int i=1;i<=n;i++)
			b[i]=xr(a1[i],x[i%4]);
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=m;i++)
		{
			memcpy(win,win1,sizeof(win));
			if(k[i]==0)
				ans[i]=1;
			else
			{
				for(int j=1;j<=k[i];j++)
				{
					for(int q=1;q<=a[k[i]-j];q++)
					{
						if(g[j][q])
						{
							bool flag=0;
							for(int w=a[j]*q;w>a[j-1]*(2*q-1);w--)
								if(win[j-1][w])
								{
									if(w>c[i])
									{
										flag=1;
										win[j][w]=1;
									}
									else if(b[w]>=j)
										win[j][w]=1;
									else
										flag=1;
								}
							if(flag)
								for(int w=a[j]*(q-1)+1;w<=a[j-1]*(2*q-1);w++)
									if(win[j-1][w])
										win[j][w]=1;
						}
						else
						{
							bool flag=0;
							for(int w=a[j]*(q-1)+1;w<=a[j-1]*(2*q-1);w++)
								if(win[j-1][w])
								{
									if(w>c[i])
									{
										flag=1;
										win[j][w]=1;
									}
									else if(b[w]>=j)
										win[j][w]=1;
									else
										flag=1;
								}
							if(flag)
								for(int w=a[j]*q;w>a[j-1]*(2*q-1);w--)
									if(win[j-1][w])
										win[j][w]=1;
						}
					}
				}
				for(int j=1;j<=a[k[i]];j++)
					if(win[k[i]][j])
						ans[i]+=j;
				}
		}
		ans1=ans[1];
		for(int i=2;i<=m;i++)
			ans1=xr(ans1,i*ans[i]);
		cout<<ans1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
