#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=1e6+10;
int cnts;
int T,n,m,L,V;
int a[N],v[N],d[N],p[N],kl[N],kr[N],k[N],ans1,ans2;
struct node{
	int l;
	double r,vl,vr;
}seg[N];
int eq(double x,double y){
	if(x-y<=1e-7) return 1;
	else return 0;
}
double vt(int s,int aa,int vv){
	return sqrt(vv*vv+2*aa*s);
}
double s(int v1,int v2,int aa){
	return (v1*v1-v2*v2)*1.0/(2*aa*1.0);
}
void solve1(){
	int ss;
	for(int i=1;i<=n;i++){
		ss=L-d[i];
		if(a[i]>=0)
			if(v[i]>V)seg[++cnts].l=d[i],seg[cnts].r=L*1.0,seg[cnts].vl=v[i]*1.0,seg[cnts].vr=vt(ss,a[i],v[i]);
			else
				if(vt(ss,a[i],v[i])>V*1.0)
					seg[++cnts].l=d[i]+s(V,v[i],a[i]),seg[cnts].r=L*1.0,seg[cnts].vl=V*1.0,seg[cnts].vr=vt(ss,a[i],v[i]);
		else
			if(v[i]>V)
				if(s(V,v[i],a[i])>ss)
					seg[++cnts].l=d[i],seg[cnts].r=L*1.0,seg[cnts].vl=v[i]*1.0,seg[cnts].vr=vt(ss,a[i],v[i]);
				else
					seg[++cnts].l=d[i],seg[cnts].r=d[i]*1.0+s(V,v[i],a[i]),seg[cnts].vl=v[i]*1.0,seg[cnts].vr=V*1.0;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		ans1=0;
		ans2=0;
		scanf("%d %d %d %d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)
			scanf("%d %d %d",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
		}
		sort(p+1,p+m+1);
		solve1();
		for(int i=1;i<=cnts;i++){
			kl[i]=lower_bound(p+1,p+n+1,seg[i].l)-a;
			kr[i]=upper_bound(p+1,p+n+1,seg[i].r)-a-1;
		}
		for(int i=1;i<=n;i++)
			if(kl[i]>=1&&kr[i]<=n) ans1++;
		cout<<ans1<<" "<<ans1;
		cout<<endl;
	}
	return 0;
}
