#include<bits/stdc++.h>
#define N ((int)(1e5)+10)
using namespace std;
typedef long long ll;
const double eps=1e-3;
struct node{
	int first,second;
};
int T;
int n,m,L,V;
int d[N],v[N],a[N];
int p[N];
int l[N],r[N];
node checker[N];
int cnt;
int ans;
inline double cal(int aa,int vv){
	return 1.0*(V*V-vv*vv)/2.0/aa;
}
inline node check(int l_,int r_){
	int ll,rr;
	ll=lower_bound(p+1,p+m+1,l_)-p;
	rr=lower_bound(p+1,p+m+1,r_)-p-1;
	if(r_>=p[m])rr=m;
	return {ll,rr};
}
inline bool cmp(node x,node y){
	if(x.second!=y.second)return x.second<y.second;
	else return x.first<y.first;
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		scanf("%d %d %d %d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)scanf("%d %d %d",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;i++)scanf("%d",&p[i]);
		cnt=0;
		ans=n;
		for(int i=1;i<=n;i++){
			if(a[i]==0&&v[i]>V)cnt++,l[cnt]=d[i],r[cnt]=L;
			else if(a[i]>0)cnt++,l[cnt]=d[i]+cal(a[i],v[i])+1,r[cnt]=L;
			else if(a[i]<0&&v[i]>V)cnt++,l[cnt]=d[i],r[cnt]=d[i]+cal(a[i],v[i])-eps;
			else {ans--;continue;}
			node x=check(l[cnt],r[cnt]);
			if(x.first>x.second)ans--,cnt--;
		}
		printf("%d ",ans);
		ans=0;
		for(int i=1;i<=cnt;i++)checker[i]=check(l[i],r[i]);
		sort(checker+1,checker+cnt+1,cmp);
		int lst=0;
		for(int i=1;i<=cnt;i++){
			int ll=checker[i].first,rr=checker[i].second;
			if(ll>lst)ans++,lst=rr;
		}
		printf("%d\n",m-ans);
	}
}
