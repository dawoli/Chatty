#include<bits/stdc++.h>
using namespace std;
struct student
{
	long long a;
	long long b;
	long long c;
	long long mid; 
	long long max;
	long long min;
};
student stu[100005];
long long an=0,bn=0,cn=0; //记得每次循环后改为0！！！ 
long long n;
bool cmpmax(student a,student b)
{
	return a.max>b.max;
}
long long foundmq(student a)
{
	if(0==a.a)
	{
		an++;
		return 0;
	}
	else if(0==a.b)
	{

		bn++;
		return 0;
	
	}
	else if(0==a.c)
	{

		cn++;
		return 0;


	}
}
long long foundmp(student a)
{
	if(a.max==a.a) 
	{
		if(an<n/2)
		{
			an++;
			return a.max;
		}
		else return foundmq(a);	
	}
	else if(a.max==a.b)
		if(bn<n/2)
		{
			bn++;
			return a.max;
		}
		else return foundmq(a);	
	else if(a.max==a.c)
	{
		if(cn<n/2)
		{
			cn++;
			return a.max;
		}
		else return foundmq(a);	
	}
}
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	for(long long i=0;i<t;i++)
	{
		long long ans=0;
		cin>>n;
		for(long long j=0;j<n;j++)
		{
			long long a,b,c;
			cin>>a>>b>>c;
//找到中间值、最大值 
			if(a>=b &&a<=c)	
			{
				stu[j].mid=a;
				stu[j].max=c-a;
				stu[j].min=b-a;	
			}
			else if(a>=c&&a<=b)
			{
				stu[j].mid=a;
				stu[j].max=b-a;
				stu[j].min=c-a;
				
			}
			else if(b>=a &&b<=c)
			{
				stu[j].mid=b;
				stu[j].max=c-b;	
				stu[j].min=a-b;
			}
			else if(b>=c&&b<=a)	
			{
				stu[j].mid=b;
				stu[j].max=a-b;
				stu[j].min=c-b;
			}		
			else if(c>=a &&c<=b)
			{
				stu[j].mid=c;
				stu[j].max=b-c;
				stu[j].min=a-c;
			}
			else if(c>=b&&c<=a)
			{
				stu[j].mid=c;
				stu[j].max=a-c;
				stu[j].min=b-c;
			}
			stu[j].a=a-stu[j].mid;
			stu[j].b=b-stu[j].mid;
			stu[j].c=c-stu[j].mid;
		}
	//数据处理完毕
	//先排最大值 
	//一个去满了不代表别的数组不能去取他的最大值 
		for(long long j=0;j<n;j++) ans+=stu[j].mid;
//		for(int j=0;j<n;j++) cout<<stu[j].a<<endl<<stu[j].b<<endl<<stu[j].c<<endl<<stu[j].max<<endl<<stu[j].mid<<endl<<stu[j].min<<endl<<stu[j].midd<<endl;
		sort(stu,stu+n,cmpmax);
		for(long long j=0;j<n;j++)
		{		
			long long anss=foundmp(stu[j]);
			ans+=anss;
		}
		cout<<ans<<endl;
		an=0;
		bn=0;
		cn=0;
	}
	return 0;
 } 
