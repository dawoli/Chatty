#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v;
struct node{
	int d,v,a,r;
	bool c=false;
	bool operator< (const node &c) const{
		return c.d>d;
	}
} a[100001];
//priority_queue<node> pq;
int q[100001],sum;

bool vis[100001];
void solve(){
	memset(vis,0,sizeof(vis));
	memset(q,0,sizeof(q));
	sum=0;
	scanf("%d %d %d %d",&n,&m,&l,&v);
	for(int i=1;i<=n;++i){
		node tmp;
		scanf("%d %d %d",&tmp.d,&tmp.v,&tmp.a);
		long double dd=v*v-tmp.v*tmp.v;
		if(tmp.a>0){
			if(dd/(2*tmp.a)==(long long)dd/(2*tmp.a)&&(long long)ceil(dd/(2*tmp.a))%(2*tmp.a))
				tmp.c=true;
			tmp.r=(dd>0)?(ceil(dd/(2*tmp.a))+tmp.d):-1e6-1;
		}else if(tmp.a<0){
			if(dd/(2*tmp.a)==(long long)dd/(2*tmp.a)&&(long long)floor(dd/(2*tmp.a))%(2*tmp.a))
				tmp.c=true;
			tmp.r=((dd<0)?floor(dd/(2*tmp.a))+tmp.d):-1e6-1;
		}else
			tmp.r=-1e6-1;
		//cout<<tmp.d<<" "<<tmp.a<<" "<<tmp.r<<endl;
		a[i]=tmp;
	}
	for(int i=1;i<=m;++i){
		int tmp;
		scanf("%d",&tmp);
		q[i]=tmp;
		vis[i]=0;
	}
	int sum2=0;
	for(int i=1;i<=n;i++){
		auto tmp=a[i];
		int l1=1,r1=m;
		while(l1<r1){
			int mid=(l1+r1)>>1;
			if(q[mid]>=tmp.d){
				r1=mid;
			}else
				l1=mid+1;
		}
		int r=r1;
		l1=1,r1=m;
		while(l1<r1){
			int mid=(l1+r1+1)>>1;
			if(q[mid]<=tmp.r){
				l1=mid;
			}else{
				r1=mid-1;
			}
		}
		int l=l1,tt=0;
		if(q[r]==tmp.r&&r!=m&&tmp.c)
			r++;
		if(tmp.a>0&&tmp.r>=0){
			
			if(r>=m&&q[r]>=tmp.r){
				vis[r]++;
				sum++;
				tt++;
			}
		}else if(tmp.a<0&&tmp.r>=0){
			if(tmp.r>q[l]){
				vis[l]++;
				sum++;
				tt++;
			}
		}else{
			if(tmp.v>v)
				vis[l]++,sum++,tt++;
		}
		if(tt)
			sum2++;
	}
	int minn=1e6;
	for(int i=1;i<=m;i++){
		minn=min(minn,sum2-vis[i]+1);
	}
	printf("%d %d\n",sum,n-minn);
	
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		solve();
	}
}
