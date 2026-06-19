#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 114514
double p[N];
struct car {
	double d,e,v,a;//开始超速位、结束超速位、初始速度、加速度
	bool k1,k2;//开闭 
}c[N];
struct vover {//超速还被看见的车 
	int s,t;//被看见的起点和终点 
}co[N];
bool cmp(const car&x,const car&y) {
	if(x.d!=y.d) return x.d<y.d;
	return x.e<y.e;
}
bool cmp2(const vover&x,const vover&y) {
	if(x.s!=y.s) return x.s<y.s;
	return x.t<y.t;
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		int n,m;
		double L,V;//车辆数量、测速仪数量、主干道长度、道路限速
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) {
			int d;
			cin>>d>>c[i].v>>c[i].a;
			if(c[i].a==0) {
				if(c[i].v>V) {
					c[i].d=d,c[i].e=L;
				}
				else c[i].d=c[i].e=0;
			}
			else if(c[i].a>0) {
				double t2=(V-c[i].v)/(-c[i].a);
				double s2=d+c[i].v*t2+0.5*c[i].a*t2*t2;
				if(s2<=L) {
					c[i].d=s2,c[i].e=L;
					c[i].k1=1;
				}
				else c[i].d=c[i].e=0;
			}
			else {
				if(c[i].v<=V) c[i].d=c[i].e=0;
				else {
					c[i].d=d;
					double t2=(c[i].v-V)/(-c[i].a);
					double s2=d+c[i].v*t2+0.5*c[i].a*t2*t2;
					if(s2>L) c[i].e=L;
					else {
						c[i].e=s2;
						c[i].k2=1;
					}
				}
			}
		}
		sort(c+1,c+n+1,cmp);
		//Step1 确定每辆车超速距离区间 
		for(int i=1;i<=m;i++) {
			cin>>p[i];
		}
		sort(p+1,p+m+1);
		int nO=0;
		int mat=0;
		for(int i=1;i<=n;i++) {
			if(c[i].d==0&&c[i].e==0) continue;
			int p1=lower_bound(p+1,p+m+1,c[i].d)-p;
			int p2=upper_bound(p+1,p+m+1,c[i].e)-p-1;
			if(p[p2]==c[i].e&&c[i].k2) p2--;
			if(p[p1]==c[i].d&&c[i].k1) p1++;
			if(p1>p2) continue;
			co[++nO].s=p1;
			co[nO].t=p2;
			mat=max(mat,p2);
		}
		cout<<nO<<" ";
		//Step2 确定每辆车超速被谁看见（测速仪编号） 
		sort(co+1,co+nO+1,cmp2);
		//for(int i=1;i<=n;i++) cout<<co[i].s<<" "<<co[i].t<<"\n";
		int i=1;
		ll ans=0;
		while(i<=nO) {
			//cout<<i<<" ";
			int j=i;
			int mi=(1<<30);
			while(co[j].s<=mi&&j<=nO) {
				mi=min(mi,co[j].t);
				j++;
			}
			//cout<<j<<"\n";
			i=j;//在co[j-1].s位置，果断选择盖，盖住的别管，j继续 
			ans++;
		}
		cout<<m-ans<<"\n";//最多关几个=测速仪数量-最少开几个 
		//Step3 确定最小区间盖点解决 
	}
	return 0;
}
