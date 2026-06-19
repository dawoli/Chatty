//P5661 [CSP-J2019] 公交换乘
#include<iostream>
#include<deque>//记录优惠券
using namespace std;
int n,sum=0;
struct Go //公交记录
{
	bool type;//公共交通类型
	int v,t;//v表示价格，t表示时间
}a;
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
deque<Go> q;//双端队列
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a.type>>a.v>>a.t;
		while(!q.empty())//扔掉过期的优惠券		
		{
			if(!cmp(q.front(),a,0))q.pop_front();
			else break;
		}
		if(a.type==0)//地铁
		{
			q.push_back(a);//添加优惠券
			sum+=a.v;
		}
		else//公交
		{
			bool pay=1;//假设要付钱
			if(!q.empty())//用掉优惠券
			{
				for(int i=0;i<(int)q.size();i++)
				{
					if(cmp(q[i],a,1))
					{
						q[i].v=-1;//防止再次找到
						pay=0;//不用付了
						break;//特别注意：找到为止
					}
				}
			}
			if(pay)sum+=a.v;
		}
		//cout<<sum<<endl;
	}
	cout<<sum;
	return 0;
}
