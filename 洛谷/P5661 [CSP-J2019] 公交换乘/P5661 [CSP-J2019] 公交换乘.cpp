//P5661 [CSP-J2019] 公交换乘
#include<iostream>
#include<queue>//记录优惠券
using namespace std;
int n,sum=0;
struct Go //公交记录
{
	bool type;//公共交通类型
	int v,t;//v表示价格，t表示时间
}a[100001];
bool cmp(Go a,Go b,bool flag)//确定是否使用优惠券，a是优惠券，b是现在,flag表示考不考虑价格
{
	if(flag==0)
	{
		if(b.t-a.t<=45)return 1;
	}
	if(flag==1)
	{
		if(b.t-a.t<=45&&a.v>=b.v)return 1;
	}	
	return 0;
}
queue<Go> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[n].type>>a[n].v>>a[n].t;
		while(!q.empty())//扔掉过期的优惠券		
		{
			if(!cmp(q.front(),a[n],0))q.pop();
			else break;
		}
		if(a[n].type==0)//地铁
		{
			q.push(a[n]);//添加优惠券
			sum+=a[n].v;
		}
		else//公交
		{
			if(!q.empty()&&cmp(q.front(),a[n],1))q.pop();//用掉优惠券
			else sum+=a[n].v;
		}
		//cout<<sum<<endl;
	}
	cout<<sum;
	return 0;
}
