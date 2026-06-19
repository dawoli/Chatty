#include<bits/stdc++.h>
using namespace std;
int bi,t,n,a,b,c,as=0,bs=0,cs=0,ans=0;
int ar[100001]={0},br[100001]={0},cr[100001]={0};
/*struct stu
{
	int bu;
	int re;
};
stu s[100001];*/
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		as=0;
		bs=0;
		cs=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			bi=max(max(a,b),c);
			ans+=bi;
			if(bi==a)
			{
				as++;
				ar[as]=a-max(b,c);	
			}
			else
			{
				if(bi==b)
				{
					bs++;
					br[bs]=b-max(a,c);
				}
				else
				{
					cs++;
					cr[cs]=c-max(a,b);
				}
			}
		}
		if(max(as,max(bs,cs))>n/2)
		{
			if(as==max(as,max(bs,cs)))
			{
				sort(ar+1,ar+as+1);
				for(int j=1;j<=as-n/2;j++)
				{
					ans-=ar[j];
				}
		//		printf("a\n");
			}
			if(bs==max(as,max(bs,cs)))
			{
				sort(br+1,br+bs+1);
				for(int j=1;j<=bs-n/2;j++)
				{
					ans-=br[j];
				}
		//		printf("b\n");
			}
			if(cs==max(as,max(bs,cs)))
			{
				sort(cr+1,cr+cs+1);
				for(int j=1;j<=cs-n/2;j++)
				{
			//		printf("%d :%d\n",j,cr[j]);
					ans-=cr[j];
				}
			//	printf("c\n %d %d %d\n",as,bs,cs);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
147325
*/
