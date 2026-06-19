#include<bits/stdc++.h>
using namespace std;
pair<int,pair<int,int> > edges[1000011];
pair<int,pair<int,int> > hx[10111];
int father[10111];
pair<int,pair<int,int> > a[21][10111];
long long c[10111];
int sz[10111];
char s[10011];
int findset(int k)
{
	if(father[k]==k)return k;
	father[k]=findset(father[k]);
	return father[k];
}
int fread()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int ans=0;
	for(int i=1;i<=n;i++)ans=ans*10+s[i]-'0';
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	n=fread(),m=fread(),k=fread();
	for(int i=1;i<=n;i++)father[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++)
	{
		edges[i].second.first=fread(),edges[i].second.second=fread(),edges[i].first=fread();
	}
	sort(edges+1,edges+m+1);
	int top=n;
	int fx=0;
	long long sum=0;
	for(int i=1;i<=m;i++)
	{
		if(top==1)break;
		int temp1=findset(edges[i].second.first),temp2=findset(edges[i].second.second);
		if(temp1==temp2)continue;
		if(sz[temp1]>sz[temp2])swap(temp1,temp2);
		father[temp1]=temp2;
		sz[temp2]+=sz[temp1];
		top--;
		hx[++fx]=edges[i];
		sum+=edges[i].first;
	}
	long long ans=sum;
	m=fx;
	for(int i=1;i<=k;i++)
	{
		c[i]=fread();
		for(int j=1;j<=n;j++)a[i][j].first=fread(),a[i][j].second.first=n+i,a[i][j].second.second=j;
	}
	for(int i=1;i<=((1<<k)-1);i++)
	{
		m=fx;
		long long sum=0;
		for(int j=1;j<=k;j++)
		{
			if(i&(1<<(j-1)))
			{
				for(int f=1;f<=n;f++)edges[++m]=a[j][f];
				sum+=c[j];
			}
		}
		for(int j=1;j<=fx;j++)edges[j]=hx[j];
		for(int i=1;i<=n+k;i++)father[i]=i,sz[i]=1;
		sort(edges+1,edges+m+1);
		int top=n+k;
		for(int i=1;i<=m;i++)
		{
			if(top==1)break;
			int temp1=findset(edges[i].second.first),temp2=findset(edges[i].second.second);
			if(temp1==temp2)continue;
			if(sz[temp1]>sz[temp2])swap(temp1,temp2);
			father[temp1]=temp2;
			sz[temp2]+=sz[temp1];
			top--;
			sum+=edges[i].first;
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
