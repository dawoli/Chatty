#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double eps=1e-10;
int t,n,m,l,maxV,p[100005];
struct node{
	int l,r;
}a[100005],b[100005];
int cnt;
bool vis[100005];
void init(){
	cnt=0;
	memset(vis,0,sizeof(vis));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(p,0,sizeof(p));
	maxV=n=m=l=0;
}
bool cmp(node x,node y){
	if(x.r==y.r)return x.l<y.l;
	else return x.r<y.r;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);//t=1;
	while(t--){
		init();
		scanf("%d%d%d%d",&n,&m,&l,&maxV);
//		cout<<n<<" "<<m<<" "<<l<<" "<<maxV<<'\n';
		int _res=0;
		for(int i=1;i<=n;i++){
			int d,v,A;scanf("%d%d%d",&d,&v,&A);
//			if(v>maxV && d<=324762)vis[i]=1,_res++;
			if(A==0){
				if(v>maxV)a[i]=node{d,l};
				else a[i]=node{-1,-1};
			}else if(A>0){
				if(v>maxV)a[i]=node{d,l};
				else{
					double ti=(double)(maxV-v)/A;
					double s=d+A*ti*ti/2+v*ti;
					if(s>l+1){
						a[i]=node{-1,-1};
						continue;
					}
					int _s=ceil(s);
					if(fabs(s-_s)<=eps)a[i]=node{_s+1,l};
					else a[i]=node{_s,l};
				}
			}else{
				if(v<=maxV)a[i]=node{-1,-1};
				else{
					double ti=(double)(v-maxV)/(-A);
					double s=d+A*ti*ti/2+v*ti;
					if(s>l+1){
						a[i]=node{d,l};
						continue;
					}
					int _s=s;
//					cout<<ti<<" "<<s<<" "<<_s<<" "<<fabs(s-_s)<<'\n';
					if(fabs(s-_s)<=eps)a[i]=node{d,_s-1};
					else a[i]=node{d,_s};
				}
			}
		}
//		printf("real answer=%d\n",_res);
		for(int i=1;i<=m;i++)scanf("%d",&p[i]);
//		for(int i=1;i<=n;i++)printf("%d %d\n",a[i].l,a[i].r);
		for(int i=1;i<=n;i++){
			if(a[i].l==-1 && a[i].r==-1)continue;
			int L=1,R=m,rl=m+1,rr=0;
			while(L<=R){
				int mid=(L+R>>1);
				if(p[mid]>=a[i].l)rl=mid,R=mid-1;
				else L=mid+1;
			}
			L=1;R=m;
			while(L<=R){
				int mid=(L+R>>1);
				if(p[mid]<=a[i].r)rr=mid,L=mid+1;
				else R=mid-1;
			}
			if(rl<=rr)b[++cnt]=node{rl,rr};
//			else if(vis[i])printf("!!! %d %d\n",a[i].l,a[i].r);
		}
		printf("%d ",cnt);
		sort(b+1,b+1+cnt,cmp);
//		for(int i=1;i<=cnt;i++)printf("(%d %d)\n",b[i].l,b[i].r);
		int res=0,la=0;
		for(int i=1;i<=cnt;i++){
			if(b[i].l<=la)continue;
			res++;la=b[i].r;
		}
		printf("%d\n",m-res);
	}
	return 0;
}
