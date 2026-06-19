#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,ans,maxn;
pair<int,int> p[4];
struct node{
	int a,b,c,d;
}ver[N];
bool cmp1(pair<int,int> a,pair<int,int> b){return a.first>b.first;}
vector<int> v[4];
bool cmp2(int a,int b){return ver[a].a-ver[a].c<ver[b].a-ver[b].c;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		v[1].clear();v[2].clear();v[3].clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
            scanf("%d%d%d",&p[1].first,&p[2].first,&p[3].first);
			p[1].second=1,p[2].second=2,p[3].second=3;
			sort(p+1,p+4,cmp1);
			ver[i]=(node){p[1].first,p[1].second,p[2].first,p[2].second};
            v[p[1].second].push_back(i);
			ans+=p[1].first;
		}
		if(v[1].size()>n/2) maxn=1;
		else if(v[2].size()>n/2) maxn=2;
		else if(v[3].size()>n/2) maxn=3;
		else{
			printf("%d\n",ans);
			continue;
		}
		sort(v[maxn].begin(),v[maxn].end(),cmp2);
		for(int i=0;i<v[maxn].size()-n/2;i++) ans-=ver[v[maxn][i]].a-ver[v[maxn][i]].c;
		printf("%d\n",ans);
	}
	return 0;
}
