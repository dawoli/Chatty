#include<bits/stdc++.h>
using namespace std;
int mr(){
	int x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0'; 
		ch=getchar();
	}
	return x*w;
}
#define db double
const int N=1e5+5,M=1e6+6,inf=1e9+9;
int n,m;
db L,V; 
db d[N],v[N],a[N],p[N];
bool vi[N];
struct node{
	db st,en;
	int id;
}dis[N];
bool cmp(node a,node b){
	return a.st<b.st;
}
void solve(){
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++){
		d[i]=mr();
		v[i]=mr();
		a[i]=mr();
		dis[i].id=i;
		if(v[i]>V&&a[i]<0){
			dis[i].st=d[i];
			dis[i].en=min(d[i]+abs((V*V-v[i]*v[i])/2/a[i]),L);
		}
		if(v[i]<=V&&a[i]<=0){
			dis[i].st=L+1;
			dis[i].en=L+1;
		}
		if(v[i]>V&&a[i]>=0){
			dis[i].st=d[i];
			dis[i].en=L+1;
		}
		if(v[i]<=V&&a[i]>0){
			dis[i].st=min(abs((V*V-v[i]*v[i])/2/a[i])+d[i],L);
			dis[i].en=L+1;
		}
	}
	for(int i=1;i<=m;i++){
		p[i]=mr();
	}
	int cnt=0,ans=0,final=1,tot=0;
	sort(dis+1,dis+n+1,cmp);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	for(int i=1,j=1;i<=n;i++){//i枚举起始点，j枚举哪个p 
		int x=dis[i].st,y=dis[i].en;
		tot++;
		q.push({y,dis[i].id});
		while(p[j]<x){//找超速区间第一个摄像头 
			j++;
		}
		while(!q.empty()&&p[j]>q.top().second){//区间末出队 
			if(!vi[i])ans++;	
			for(int i=1;i<=n;i++){
				if(!vi[i]&&dis[i].st<=q.top().second&&dis[i].en>=q.top().second){
					vi[i]=1;
				}
			}
		}
		if(y>p[j]){
			cnt++;
		}
		else{
			dis[i].st=inf;
			dis[i].en=0;
			dis[i].id=0;
		}
	}
	cout<<cnt;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
