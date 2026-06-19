#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int v,xx,id;
	bool operator < (const struct node & t) const
	{
		return xx<t.xx;
	}
}NODE;
int TTT,n;
int a[200005],b[200005],c[200005],arr_a_l,arr_b_l,arr_c_l,ans;
NODE arr_a[200005],arr_b[200005],arr_c[200005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&TTT);
	while(TTT--)
	{
		scanf("%d",&n);
		arr_a_l=arr_b_l=arr_c_l=ans=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
			
			ans+=max(a[i],max(b[i],c[i]));
			
			if(a[i]>=b[i]&&a[i]>=c[i])
				arr_a[++arr_a_l]=(NODE){a[i],a[i]-max(b[i],c[i]),i};
			else if(b[i]>=a[i]&&b[i]>=c[i])
				arr_b[++arr_b_l]=(NODE){b[i],b[i]-max(a[i],c[i]),i};
			else
				arr_c[++arr_c_l]=(NODE){c[i],c[i]-max(a[i],b[i]),i};
		}
		if(arr_a_l>n/2)
		{
			sort(arr_a+1,arr_a+arr_a_l+1);
			for(int i=1;i<=arr_a_l-n/2;++i)
				ans-=(arr_a[i].xx);
		}
		else if(arr_b_l>n/2)
		{
			sort(arr_b+1,arr_b+arr_b_l+1);
			for(int i=1;i<=arr_b_l-n/2;++i)
				ans-=(arr_b[i].xx);
		}
		else if(arr_c_l>n/2)
		{
			sort(arr_c+1,arr_c+arr_c_l+1);
			for(int i=1;i<=arr_c_l-n/2;++i)
				ans-=(arr_c[i].xx);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
