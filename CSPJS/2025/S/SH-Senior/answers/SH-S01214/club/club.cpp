#include<bits/stdc++.h>
using namespace std;
long long n,m,t,a[100001][4],b[100001],c[100001],s;
dfs(long long step,long long ans,long long q,long long w,long long p)
{
	if(step>n)
	{
	s=max(s,ans);
	return 0;	
	}
	if(q!=n/2)
	dfs(step+1,ans+a[step][0],q+1,w,p);	
	if(w!=n/2)
	dfs(step+1,ans+a[step][1],q,w+1,p);	
	if(p!=n/2)
	dfs(step+1,ans+a[step][2],q,w,p+1);	

}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++)
	{ 
	s=0;
		cin>>n;
		long long k=n/2,q=0,w=0,p=1;
		for(long long j=1;j<=n;j++)
		{
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			if(a[j][2]==0&&p==1) 
			{
				p=1;
			b[j]=a[j][0]-a[j][1];
			c[j]=j;	
			}
			else
			p=0;
		}
		if(p==1)
		{
			for(long long j=1;j<n;j++)
		{
			for(long long z=n;z>j;z--)
			if(abs(b[c[z]])>abs(b[c[z-1]]))
			{
				swap(c[z],c[z-1]);
			}
		}	
		for(long long j=1;j<=n;j++)
		{
		if(q==k||w==k)
		{
		p=j;
		break;		
		}	
		if(b[c[j]]<=0)
		{
		s+=a[c[j]][1];
		w++;	
		}
		else
		{
			s+=a[c[j]][0];
			q++ ; 
			}	
		}
		 if(q==k)
		 {
		 	for(long long j=p;j<=n;j++)
		 	s+=a[c[j]][1];
		 }
		 else
		 if(w==k)
		{
			for(long long j=p;j<=n;j++)
			s+=a[c[j]][0];
		}
		cout<<s<<endl;
		}
		else
		{
		dfs(1,0,0,0,0);	
		cout<<s<<endl; 
		}
	}
	return 0;
}








































































/*
希望有人看到吧 也许真的没有人看完吧 
t1的时候我就想放弃了因为tm的一个冒泡写了我整整2个小时
这一次应该是我退出信奥的最后一个考试了
哎中考也感觉考不上了
我这次也没有任何希望了自己预估分数为100左右
在这里也附上我的哔哩哔哩账号名吧
分不清真假的虚无
三角洲账号：玩大坝的虚无 
三角洲直接加我就行了 
在刚刚学习信奥的时候是那么的感觉有趣
可真正的进入s组后
发现自己是多么的弱
原先是j组的300分鼓励了我来继续
可是现实是那么的残酷
s组对于我而言已经难如天花板了
我已经对s组的一等奖没有抱任何希望了
可能这是我的最后一次接触信奥了吧
已后就没有这么多机会了
也许这只是一次分别
但也有可能是一次永别 
信奥铸就了我对编程的深入了解
也打碎了我编程一个向往的心 
t1虽然以经有了思路 但是我不会排序啊
我其他的题目看天命吧
希望有三角洲电脑大佬带带我
也想要一个固排不会嘲笑我玩的菜 
也许没有人会看到这个东西吧 
哎时间也差不多了 
我给看到的人一个祝福吧
祝
看到的人信奥
一路顺风
畅通无阻
考试总是能全对&ak 
也祝愿我自己一切顺利 
还有一个东西 
hallow world 
*/ 
