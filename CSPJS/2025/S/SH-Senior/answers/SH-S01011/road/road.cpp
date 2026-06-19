#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int dis[N + 15],n,m,k,a[15][N],c[15];
long long ans,tot;
struct node{
	int to,dis;
};
vector<node>edge[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
bitset<N + 15>is;
long long prim(int s)
{
	is.reset();
//	int cnt = 0;
	while(!q.empty())
		q.pop();
	tot = 0;
	for(int i = 1;i <= k;i++) {
		if((s >> i) & 1)
			tot += c[i];
	}
	memset(dis,0x3f,sizeof(dis));
	dis[1] = 0;
	q.push({0,1});
	int p,d;
	while(!q.empty()) {
		p = q.top().second,d = q.top().first;
		q.pop();
		if(dis[p] < d || is[p])
			continue;
//		cout<<p<<endl;
		is[p] = 1;
		tot += dis[p];
//		cnt++;
		if(p <= n) {
//			tot += dis[p];
			for(auto i : edge[p]) {
				if(dis[i.to] > i.dis) {
					dis[i.to] = i.dis;
					q.push({dis[i.to],i.to});
				}
			}
			for(int i = 1,pt;i <= k;i++) {
				if(((s >> i) & 1) == 0)
					continue;
				pt = n + i;
				if(dis[pt] > a[i][p]) {
					dis[pt] = a[i][p];
					q.push({dis[pt],pt});
				}
			}
		} else {
			if(((s >> (p - n)) & 1) == 0)
					continue;
			for(int j = 1;j <= n;j++) {
				if(dis[j] > a[p - n][j]) {
					dis[j] = a[p - n][j];
					q.push({dis[j],j});
				}
			}
		}
	}
//	cout<<cnt<<endl;
	return tot;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1,u,v,w;i <= m;i++) {
		scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}
	bool all_zero = 1;
	for(int i = 1;i <= k;i++) {
		scanf("%d",&c[i]);
		if(c[i])
			all_zero = 0;
		for(int j = 1;j <= n;j++)
			scanf("%d",&a[i][j]);
	}
	ans = 0x7fffffffffffffff;
	if(all_zero){
//		cout<<"YES";
		int i = (1 << k) - 1;
		ans = min(ans,prim(i * 2));
	} else{
		for(int i = 0;i < (1 << (k));i++) {
			ans = min(ans,prim(i * 2));
		}
	}
	printf("%lld\n",ans);
	fclose(stdin),fclose(stdout);
	return 0;
}
