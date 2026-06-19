#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>,int> PIII;
const int N=200015,M=N*10*2;
int h[N],e[M],ne[M],w[M],idx;
void add(int a,int b,int c){
	e[idx]=b;
	ne[idx]=h[a];
	w[idx]=c;
	h[a]=idx++;
}
int n,K,q;
int a[N];
int cnt[N];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof cnt);
		memset(h,-1,sizeof h);
		idx=0;
		scanf("%d %d %d",&n,&K,&q);
		for(int i=1;i<=n;i++){
			int l;
			scanf("%d",&l);
			for(int j=1;j<=l;j++){
				scanf("%d",&a[j]);
				cnt[a[j]]++;
			}
			for(int j=1;j<=l;j++){
				for(int k=j+1;k<=j+K-1;k++){
					if(k>l)break;
					add(a[j],a[k],i);
				}
			}
		}
		while(q--){
			int x,y,ans=0;
			scanf("%d %d",&x,&y);
			queue<PIII>q;
			q.push({{0,1},0});
			while(!q.empty()){
				PIII t=q.front();
				q.pop();
				if(t.first.first==x&&t.first.second==y){
					ans=1;
					break;
				}
				if(t.first.first>=x)continue;
				for(int i=h[t.first.second];i!=-1;i=ne[i]){
					if(w[i]==t.second)continue;
					int j=e[i];
					if(cnt[j]==1&&t.first.first!=x-1)continue;
					q.push({{t.first.first+1,j},w[i]});
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
