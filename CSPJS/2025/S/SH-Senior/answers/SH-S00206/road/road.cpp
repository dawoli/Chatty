#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm> 
#include<queue>
#include<vector>
using namespace std;
long long n,m,k;
const long long N=1e4+5,M=1e6+5;
long long fa[N];
long long r[11][N];
struct edge{
	long long b,c;
	bool operator <(const edge n1)const{
		return n1.c<c;
	} 
};
priority_queue<edge> q;
vector<edge> a[N];
bool vis[N]={};
long long pim(){
//	cout<<1;
	memset(vis,0,sizeof(vis));
	long long ans=0;
	long long cnt=n-1;
	vis[1]=1;
	for(long long i=0;i<a[1].size();i++){
		edge aaa;
		aaa.b=a[1][i].b;
		aaa.c=a[1][i].c;
		q.push(aaa);
	}
	while(q.size()){
		if(cnt==0) break;
		edge ntx=q.top();
		q.pop();
		ans+=ntx.c;
		long long v=ntx.b;
	//	cout<<v<<" "<<ntx.c<<endl;
		vis[v]=1;
		cnt--;
		for(long long i=0;i<a[v].size();i++){
			edge aaa;
			aaa.b=a[v][i].b;
			aaa.c=a[v][i].c;
		
			if(!vis[aaa.b]){
				q.push(aaa);
			} 
		}
	}
	return ans;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long u,v,c;
	for(long long i=1;i<=m;i++){
		cin>>u>>v>>c;
		
		edge ad,ad1;
		ad.b=v;
		ad.c=c;
		ad1.b=u;
		ad1.c=c;
		a[u].push_back(ad);
		a[v].push_back(ad1);
	}
	for(long long i=1;i<=k;i++){
		for(long long j=0;j<=n;j++){
			cin>>r[i][j];
		}
	}
	long long cnt=n-1;
	if(k==0){
		cout<<pim();
	}
	else if(k<=5 && n<=1000){
		long long anss=1e18;
		for(long long i=0;i<=(1<<k)-1;i++){
			long long ansss=0;
	//		cout<<-i<<endl;
			for(long long j=1;j<=k;j++){
				if(i>>(j-1)&1==1){
					ansss+=r[j][0];
					for(long long kk=1;kk<=n;kk++){
						for(long long w=1;w<kk;w++){
							edge ad,ad1;
							ad.b=kk;
							ad.c=r[j][kk]+r[j][w];
						//	cout<<k<<" "<<w<<" "<<r[j][k]+r[j][w]<<endl;
							ad1.b=w;
							ad1.c=r[j][kk]+r[j][w];
							a[w].push_back(ad);
							a[kk].push_back(ad1);
						}
					}
				}
			}
	//		cout<<i<<endl;
			ansss+=pim();
		//	cout<<ansss;
			anss=min(anss,ansss);
			for(long long j=1;j<=k;j++){
				if(i>>(j-1)&1==1){
					for(long long kk=1;kk<=n;kk++){
						for(long long w=1;w<kk;w++){
							a[kk].pop_back();
							a[w].pop_back();
						}
					}
				}
			}
		//	cout<<0<<endl;
		}
		cout<<anss;
	}
	return 0;
} 
