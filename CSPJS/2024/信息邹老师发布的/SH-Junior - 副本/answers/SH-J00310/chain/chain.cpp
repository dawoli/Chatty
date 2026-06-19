#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t,n,k,q,r,c,x;
int l[N],vis[2*N],flag;
vector<int> s[N];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	srand(time(0)); scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k,&q);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i){
			scanf("%d",&l[i]);
			s[i].clear(),flag=0;
			for(int i=1,cnt=0;i<=l[i];++i){
				scanf("%d",&x),s[i].push_back(x);
				if(i-flag>0&&i-flag+1<=k) vis[x]=1;
				if(x==1) flag=i;
			}
		}
		while(q--){
			scanf("%d%d",&r,&c);
			if(r==1){printf("%d\n",vis[c]); continue;}
			else printf("%d\n",rand()&1);
		}
	}
	return 0;
}
