#include<bits/stdc++.h>
#define ar2 array<int,2>
#define arr2 array<double,2>
#define ar3 array<int,3>
#define db double 
const int N=1000005,mod=1e9+7,M=1000005;
int bit(int x){
	return 1ll<<x;
}
int lowbit(int x){
	return x&(-x);
}
int add(int x,int y){
	x+=y;
	if(x>=mod)x-=mod;
	return x;
}
int sub(int x,int y){
	x-=y;
	if(x<0)x+=mod;
	return x; 
}
int mul(int x,int y){
	return 1ll*x*y%mod;
}
int powmod(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=mul(ans,x);
		y/=2;
		x=mul(x,x); 
	}
	return ans;
}
using namespace std;
int n,m,L,V,cnt;
double eps=1e-5;
arr2 ed[N];
ar3 q[N];
int p[N],pre[M];
bool cmp(arr2 x,arr2 y){
	return x[1]<y[1];
}
void add(db l,db r,int &sm){
	int p=(int)l,tmp=pre[(int)r];

	if(p==l)tmp-=pre[p-1];
	else tmp-=pre[p];
//	printf("kkk %.2f %.2f %d\n",l,r,tmp);	
	if(tmp)ed[++cnt]={l,r};
	else {
//		puts("?");
		sm--;
	}
}
void solve(){
	scanf("%d%d%d%d",&n,&m,&L,&V);
	cnt=0;
	int now=1,ans=0,sm=n;
	for(int i=1;i<=n;i++){
		int d,v,a;scanf("%d%d%d",&d,&v,&a);
		q[i]={d,v,a};
	}
	for(int i=0;i<=M-5;i++)pre[i]=0;
	for(int i=1;i<=m;i++){
		scanf("%d",&p[i]);
		pre[p[i]]++;
	}
	for(int i=1;i<=M-5;i++)pre[i]+=pre[i-1];
	for(int i=1;i<=n;i++){
		int d=q[i][0],v=q[i][1],a=q[i][2];
		if(a==0){
			if(v<=V)sm--;
			else{
				add(d,L,sm); 
			}
			continue;
		}
		if(v<=V&&a<0){
			sm--;
			continue;
		}
		if(v>V&&a>0){
			add(d,L,sm);
			continue;
		}
		if(v==V&&a>0){
			add(d+eps,L,sm);
			continue;
		}
		if(a>0){
			add(d+1.0*(1.0*V*V-1.0*v*v)/2/a+eps,L,sm);
		}else{
			add(d,d+1.0*(1.0*V*V-1.0*v*v)/2/a-eps,sm); 
		}
	} 
	sort(ed+1,ed+1+cnt,cmp);
	int mx=-1;
	for(int i=1;i<=cnt;i++){
//		printf("%.5f %.5f\n",ed[i][0],ed[i][1]);
		if(mx<ed[i][0]){
			while(now<=m&&p[now]<ed[i][0])now++;
			while(now<m&&p[now+1]<=ed[i][1])now++;
//			printf("ppp %d %d\n",now,p[now]);
			if(now<=m&&p[now]>=ed[i][0]&&p[now]<=ed[i][1]){
				ans++;
				mx=p[now];
			}else{
				sm--;
			}
		}
	}
//	int mx=-1;
//	for(int i=1;i<=m;i++){
//		while(now<=cnt&&ed[now][1]<p[i]){
//			now++;
//			if(ed[now][0]>mx)sm--;
////			puts("WA");
//		}
//		if(now>cnt)break;
//		if(i!=m&&p[i+1]<=ed[now][1])continue;
//		if(ed[now][0]>p[i]){
//			now++;
//			sm--;
//			i--;
//			continue;
//		} 
//		ans++;
//		mx=max(mx,p[i]);
//		while(now<=cnt&&ed[now][0]<=p[i])now++;
//		
//		if(now>cnt)break;
//	}
//	for(int i=now;i<=cnt;i++)if(ed[i][0]>p[m]){
//		sm--;
//	}
//	printf("sm %d\n",m);
	printf("%d %d\n",sm,m-ans);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;cin>>t;
//	t=1;
	while(t--)solve();	
	return 0;
}
