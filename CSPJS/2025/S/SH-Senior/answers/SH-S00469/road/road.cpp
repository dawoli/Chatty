#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int u,v;
	long long w;
	bool operator < (const struct node & t) const
	{
		return w<t.w;
	}
}NODE;

int n,m,k,dfs_ceil,arr_l,wei_l;
long long sum_mst,ans,a[15][20025],ccc[25],wei[2000006];
int ance[20025],dfs_m[25];
NODE arr[2000025];

int find_ance(int x)
{
	return ance[x]==x?x:ance[x]=find_ance(ance[x]);
}
void union_set(int x,int y)
{
	x=find_ance(x);
	y=find_ance(y);
	if(x!=y)
		ance[y]=x;	
} 
void my_MST(int nn)
{
	int i,j=1;
	for(int i=1;i<=n+20;++i)
		ance[i]=i;
	sum_mst=0;
	for(i=1;i<nn;++i,++j)
	{
		while(j<=arr_l&&(arr[j].u>n&&dfs_m[arr[j].u-n]==0||arr[j].v>n&&dfs_m[arr[j].v-n]==0||find_ance(arr[j].u)==find_ance(arr[j].v)))
			j++;
		if(j<=arr_l)
		{
			union_set(arr[j].u,arr[j].v);
			sum_mst+=arr[j].w; 
		}
	}
}

void dfs(int layer,int pre)
{
	if(layer>dfs_ceil)
	{
		long long ret=0;
		int i;
		for(i=1;i<=k;++i)
			ret+=a[i][0]*dfs_m[i];

		my_MST(n+dfs_ceil);
		ans=min(ans,sum_mst+ret);
		return;
	}
	for(int i=pre+1;i<=k;++i)
	{
		dfs_m[i]=1;
		dfs(layer+1,i);
		dfs_m[i]=0;
	}
}
void read(int & tmp)
{
	char ch;
	tmp=0;
	while(1)
	{
		ch=getchar();
		if(ch==' '||ch=='\n')
			break;
		tmp=tmp*10+ch-'0';
	}
}
void llread(long long & tmp)
{
	char ch;
	tmp=0;
	while(1)
	{
		ch=getchar();
		if(ch==' '||ch=='\n')
			break;
		tmp=tmp*10+ch-'0';
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	int i,j,u,v;
	long long w;
	for(i=1;i<=m;++i)
	{
		read(u);
		read(v);
		llread(w);
		wei[++wei_l]=w;
		arr[i]=(NODE){u,v,w};
	}
	arr_l=m;
	for(i=1;i<=k;++i)
	{
		llread(a[i][0]);
		ccc[i]=a[i][0];
		for(int j=1;j<=n;++j)
		{
			llread(a[i][j]);
			wei[++wei_l]=a[i][j];
			arr[++arr_l]=(NODE){n+i,j,a[i][j]};
		}
	} 
	sort(ccc+1,ccc+k+1);
	sort(wei+1,wei+wei_l+1);
	sort(arr+1,arr+arr_l+1);
	my_MST(n);
	ans=sum_mst;
	long long sum_c=0;
	for(i=1;i<=k;++i)
	{
		sum_c=0;
		for(j=1;j<=i;++j)
			sum_c+=ccc[j];
		for(j=1;j<n+i;++j)
			sum_c+=wei[j];
		if(sum_c>=ans)
			continue;
		dfs_ceil=i;
		dfs(1,0);
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
