#include<bits/stdc++.h>
#define mod 23333
using namespace std;
int a[500005],s[500005],cnt;
int len;
struct st
{
	int lt,rt;
}qujian[50000005];
bool cmp(st a,st b)
{
	return a.rt-a.lt==b.rt-b.lt?a.lt<b.lt:a.rt-a.lt<b.rt-b.lt;
}
inline int f(int l,int r)
{
	return s[r] xor s[l-1];
}
void check(int i,int j)
{
	if((qujian[i].lt<=qujian[j].lt&&qujian[j].lt<=qujian[i].rt||qujian[i].lt<=qujian[j].rt&&qujian[j].rt<=qujian[i].rt)&&qujian[i].lt!=-1&&qujian[j].lt!=-1)
	{
		if(qujian[i].rt-qujian[i].lt>qujian[j].rt-qujian[j].lt)
		{
			cnt--;
			qujian[i].lt=-1;
			qujian[i].rt=-1;
		}
		else
		{
			cnt--;
			qujian[j].lt=-1;
			qujian[j].rt=-1;
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d %d",&n,&k);
	scanf("%d",&a[1]);
	s[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1] xor a[i];
	}
	/*while(i<=n)
	{
		flag=0;
		i=l+1;
		for(j=i;j<=n;j++)
		{
			if(flag)
				break;
			for(l=j;l<=n;l++)
				if(f(j,l)==k)
				{
					front_cnt++;
					flag=1;
					break;
				}
		}
	}
	l=n+1;
	while(i>0)
	{
		flag=0;
		i=l-1;
		for(j=i;j>0;j--)
		{
			if(flag)
				break;
			for(l=j;l>0;l--)
				if(f(l,j)==k)
				{
					back_cnt++;
					flag=1;
					break;
				}
		}
	}*/
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
		{
			int t=f(l,r);
			if(t==k)
			{
				qujian[len].lt=l;
				qujian[len].rt=r;
				len++;
			}
		}
	sort(qujian,qujian+len,cmp);
	cnt=len;
	for(int i=0;i<len;i++)
		for(int j=i+1;j<len;j++)
			check(j,i);
	printf("%d\n",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
