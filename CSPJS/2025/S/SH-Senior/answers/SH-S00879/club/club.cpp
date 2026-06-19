#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int t,n;
long long ans;
struct a0{
	int n[4];
	int m,nm,ms;
}a[100001];
bool cmp(a0 x,a0 y)
{
	return x.ms>y.ms;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int j=0;j<t;j++)
	{
		scanf("%d",&n);
		ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a[i].n[1],&a[i].n[2],&a[i].n[3]);
			if(a[i].n[1]>=a[i].n[2]&&a[i].n[1]>=a[i].n[3]){
				a[i].m=1;
				if(a[i].n[2]>=a[i].n[3]){
					a[i].nm=2;
					a[i].ms=a[i].n[1]-a[i].n[2];
				}
				else{
					a[i].nm=3;
					a[i].ms=a[i].n[1]-a[i].n[3];
				}
			}
			else{
				if(a[i].n[2]>=a[i].n[1]&&a[i].n[2]>=a[i].n[3]){
					a[i].m=2;
					if(a[i].n[1]>=a[i].n[3]){
						a[i].nm=1;
						a[i].ms=a[i].n[2]-a[i].n[1];
					}
					else{
						a[i].nm=3;
						a[i].ms=a[i].n[2]-a[i].n[3];
					}
				}
				else
				{
					a[i].m=3;
					if(a[i].n[1]>=a[i].n[2]){
						a[i].nm=1;
						a[i].ms=a[i].n[3]-a[i].n[1];
					}
					else{
						a[i].nm=2;
						a[i].ms=a[i].n[3]-a[i].n[2];
					}
				}
			}
		}
		sort(a,a+n,cmp);
		int cnt[4],lim=n/2;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=0;i<n;i++)
		{
			if(cnt[a[i].m]<lim)
			{
				cnt[a[i].m]++;
				ans+=a[i].n[a[i].m];
			}
			else ans+=a[i].n[a[i].nm];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
