#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
ll T;
ll n,m,l,lv;//limited_v
struct car
{
	ll ds,dt;
}c[N];
bool f[N];
ll p[N];
ll ans1,ans2;//ans1 refers to total number and ans2 refers to how many to stop
bool cmp(car a,car b)
{
	if(a.ds!=b.ds) return a.ds<b.ds;
	else return a.dt<b.dt;
}
ll Finds(ll x)//找出第一个p[i]>=x的i 
{
	ll l=0,r=m+1;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(p[mid]>=x) r=mid;
		else l=mid+1; 
	}
	return l;
}
ll Findt(ll x)//找出最后一个p[i]<=x的i
{
	ll l=0,r=m+1;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(p[mid]<=x) l=mid+1;
		else r=mid;
	}
	return l-1;
} 
struct Sgt
{
	ll ds,dt;
}e[N];
bool cmp2(Sgt a,Sgt b)
{
	if(a.dt!=b.dt) return a.dt<b.dt;
	else return a.ds<b.ds;//t相等时，保留最下面的元素，即最下面的元素的s值最大 
}
void Init()
{
	memset(p,0,sizeof(p));
	memset(c,0,sizeof(c));
	memset(f,0,sizeof(f));
	memset(e,0,sizeof(e));
	ans1=ans2=0;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		Init();
		scanf("%lld%lld%lld%lld",&n,&m,&l,&lv);
		ll t=0;//记录超速车的总数
		//caution: t>=ans1 because of the potential escape!
		for(int i=1;i<=n;++i)
		{
			ll d,v0,a;
			scanf("%lld%lld%lld",&d,&v0,&a);
			if(!a)//匀速直线 
			{
				if(v0<=lv) continue;//关我屁事
				else//从早超速到晚 
				{
					t++;
					c[t].ds=d,c[t].dt=l;
				} 
			}
			else if(a>0)//匀加速直线 
			{
				ll vt2=v0*v0+2*a*(l-d);//vt^2
				if(v0>lv)//刚上高速就飙车 
				{
					t++;
					c[t].ds=d,c[t].dt=l;
				}
				else if(vt2<=lv) continue;//始终不超速，遵纪守法好市民
				else
				{
					t++;
					c[t].dt=l;
					ll tw_ax=lv*lv-v0*v0+2*a*d;//2a(x-d)=vt^2-v0^2 
					c[t].ds=tw_ax/(a<<1)+1;//无论是否在整数点达到最大允许速度lv，都只能在此时位置的下一个整数点开始才有可能被测出超速！！！~ 
				} 
			}
			else//匀减速直线
			{
				a*=(-1);//负号外显 
				if(v0<=lv) continue;//始终不超速，遵纪守法好市民
				else if(v0*v0-lv*lv>2*a*(l-d))//到了终点了还刹不住车，注意符号是> 
				{
					t++;
					c[t].ds=d,c[t].dt=l;
				}
				else
				{
					t++;
					c[t].ds=d;
					ll tw_ax=v0*v0-lv*lv+2*a*d;//2a(x-d)=v0^2-vt^2
					if(tw_ax%(a<<1)) c[t].dt=tw_ax/(a<<1);//如果在非整数点降回正常速度，那么在它对应的整除点处任被判定为超速
					else c[t].dt=tw_ax/(a<<1)-1;//否则只会在该点的上一点处被判定为超速 
				}
			} 
		}
		sort(c+1,c+1+t,cmp);
		ll pos=1;
		for(int i=1;i<=m;++i) scanf("%lld",&p[i]);
		p[0]=-1,p[m+1]=l+1;//二分边界 
		for(int i=1;i<=t;++i)//计算出每辆超速车对应能测到的p的编号区间 
		{
			ll dds=Finds(c[i].ds);
			ll ddt=Findt(c[i].dt);
			if(dds<=ddt)//能查到 
			{
				ans1++;
				e[ans1].ds=dds,e[ans1].dt=ddt;
			}
		}
		//cout<<ans1<<endl;
		//subtask1 finished!!! time:  16:07 
		sort(e+1,e+1+ans1,cmp2);
		ll tmps=-1;//当前合并的母数组的s，判断子数组能否被合并，初始使得e[ans1].ds一定>=tmps 
		ll fd=0;//找寻当前母数组的位置 
		for(int i=ans1;i;--i)//倒叙跑一遍，看能不能合并，未被合并的用f=true表示 
		{
			if(e[i].ds>=tmps)//i的ds大，i的dt小，那么i可以合并目前的母数组并成为新的母数组
			{
				tmps=e[i].ds;
				f[fd]=false;
				fd=i;
				f[i]=true;//替换为新的母数组 
			} 
			else//不能合并，说明上一个母数组的合并已经全部结束，开新坑 
			{
				tmps=e[i].ds;
				fd=i;
				f[i]=true;
			}
		}
		ll tmpt=-1;
		for(int i=1;i<=ans1;++i)
		{
			if(!f[i]) continue;
			if(e[i].ds>tmpt)//不能被上一次贪心涵盖
			{
				ans2++;//注意此时的ans2为保留值，输出时需要用m-ans2
				tmpt=e[i].dt; 
			} 
		}
		printf("%lld %lld\n",ans1,m-ans2);
	}
	return 0;
}
/*
subtask1
Firstly,deal with every car's data,find out when they will exceed their speed
If they won't,neglect it!
So we needn't store every car's "dva",just check when they will exceed,store as the form [ds[i],dt[i]],meaning that monitors equipped between [ds,dt] can find out an illegal driver
*/
//however, some cars may escape punishing from the very beginning!
/*
Now let's think about subtask2
一个元素为1~m的数列，已知ans1个区间，求数列至少需要保留多少元素才能使得每个区间内都有元素剩余 
首先肯定要把每个区间按照ds或dt递增排序
如果区间之间有包含关系，那么只要小区间之中有元素，大区间中就一定有元素，进行合并（即删除大区间的要求） 
那么此时剩余的所有区间一定会满足ds1<ds2且dt1<dt2，即ds和dt互不相等 
然后我们从头开始，将第一个区间的最后一个元素x保留（符合贪心策略）
随后将包含x的所有区间(ds[i]<=x)全部删除，第i+1个区间为新的第一个区间，重复上一行的操作直至全部计算完毕
理论可行，开始实践！ time: 16:22
finished! at 16:48
*/
