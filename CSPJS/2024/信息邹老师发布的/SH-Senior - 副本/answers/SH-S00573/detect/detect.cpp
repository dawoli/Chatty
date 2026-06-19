/*
每台车给定初始位置，初始速度和加速度
求出超速车数以及至多关闭几个测速仪

部分分:
20:n<=20
50:n<=3000
100:n<=100000

50分做法：


满分做法：
对于一台车，只有一个区间可能拦截到他
可以采用二分求出区间
题目变成：给定n个限制，每次指定第a[i]个测速器到第b[i]个测速器必须留一个，问最少留几个 
按左端点排序，每次选区间中最后一个，最终统计答案

formulas: 注意真正位置=S+S0
S=v0*t+0.5*a*t*t
v=sqrt(v0*v0+2*a*S)
v=S*2a+v0*v0

*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using Pair=pair<int,int>; 
const int maxn1=21;
const int maxn=1e5+5;
const int maxl=1e6+5;
const int maxv=1e3+5;
int T,n,m,L,V,d[maxn],v[maxn],a[maxn],det[maxn];
Pair lim[maxn];
bool cmp(Pair x,Pair y) {
	return x.second<y.second;
}
signed main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) {
			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
		}
		for(int i=1;i<=m;i++) {
			scanf("%lld",&det[i]);
		}
		sort(det+1,det+m+1);
		for(int i=1;i<=n;i++) {
			int start=lower_bound(det+1,det+m+1,d[i])-det;
			if(start>m)  continue;
			if(a[i]==0) {
				if(v[i]>V)  lim[i]={start,m};
				else  lim[i]={1,0};
			}
			else if(a[i]>0) {
				//v=sqrt(v0*v0+2*a*S)
				int base=start-1;
				for(int step=20;step>=0;step--) {
					int test=base+(1<<step);
					if(test>m)  continue;
					if(v[i]*v[i]+2*a[i]*(det[test]-d[i])<=V*V)  base=test;
				}
				lim[i]={base+1,m};
			}
			else {
				//v=S*2a+v0*v0
				//S=v0*t+0.5*a*t*t
				double vv=v[i],aa=a[i],dd=d[i];
				int base=start-1;
				double time=-vv/aa,limit=vv*time+0.5*aa*time*time;
				for(int step=20;step>=0;step--) {
					int test=base+(1<<step);
					if(test>m)  continue;
					if((det[test]-d[i])<=limit&&(det[test]-d[i])*2*a[i]+v[i]*v[i]>V*V)  base=test;
				}
				lim[i]={start,base};
			}
		}
		sort(lim+1,lim+n+1,cmp);
		int cnt=0,cur=0,ans=0;
		for(int i=1;i<=n;i++) {
			int l=lim[i].first,r=lim[i].second;
			if(l>r||l==0||r>m)  continue;
			cnt++;
			if(l>cur)  ans++,cur=r;
		}
		cout<<cnt<<" "<<m-ans<<"\n";
	}
	return 0;
}
