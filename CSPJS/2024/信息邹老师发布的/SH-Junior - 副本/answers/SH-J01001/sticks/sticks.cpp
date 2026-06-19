#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int sticks[]={-1,6,2,5,5,4,5,6,3,7,6};
int n,t,re;
int check(int n)
{
	for(int i=2;i<=10;i++)
	{
		if(sticks[i]==n)
			return i-1;
	}
}
int check2(int now_num,int group,int sub)
{
	re=now_num*pow(10,(group));
	int now_set=1;
	while(sub>0)
	{
		if(now_set>=group)
			break;
		now_set++;	
		re+=8*pow(10,now_set-1);
		sub--;
	}
	if(sub>0)
	{
		for(int i=now_num+1;i<n;i++)
		{
			if(sub-(sticks[i]-sticks[now_num]==0))
			{
				re+=(i-now_num)*pow(10,group);
				return re;
			}
		}
	}
}
int func(int n)
{
	if(n==1)
		return -1;
	int group=n/7;
	if(group==0)
		return check(n);
	else
	{
		int sum=2+group*6;
		int sub=n-sum,now_num=1;
		if(sub<=group)
		{
			re=now_num*pow(10,(group));
			for(int i=0;i<group;i++)
				re+=8*pow(10,i);
			return re;	
		}
		else
		{
			int re1=check2(now_num,group,sub);
			int a[group+2],spl=re1,set=1;
			while(spl)
			{
				a[set++]=spl%10;
				spl/=10;	
			}		
			int sum=a[set-1]*pow(10,(group));
			sort(a+2,a+group+1);
			for(int i=1;i<=group;i++)
			{
				sum+=a[i]*pow(10,(group-i));
			}
			return sum;
		}
	}
	
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		int re=0;
		cout<<func(n)<<endl;	
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
