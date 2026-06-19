#include<bits/stdc++.h>
using namespace std;
#define N 100009
int n,x[N],c,ans;
priority_queue<int,vector<int>,greater<int> > pq;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&x[i]);
	sort(x+1,x+n+1);
	pq.push(x[1]);ans=n;
	for(int i=2;i<=n;++i){
		c=pq.top();
		if(c<x[i])--ans,pq.pop();
		pq.push(x[i]);
	}
	printf("%d\n",ans);
	return 0;
}
