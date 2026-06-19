#include <bits/stdc++.h>
#define N 100007
using namespace std;
//最大的重复元素数量 
int f[N],a,n,ans=0,top=0;

//void dp()
//{
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<i;j++)
//		{
//			if(a[j]<a[i])
//			{
//				f[i]=max(f[i],f[j]+1); 
//				r[i]=j;//记录路径 
//			}
//		}
//	}
//	return ;
//}

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		top=max(top,a);
		f[a]++;;
	}
	for(int i=1;i<=top;i++)
	{
		ans=max(ans,f[i]);
	}
	printf("%d",ans);
}
