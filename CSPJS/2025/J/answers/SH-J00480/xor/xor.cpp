#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int x,y;
	bool operator < (const struct node & t) const
	{
		return x<t.x;
	}
}NODE;
int n,k,arr_l,a[500005],sum[500005],g[500005],p[500005];
map<int,int> mp;
NODE arr[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	int flag1=1,flag01=1,cnt2_1=0,cnt0=0;
	mp[0]=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
		if(mp.count(sum[i]^k))
			arr[++arr_l]=(NODE){mp[sum[i]^k]+1,i};
		mp[sum[i]]=i;
		if(a[i]!=1)
			flag1=0;
		if(a[i]!=1&&a[i]!=0)
			flag01=0;
		if(a[i]==1&&a[i-1]==1)
			cnt2_1++;
		if(a[i]==0)
			cnt0++;
	}
	if(flag1)//A
		printf("%d\n",n/2);
	else if(flag01)//B
	{
		if(!k)
			printf("%d\n",cnt2_1+cnt0);
		else
			printf("%d\n",n-cnt0);
	}
	else
	{
		sort(arr+1,arr+arr_l+1);
		g[arr_l+1]=INT_MAX;
		for(int i=arr_l;i>=1;--i)
		{
			g[i]=min(arr[i].y,g[i+1]);
			p[i]=(g[i+1]>arr[i].y?i:p[i+1]);
		}
		int w=0,ans=0;
		while(w<arr_l)
		{
			w=p[w+1];
			ans++;
			int www=w;
			for(int i=w+1;i<=arr_l&&arr[i].x<=arr[www].y;++i)
				w=i;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
