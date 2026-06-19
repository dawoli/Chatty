#include<cstdio>
#include<iostream>
using namespace std;
//true=red,false=blue
typedef struct
{
	int a;
	bool color;
} entry;
long* c=new long[1];
entry* a=new entry[1];
long score(entry* a,int len)
{
	long score=0;
	bool found;
//	for(int i=0;i<len;i++)
//	{
//		printf("%c%d ",a[i].color?'r':'b',a[i].a);
//	}
//	printf("\n");
	for(int i=0;i<len;i++)
	{
//		printf("%d:color=%c,",i,a[i].color?'r':'b');
		found=false;
		for(int j=i-1;j>=0;j--)
			if(a[i].color==a[j].color)
			{
				found=true;
//				printf("left_common=%d,value=%d,",j,a[j].a);
				if(a[i].a==a[j].a)
				{
					c[i]=a[i].a;
//					printf("value_same=true,score=%d\n",a[i].a);
				}
				else
				{
					c[i]=0;
//					printf("value_same=false,score=0\n");
				}
				break;
			}
		if(!found)
		{
			c[i]=0;
//			printf("left_common=-1,score=0\n");
		}
	}
//	printf("c=[");
	for(int i=0;i<len;i++)
	{
//		printf("%d,",c[i]);
		score+=c[i];
	}
//	printf("]\ntotal_score=%d\n",score);
	return score;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t,n,carry;
	long max_score;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		max_score=0;
		cin>>n;
		delete[] c;
		delete[] a;
		c=new long[n];
		a=new entry[n];
		for(int j=0;j<n;j++)
		{
			cin>>a[j].a;
			a[j].color=0;
		}
		while(!a[n-1].color)
		{
			max_score=max(score(a,n),max_score);
			carry=1;
			for(int j=0;j<n;j++)
			{
				if(!carry)
					break;
				else
				{
					a[j].color=(!a[j].color);
					if(!a[j].color)
						carry=1;
					else
						carry=0;
				}
			}
		}
		cout<<max_score<<endl; 
	}
	return 0;
}
