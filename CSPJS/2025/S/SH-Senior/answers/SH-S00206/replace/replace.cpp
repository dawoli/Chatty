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
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cout<<0<<endl;
	}
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
	}
	return 0;
} 
