#include<bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;
int t,n,p,q,ans;
int a[maxn],b[maxn];
int dis[maxn],in[maxn];
vector<pair<int,int> > graph[maxn];
struct node{
	int s,t,val;
}color[maxn];

void init(){
	memset(b,0,sizeof(b));
	memset(dis,0,sizeof(dis));
	memset(in,0,sizeof(in)); 
	for(int i = 1;i <= p;i ++){
		graph[i].clear();
	}
	p = 0;
	ans = 0;
}

void build(){
	for(int i = 1;i <= p;i ++){
		graph[p + 1].push_back(make_pair(i,color[i].val));
		graph[i].push_back(make_pair(p + 2,0));
		in[i] ++;
		in[p + 2] ++;
	}
	for(int i = 1;i <= p;i ++){
		for(int j = i + 1;j <= q;j ++){
			if(color[j].s <= color[i].t)	continue;
			graph[i].push_back(make_pair(j,color[j].val));
			in[j] ++;
		}
	}
}

int toposort(){
	queue<int> que;
	que.push(p + 1);
	while(!que.empty()){
		int i = que.front();
		que.pop();
		for(int j = 0;j < graph[i].size();j ++){
			dis[graph[i][j].first] = max(dis[graph[i][j].first],dis[i] + graph[i][j].second);
			in[graph[i][j].first] --;
			if(in[graph[i][j].first] == 0)	que.push(graph[i][j].first); 
		}
	}
	return dis[q];
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t --){
		init();
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++){
			scanf("%d",&a[i]);
		}
		for(int i = 1;i <= n;i ++){
			for(int j = i + 1;j <= n;j ++){
				if(a[j] == a[i]){
					b[i] = j;
					break;
				}
			}
		}
		for(int i = 1;i <= n;i ++){
			if(b[i] != 0){
				if(b[i] > i + 1)	color[++ p] = (node){i + 1,b[i] - 1,a[i]};
				else if(b[i] == i + 1)	ans += a[i];
			}
		}
		q = p + 2;
		build();
		ans += toposort();
		printf("%d\n",ans); 
	}
	return 0;
}
