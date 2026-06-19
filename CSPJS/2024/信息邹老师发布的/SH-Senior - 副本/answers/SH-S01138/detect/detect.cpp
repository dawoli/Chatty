#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct car{
	int d,v,a;
};
car s[N];
int p[N];
int n,m,L,V;
int fid1(int aim){
	int l=1,r=m;
	int ret=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(p[mid]>=aim){
			ret=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return ret;
}
int fid2(int aim){
	int l=1,r=m;
	int ret=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(p[mid]<=aim){
			ret=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ret;
}
struct node{
	int l,r;
};
node e[N];
bool cmp(node a,node b){
	return a.r<b.r;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].d,&s[i].v,&s[i].a);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
		}
		sort(p+1,p+1+m);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i].a==0){
				if(s[i].v>V&&s[i].d<=p[m]){
					cnt++;
					int idx=fid1(s[i].d);
					e[cnt].l=idx;
					e[cnt].r=m;
				}
			}else if(s[i].a>0){
				if(s[i].v>V){
					if(s[i].d>p[m]){
						continue;
					}
					int idx=fid1(s[i].d);
					cnt++;
					e[cnt].l=idx;
					e[cnt].r=m;
					continue;
				}
				int now=(V)*(V)-(s[i].v)*(s[i].v);
				now/=2*s[i].a;
				now++;
				now+=s[i].d;
				if(now>p[m]){
					continue;
				}
				int idx=fid1(now);
				cnt++;
				e[cnt].l=idx;
				e[cnt].r=m;
			}else{
				if(s[i].v<=V){
					continue;
				}
				int now=(V)*(V)-(s[i].v)*(s[i].v);
				now=-now;
				s[i].a=-s[i].a;
				if(now%(2*s[i].a)==0){
					now/=2*s[i].a;
					now--;
				}else{
					now/=2*s[i].a;
				}
				now+=s[i].d;
				if(now<p[1]||s[i].d>p[m]){
					continue;
				}
				int idx=fid2(now);
				int idx2=fid1(s[i].d);
				if(idx!=-1&&idx2!=-1&&idx2<=idx){
					cnt++;
					e[cnt].l=idx2;
					e[cnt].r=idx;
				}
			}
		}
		printf("%d ",cnt);
		if(cnt==0){
			printf("%d\n",m);
			continue;
		}
		sort(e+1,e+1+cnt,cmp);
		int ans=0;
		ans++;
		int now=e[1].r;
		for(int i=2;i<=cnt;i++){
			if(now<e[i].l){
				ans++;
				now=e[i].r;
			}
		}
		printf("%d\n",m-ans);
	}
	return 0;
}
