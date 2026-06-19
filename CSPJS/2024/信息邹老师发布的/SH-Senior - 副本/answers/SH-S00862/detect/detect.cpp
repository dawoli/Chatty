#include<bits/stdc++.h>
using namespace std;
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
#define N 111111
struct Seg{
	int l,r;
	bool operator<(Seg b)const{
		return r>b.r;
	}
	bool operator>(Seg b)const{
		return l<b.l;
	}
};
int t,n,m,l,v0,s[N],v[N],a[N],ans0,ans1,maxx;
int r[N];
vector<Seg>us;
priority_queue<Seg>now;
void init(){
	us.clear();
	ans0=0;
	ans1=0;
	maxx=-1;
}
void work(){
	scanf("%d%d%d%d",&n,&m,&l,&v0);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&s[i],&v[i],&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&r[i]);
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			int s0;
			if(v0<v[i])s0=s[i]-1;
			else if(v0>v[i])s0=s[i]+(v0*v0-v[i]*v[i]-1)/(2*a[i]);
			else s0=s[i]-1;
//			cerr<<s[i]<<' '<<v[i]<<' '<<a[i]<<' '<<s0<<endl;
			if(v[i]*v[i]+2*a[i]*(r[m]-s[i])>v0*v0)++ans0,ans1=1,
				maxx=max(maxx,(int)(upper_bound(r+1,r+1+m,s0)-r));
		}
		if(a[i]==0)
			if(v[i]>v0&&lower_bound(r+1,r+1+m,s[i])!=r+1+m)++ans0,ans1=1,
				maxx=max(maxx,(int)(lower_bound(r+1,r+1+m,s[i])-r));
	}
	if(maxx==-1)maxx=1e9;
	for(int i=1;i<=n;i++)
		if(a[i]<0){
			int s0;
			if(v0>v[i])s0=s[i]-1;
			else if(v0<v[i])s0=s[i]+(v0*v0-v[i]*v[i]+1)/(2*a[i]);
			else s0=s[i]-1;
//			cerr<<20-t<<' '<<i<<' '<<s0<<endl;
			if(upper_bound(r+1,r+1+m,s0)-lower_bound(r+1,r+1+m,s[i])>0){
				++ans0;
				us.push_back({lower_bound(r+1,r+1+m,s[i])-r,upper_bound(r+1,r+1+m,s0)-r-1});
			}
		}
	sort(us.begin(),us.end(),greater<Seg>());
	bool f=0;
	for(auto i:us){
//		cerr<<i.l<<' '<<i.r<<endl;
		now.push(i);
		while(now.size()&&now.top().r<i.l){
			int id=now.top().r;
			if(id<maxx||f)++ans1;else f=1;
			while(now.size()&&now.top().l<=id)
				now.pop();
		}
	}
	while(now.size()){
		int id=now.top().r;
		if(id<maxx||f)++ans1;else f=1;
		while(now.size()&&now.top().l<=id)
			now.pop();
	}
	printf("%d %d\n",ans0,m-ans1);
}
int main(){
	open("detect");
	cin>>t;
	while(t--)
		init(),work();
}
