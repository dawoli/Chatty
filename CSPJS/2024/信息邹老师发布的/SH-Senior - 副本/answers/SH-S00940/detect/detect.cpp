#include<bits/stdc++.h>
#define INF 2e9
#define ll long long
#define Ep 0.000001
using namespace std;
const ll N=1e5+5,M=1e5+5;
struct Car{ll d,v,a;}c[N];
struct Range_Dt{ll l,r;}Dt[N];
ll T,n,m,L,V,p[M],cnt,ans1,ans2,pos;
bool cmp(const Range_Dt &x,const Range_Dt &y){
	return x.r<y.r||(x.r==y.r&&x.l<y.l);
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		cnt=ans1=0; ans2=pos=1;
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		for(ll i=1;i<=n;i++) scanf("%lld%lld%lld",&c[i].d,&c[i].v,&c[i].a);
		for(ll i=1;i<=m;i++) scanf("%lld",&p[i]);
		for(ll i=1;i<=n;i++)
		{
			double D_l,D_r,L_max;
			ll Pos_l,Pos_r;
			if(c[i].v<=V)
			{
				if(c[i].a<=0) continue; //不可能超速 
				double X=1.0*(V*V-c[i].v*c[i].v)/(2.0*c[i].a);
				D_l=c[i].d+X+Ep;
				//c[i].d+X的位置,速度正好达到V 
			}
			else D_l=c[i].d;
			//计算D_l,即哪里开始超速
			if(c[i].a>0) D_r=p[m];
			else if(c[i].a==0) D_r=p[m];//c[i].a=0时,c[i].v一定>V
			else
			{
				//c[i].a<0时,c[i].v一定>V
				double X=1.0*(c[i].v*c[i].v-V*V)/(-2.0*c[i].a);
				D_r=c[i].d+X-Ep;
				//c[i].d+X的位置,速度正好达到V 
			}
			//计算D_r,即哪里结束超速 
			Pos_l=lower_bound(p+1,p+m+1,D_l)-p;
			Pos_r=upper_bound(p+1,p+m+1,D_r)-p-1;
			if(Pos_l>m||Pos_l>Pos_r) continue;
			ans1++;
			Dt[++cnt]=(Range_Dt){Pos_l,Pos_r};
		}
//		for(ll i=1;i<=cnt;i++) cout<<Dt[i].l<<' '<<Dt[i].r<<endl;
		printf("%lld ",ans1);
		if(ans1==0)
		{
			printf("%lld\n",m);
			continue;
		}
		sort(Dt+1,Dt+cnt+1,cmp);
//		cout<<endl;
//		for(ll i=1;i<=cnt;i++) cout<<Dt[i].l<<' '<<Dt[i].r<<endl;
		for(ll i=2;i<=cnt;i++)
		{
			if(Dt[i].l<=Dt[pos].r) continue;
			ans2++;
			pos=i;
		}
		printf("%lld\n",m-ans2);
	}
	return 0;
}
