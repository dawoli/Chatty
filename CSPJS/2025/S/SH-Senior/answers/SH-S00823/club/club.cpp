#include<bits/stdc++.h>
using namespace std;
int t,n,am=0,bm=0,cm=0,ans=0;
struct tr{
	int a,b,c;
}a[100001];
bool cmp(tr x,tr y)
{
	double avx=(x.a+x.b+x.c)/3,avy=(y.a+y.b+y.c/3),fca=(x.a-avx)*(x.a-avx)+(x.b-avx)*(x.b-avx)+(x.c-avx)*(x.c-avx),fcb=(y.a-avy)*(y.a-avy)+(y.b-avy)*(y.b-avy)+(y.c-avy)*(y.c-avy);
	if (fca!=fcb) return fca<fcb;
	else return max(x.a,max(x.b,x.c))<max(y.a,max(y.b,y.c));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for (;t--;)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		}
		sort(a+1,a+n+1,cmp);
		for (int i=1;i<=n;i++)
		{
			bool a_=false,b_=false,c_=false;
			if (max(a[i].a,max(a[i].b,a[i].c))==a[i].a) a_=true;
			if (max(a[i].a,max(a[i].b,a[i].c))==a[i].b) b_=true;
			if (max(a[i].a,max(a[i].b,a[i].c))==a[i].c) c_=true;
			if (a_&&am<n/2)
			{
				am++;
				ans+=a[i].a;
			}
			else if (b_&&bm<n/2)
			{
				bm++;
				ans+=a[i].b;
			}
			else if (cm<n/2)
			{
				cm++;
				ans+=a[i].c;
			}
		}
		printf("%d\n",ans);
		//chongzhi
		am=0;
		bm=0;
		cm=0;
		ans=0;
	}
} 

