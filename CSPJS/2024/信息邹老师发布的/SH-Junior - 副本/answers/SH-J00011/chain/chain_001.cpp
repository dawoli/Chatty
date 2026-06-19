#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n,k,q,t;
int dp[105][N],ans[N],sum[N];
vector<int> g[N];
vector<pair<int,int>> h[N];
struct node{int r,c,num;}op[N];
bool cmp(node a,node b) {
	return a.r<b.r;
}
map<int,pair<int,int>> mp;

int main()  {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--) {
		memset(ans,0,sizeof(ans));
		memset(dp,0,sizeof(dp));
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++) g[i].clear(),h[i].clear();
		int cnt=0;
		for(int i=1;i<=n;i++) {
			int temp;scanf("%d",&temp);
			for(int j=1;j<=temp;j++) {
				sum[i]=sum[i-1]+temp;
				int x;scanf("%d",&x);
				if(x==1) dp[1][cnt+1]=1;
				cnt++;mp[cnt]={i,j};
				g[i].push_back(x);
				h[x].push_back({j,i});
			}
		}
		for(int i=1;i<=q;i++) 
			cin>>op[i].r>>op[i].c,op[i].num=i;
		sort(op+1,op+n+1,cmp);
		for(int i=2;i<=op[q].r;i++) {
			for(int j=1;j<=cnt;j++) {
				int f=g[mp[j].first][mp[j].second-1];
				for(int s=0;s<h[f].size();s++) {
					if(h[f][s].second==mp[j].first) continue;
					for(int m=1;m<=min(k,h[f][s].first-1);m++) {
						int x=h[f][s].second,y=h[f][s].first;
						dp[i][j]=max(dp[i][j],dp[i-1][sum[x-1]+y-m]);
					}
				}
			}
		}
		for(int i=1;i<=q;i++) {
			for(int j=0;j<h[op[i].c].size();j++) {
				for(int s=1;s<k;s++) {
					int f=h[op[i].c][j].first;
					if(f==1) continue;
					int temp=sum[h[op[i].c][j].second-1]+max(0,f-s);
					ans[op[i].num]=max(ans[op[i].num],dp[op[i].r][temp]);
				}
 			} 
		}
		for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
		
	}
	return 0;
}
