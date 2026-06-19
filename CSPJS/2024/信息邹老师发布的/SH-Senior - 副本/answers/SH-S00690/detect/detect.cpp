#include<bits/stdc++.h>
#define L 1000009
#define N 100009
#define INF 0x3f3f3f3f
#define pii pair<int,int>
using namespace std;
int T,n,m,l,v,ans1,ans2,p[N],q[L];
int c[L];
inline int lowbit(int x){return x&(-x);}
void add(int x){
	for(x++;x<=(l+1);x+=lowbit(x)){
		c[x]++;
	}
}
pii x[N];
int query(int x){
	int ret=0;
	for(x++;x;x-=lowbit(x))ret+=c[x];
	return ret;
}
bool cmp(pii a,pii b){
	return a.second<b.second||(a.second==b.second&&a.first<b.first);
}
void solve(){
	ans1=ans2=0;
	memset(q,0,sizeof(q));
	memset(c,0,sizeof(c));
	cin>>n>>m>>l>>v;
	for(int i=1;i<=n;i++){
		int d,a,v0;
		cin>>d>>v0>>a;
		if(a==0){
			if(v0>v)x[i]=make_pair(d,l),++ans1;
			else x[i]=make_pair(INF,INF);
		}
		else if(a>0){
			if(v0>v){x[i]=make_pair(d,l);++ans1;continue;}
			int tmp=d+(v*v-v0*v0)/(a<<1)+1;
			if(tmp>l) x[i]=make_pair(INF,INF);
			else x[i]=make_pair(tmp,l),++ans1;
		}
		else if(a<0){
			if(v0<=v){x[i]=make_pair(INF,INF); continue;}
			int tmp=min(d+(v0*v0-v*v-1)/(-a*2),l);
			x[i]=make_pair(d,tmp);++ans1;
		}
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=m;i++){
		cin>>p[i];
		q[p[i]]=1;
	}
	for(int i=1;i<=l;i++)q[i]+=q[i-1];
	for(int i=1;i<=ans1;i++){
		if(x[i].first==0&&(!q[x[i].second])){
			x[i]=make_pair(INF,INF);++ans2;
		}
		else if(!(q[x[i].first-1]^q[x[i].second])){
			x[i]=make_pair(INF,INF);++ans2;
		}
	}
	ans1-=ans2;ans2=0;
	if(!ans1){
		printf("0 %d\n",m);return;
	}
//	for(int i=1;i<=ans1;i++)printf("%d %d\n",x[i].first,x[i].second);
	sort(x+1,x+n+1,cmp);
	for(int i=1;i<=ans1;i++){
		if(query(x[i].second)^query(x[i].first-1)) continue;
		++ans2;
		int tmp=lower_bound(q+x[i].first,q+x[i].second+1,q[x[i].second])-q;
		add(tmp);
	}
	printf("%d %d\n",ans1,m-ans2);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
