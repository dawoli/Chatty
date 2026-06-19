#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long u;
	long long v;
	long long w;
};
bool cmp(edge a,edge b){
	return a.w<b.w;
}
vector<edge>e;
vector<edge>f;
long long fa[10050];
long long siz[10050];
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
long long cnt=0;
long long ans=0;
long long eu=0,ev=0;
long long kru(long long n){
		for(auto ee:e){
			eu=find(ee.u),ev=find(ee.v);
			if(eu!=ev){
				cnt++;
				
				ans+=ee.w;
			if(siz[eu]<siz[ev])swap(eu,ev);
			siz[eu]+=siz[ev];
				fa[ev]=eu;
				if(cnt==n-1){
					return ans;
					
				}
			}
		}
		return ans;
	
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,temp=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)siz[i]=1;
	long long u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	long long c=0;
	long long a[10050];
	sort(e.begin(),e.end(),cmp);
	long long sum=kru(n);
	if(k==0){
		cout<<sum<<endl;
		return 0;
	}
	long long flag=0;
	for(int i=1;i<=k;i++){
		cin>>c;
		f=e;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		if(a[j]==0)flag++;
		}
		if(c==0&&flag==n){
			cout<<"0";
			return 0;
		}
		flag=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				e.push_back({i,j,a[i]+a[j]});
			}
		}
		sort(e.begin(),e.end(),cmp);
		cnt=0;
		ans=0;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=n;i++)siz[i]=1;
		temp=c+kru(n);
		sum=min(sum,temp);
		e=f;
	}
	cout<<sum;
	return 0;
}
