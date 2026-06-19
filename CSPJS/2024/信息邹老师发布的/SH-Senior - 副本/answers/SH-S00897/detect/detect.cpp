#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
double s1,s2;
ll t,n,m,L,V,a[100005],v[100005],d[100005],p[100005],ans1,ss1,ss2;
ll cnt1,cnt2,cnt3;
ll sp,ep;
int qzh[1000005];
ll stp,enp,ksxh,out[100005],nowid,ans2,tto;
bool tsxza,tsxzb,fflag,flag;
struct edge
{
	int to,next;
}e[9000005];
ll head[100005],cccnt;
void Add(ll uu,ll vv)
{
	e[++cccnt].next=head[uu];
	e[cccnt].to=vv;
	head[uu]=cccnt;
}
struct node
{
	ll bo,s,e;
}f[100005];
struct node2
{
	ll id,num;
}in[100005];
bool cmp(node2 cmpa,node2 cmpb)
{
	return cmpa.num<cmpb.num;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	//cout<<11111;
	scanf("%lld",&t);
	while(t--)
	{	
		cccnt=0;
		memset(head,0,sizeof(head));
		ans1=0;
		ans2=0;
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		cnt1=0;
		cnt2=0;
		cnt3=0;
		tsxza=0;
		tsxzb=0;
		memset(qzh,0,sizeof(qzh));
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
			if(a[i]>0) cnt1++;
			else if(a[i]==0) cnt2++;
			else cnt3++;
			f[i].bo=0;
			f[i].s=0;
			f[i].e=0;
			out[i]=0;
		}
		if(cnt1==0&&cnt2>0&&cnt3==0) tsxza=1;//特殊性质A
		if(cnt1>0&&cnt2==0&&cnt3==0) tsxzb=1;//特殊性质B
		for(int i=1;i<=m;i++)
		{
			scanf("%lld",&p[i]);
			qzh[p[i]]++;//前缀和 
		}
		for(int i=1;i<=L;i++) qzh[i]=qzh[i-1]+qzh[i];
		//问题1
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0) s1=(V*V-v[i]*v[i])*1.0/(2*a[i]);//速度为道路限速的路程 
			s2=s1+d[i];
			flag=0;
			if(s2>floor(s2)) ss1=floor(s2);
			else
			{
				ss1=s2;
				flag=1;
			}
			if(s2<ceil(s2)) ss2=ceil(s2);
			else
			{
				ss2=s2;
				flag=1;
			}
			if(a[i]==0&&v[i]<=V) continue;
			if(a[i]<0&&v[i]<=V) continue;
			if(a[i]>0&&s2>=L) continue;
			if(a[i]==0)
			{
				sp=d[i];
				ep=L;
			}
			if(a[i]<0)
			{
				sp=d[i];
				if(flag==1) ep=min(ss1-1,L);
				else ep=min(ss1,L);
			}
			if(a[i]>0)
			{
				if(flag==1) sp=ss2+1;
				else sp=ss2;
				ep=L;
			}
			//if(i==1) cout<<ep<<" "<<qzh[sp]<<" "<<qzh[ep]<<endl;
			if(sp!=0&&qzh[ep]-qzh[sp-1]>0)
			{
				f[i].bo=1;
				f[i].s=sp;
				f[i].e=ep;
				ans1++;
			}
			else if(sp==0&&qzh[ep]>0)
			{
				f[i].bo=1;
				f[i].s=sp;
				f[i].e=ep;
				ans1++;
			}
		}
		printf("%lld ",ans1);
		//问题2
		if(ans1==0) printf("%lld\n",m); 
		else if(tsxza||tsxzb) printf("%lld\n",m-1);
		else
		{
			for(int i=1;i<=m;i++)
			{
				in[i].id=i;
				in[i].num=0;
			}
			sort(p+1,p+m+1);
			for(int i=1;i<=n;i++)
			{
				if(f[i].bo==0) continue;
				stp=f[i].s;
				enp=f[i].e;
				if(stp==0) ksxh=1;//开始循环
				else ksxh=qzh[stp-1]+1;
				for(int j=ksxh;j<=qzh[enp];j++)
				{
					Add(j,i);
					in[j].num++;
					out[i]++;	
				}
			}
			sort(in+1,in+m+1,cmp);
			for(int i=1;i<=m;i++)
			{
				nowid=in[i].id;
				fflag=0;
				for(int j=head[nowid];j;j=e[j].next)
				{
					tto=e[j].to;
					if(out[tto]<=1)
					{
						fflag=1;
						break;
					}
				}
				if(fflag) continue;
				else
				{
					ans2++;
					for(int j=head[nowid];j;j=e[j].next)
					{
						tto=e[j].to;
						out[tto]-=1;
					}
				}
			} 
			
			
			printf("%lld\n",ans2);
		}
	}
	return 0;
}
