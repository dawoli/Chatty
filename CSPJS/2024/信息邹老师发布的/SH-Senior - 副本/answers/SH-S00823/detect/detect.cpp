#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;
int ans,ans2;
int n,m,l,V;
int cd[MAXN],cv[MAXN],ca[MAXN],p[MAXN],p2[MAXN];

struct cjh_AREA{
	int cjh_from,cjh_to;
}cjh_area[MAXN];
int nw;

inline void cjh_input()
{
	scanf("%d%d%d%d",&n,&m,&l,&V);
	for(int i=0;i<n;++i)
	{
		scanf("%d%d%d",&cd[i],&cv[i],&ca[i]);
	}
	for(int i=0;i<m;++i)
	{
		scanf("%d",&p[i]);
		p2[m-i-1]=-p[i];
	}
	return;
} 

int cjh_posa(int d,int v,int a)
{
	double vv=v,aa=a;
	double dv=V-vv;
	double tt=dv/a*(v+dv/2);
//	cout<<vv<<" "<<aa<<" "<<dv<<" "<<tt;
	int cc=ceil(tt);
	if(double(cc)==tt)return d+cc+1;
	return d+cc;
}

int cjh_nega(int d,int v,int a)
{
//	double vv=v,aa=a;
//	double dv=vv-V;
//	double tt=dv/aa*(vv+dv/2);
//	return d+floor(tt);
	double vv=v,aa=a;
	double dv=V-vv;
	double tt=dv/a*(v+dv/2);
//	cout<<vv<<" "<<aa<<" "<<dv<<" "<<tt;
	int cc=floor(tt);
	if(double(cc)==tt)return d+cc-1;
	return d+cc;
}

inline void cjh_solve1()
{
	for(int i=0;i<n;++i)
	{
		if(ca[i]>0)
		{
			int posa=cjh_posa(cd[i],cv[i],ca[i]);
			int fd=lower_bound(p,p+m,posa)-p;
			if(fd==m)continue;
			cjh_area[nw].cjh_from=fd;
			cjh_area[nw].cjh_to=m;
			nw++;
//			cout<<i<<endl;
		}
		else if(ca[i]==0)
		{
			if(cv[i]<=V)continue;
			int fd=lower_bound(p,p+m,cd[i])-p;
//			cout<<i<<" "<<fd<<endl;
			if(fd==m)continue;
			cjh_area[nw].cjh_from=fd;
			cjh_area[nw].cjh_to=m;
			nw++;
		}
		else
		{
			if(cv[i]<=V)continue;
			
			int fd=lower_bound(p,p+m,cd[i])-p;
			if(fd==m)continue;
			
			int nega=cjh_nega(cd[i],cv[i],ca[i]);
			int fd2=lower_bound(p2,p2+m,-nega)-p2;
			if(fd==m)continue;
			fd2=m-fd2-1;
			
//			cout<<cd[i]<<" "<<nega<<endl;
//			cout<<fd<<" "<<fd2<<endl;
			
			if(fd>fd2)continue;
			
			cjh_area[nw].cjh_from=fd;
			cjh_area[nw].cjh_to=fd2;
			nw++;
			
//			cout<<i<<endl;
		}
	}
	ans=nw;
}

bool cmp(cjh_AREA cjh_AREA1,cjh_AREA cjh_AREA2)
{
	if(cjh_AREA1.cjh_from==cjh_AREA2.cjh_from)return cjh_AREA1.cjh_to<cjh_AREA2.cjh_to;
	return cjh_AREA1.cjh_from<cjh_AREA2.cjh_from;
}

inline void test2()
{
	cin>>ans;
	nw=ans;
	for(int i=0;i<ans;++i)
	{
		cin>>cjh_area[i].cjh_from;
		cin>>cjh_area[i].cjh_to;
	}
//	sort(cjh_area,cjh_area+nw,cmp);
}

inline void cjh_solve2()
{
	sort(cjh_area,cjh_area+nw,cmp);
//	for(int i=0;i<ans;++i)
//	{
//		cout<<cjh_area[i].cjh_from<<" "<<cjh_area[i].cjh_to<<endl;
//	}
	int ttl=-1,ttf,ttt,ttp=-1;
	for(int i=0;i<ans;++i)
	{
		ttf=cjh_area[i].cjh_from;
		ttt=cjh_area[i].cjh_to;
		
//		cout<<ttl<<" "<<ttf<<" "<<ttt<<" "<<ttp<<endl;
		
		if(ttl==-1)
		{
			ttl=ttt;
		}
		if(ttp==ttf)continue;
		if (ttf>ttl)
		{
			ttl=ttt;
			ttp=ttf;
			ans2++;
		}
		if(ttt<ttl)
		{
			ttl=ttt;
		}
	}
	ans2++;
	ans2=m-ans2;
}

inline void cjh_output()
{
	printf("%d %d\n",ans,ans2);
}

inline void cjh_init()
{
	ans=0;
	nw=0;
	ans2=0;
//	for(int i=0;i<MAXN;++i)
//	{
//		cjh_area[i].cjh_from=0;
//		cjh_area[i].cjh_to=0;
//	}
	return;
}

inline void cjh_test()
{
	cin>>V;
	int d,v,a;
	cin>>d>>v>>a;
	cout<<cjh_posa(d,v,a)<<endl;
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
//	test2();
//	cjh_solve2();
//	cjh_output();
	
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;++i)
	{
		cjh_init();
		cjh_input();
		cjh_solve1();
		if(!ans)ans2=m;
		else cjh_solve2();
		cjh_output();
	}
//	
//	while(1)cjh_test();
	
	return 0;
}
