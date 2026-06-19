#include<bits/stdc++.h>
using namespace std;
typedef struct monster
{
	int pw;
	int rp;
}MONSTER,*PMONSTER;
MONSTER r[100005],bucket[100005];
int n;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int i,_min2=INT_MAX,_min1=INT_MAX,_max=INT_MIN,pos,a;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&r[i].pw);
		r[i].rp=r[i].pw;
		if(_max<r[i].pw)
			_max=r[i].pw;
		if(_min1>r[i].pw)
			_min1=r[i].pw;
	}
	for(i=1;i<=n;i++)
	{
		bucket[r[i].pw].pw++;
		bucket[r[i].pw].rp++;
	}
	for(i=1;i<=100000;i++)
	{
		if(bucket[i].pw!=0)
			a++;
		if(a==2)
			break;
	}
	_min2=i;
	pos=_min1;
	for(i=_min2;i<=_max;i++)
	{
		if(!bucket[i].pw)
		{
			continue;
		}
		if(bucket[i].pw>=bucket[pos].rp)
		{
			bucket[i].pw-=bucket[pos].rp;
			n-=bucket[pos].rp;
			bucket[pos].rp=0;
			for(i=pos;i<=_max;i++)
			{
				if(bucket[i].rp!=0)
				{
					pos=i;
					break;
				}
			}
		}
		else if(bucket[i].pw<bucket[pos].rp)
		{
			bucket[pos].rp-=bucket[i].pw;
			n-=bucket[i].pw;
			bucket[i].pw=0;
		}
	}
	printf("%d",n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
