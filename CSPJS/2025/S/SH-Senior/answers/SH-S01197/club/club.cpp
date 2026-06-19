#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int id,a1,a2,b1,b2;
	bool operator < (const struct node & t ) const
	{
		return abs(a1-b1)==abs(t.a1-t.b1)?(a1==t.a1?b1<t.b1:a1<t.a1):abs(a1-b1)>abs(t.a1-t.b1);
	}
}NODE,*PNODE;
int arr[100005][3],gty1[100005],gty2[100005],gty3[100005],gogogo[100005];
NODE maxw[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int N,T,i,j,sum,gyg,wh,a_l,b_l,c_l;
	scanf("%d",&T);
	while(T--)
	{
		memset(gty1,0,sizeof(gty1));
		memset(gty2,0,sizeof(gty2));
		memset(gty3,0,sizeof(gty3));
		gyg=sum=0;
		a_l=b_l=c_l=0;
		scanf("%d",&N);
		for(i=1;i<=N;++i)
		{
			for(j=0;j<3;++j)
			{
				scanf("%d",&arr[i][j]);
				maxw[i].id=i;
				if(maxw[i].a1<arr[i][j])
				{
					maxw[i].b1=maxw[i].a1,maxw[i].b2=maxw[i].a2;
					maxw[i].a1=arr[i][j],maxw[i].a2=j;
				}
				else if(maxw[i].b1<arr[i][j])
					maxw[i].b1=arr[i][j],maxw[i].b2=j;
			}
		}
		for(i=1;i<=N;++i)
		{
			if(!maxw[i].a2)
				gty1[++a_l]=i;
			if(maxw[i].a2==1)
				gty2[++b_l]=i;
			if(maxw[i].a2==2)
				gty3[++c_l]=i;
		}
		for(i=1;i<=N;++i)
			gogogo[i]=maxw[i].a2;
		if(gyg<a_l)
			gyg=a_l,wh=0;
		if(gyg<b_l)
			gyg=b_l,wh=1;
		if(gyg<c_l)
			gyg=c_l,wh=2;
		if(gyg>N/2)
		{
			sort(maxw+1,maxw+1+N);
			//for(i=1;i<=N;++i)
			//	printf("-.- %d %d %d %d\n",maxw[i].a1,maxw[i].a2,maxw[i].b1,maxw[i].b2);
			if(!wh)
			{
				for(i=gyg;i>N/2;--i)
					gogogo[gty1[maxw[i].id]]=maxw[gty1[maxw[i].id]].b2;
			}
			if(wh==1)
			{
				for(i=gyg;i>N/2;--i)
					gogogo[gty2[maxw[i].id]]=maxw[gty2[maxw[i].id]].b2;
			}
			if(wh==2)
			{
				for(i=gyg;i>N/2;--i)
					gogogo[gty3[maxw[i].id]]=maxw[gty3[maxw[i].id]].b2;
			}
		}
		for(i=1;i<=N;++i)
			sum+=arr[maxw[i].id][gogogo[maxw[i].id]];
		printf("%d\n",sum);
		for(i=1;i<=N;++i)
		{
			for(j=0;j<3;++j)
				maxw[i].a1=maxw[i].a2=maxw[i].b1=maxw[i].b2=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
