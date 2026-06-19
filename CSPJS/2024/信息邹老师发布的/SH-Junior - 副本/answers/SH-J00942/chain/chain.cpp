#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=2e5+5;
const int MAXR=105;
int n,m,q,l[MAXN];
vector<bool> dp[MAXR][MAXN];
vector<int> a[MAXN];
vector<pair<int,int> > vc[MAXN];
vector<int> can[MAXN];
queue<int> qu;
int r[MAXN],c[MAXN];
void solve(){
	int x;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<MAXN;i++){
		vc[i].clear();
	}
	for(int i=1;i<=n;i++){
		a[i].clear();
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&l[i]);
		for(int j=0;j<l[i];j++) {
			scanf("%d",&x);
			a[i].push_back(x);
			vc[x].emplace_back(i,j);
		}
	}
	int lst;
	for(int i=1;i<=n;i++){
		lst=-m;
		dp[1][i].clear();
		for(int j=0;j<l[i];j++){
			if(j-lst+1<=m){
				dp[1][i].push_back(true);
			}else{
				dp[1][i].push_back(false);
			}
//			printf("1 %d %d %d ",i,j,lst);
//			cout<<dp[1][i][j]<<endl; 
			if(a[i][j]==1){
				lst=j;
			}
		}
	}
	for(int i=1;i<MAXN;i++){
		can[i].clear();
	}
	for(int j=1;j<=n;j++){
		for(int k=0;k<l[j];k++){
			if(dp[1][j][k]&&(can[a[j][k]].size()==0||can[a[j][k]].back()!=j)){
				can[a[j][k]].push_back(j);
			}
		}
	}
	int maxr=0;
	for(int i=1;i<=q;i++){
		scanf("%d %d",&r[i],&c[i]);
		maxr=max(maxr,r[i]);
	}
	for(int i=2;i<=maxr;i++){
		for(int j=1;j<=n;j++){
			dp[i][j].clear();
			while(!qu.empty()){
				qu.pop();
			}
			for(int k=0;k<l[j];k++){
				if(!qu.empty()&&k-qu.front()+1>m){
					qu.pop();
				}
				dp[i][j].push_back(!qu.empty());
				if(can[a[j][k]].size()>=2||(can[a[j][k]].size()==1&&can[a[j][k]][0]!=j)){
					qu.push(k);
				}
			}
		}
		for(int i=1;i<MAXN;i++){
			can[i].clear();
		}
		for(int j=1;j<=n;j++){
			for(int k=0;k<l[j];k++){
				if(dp[i][j][k]&&(can[a[j][k]].size()==0||can[a[j][k]].back()!=j)){
					can[a[j][k]].push_back(j);
				}
			}
		}
	}
	bool ans=false;
	for(int i=1;i<=q;i++){
		ans=false;
		for(pair<int,int> j:vc[c[i]]){
//			cout<<"###"<<i.first<<" "<<i.second<<" "<<dp[r][i.first][i.second]<<endl;
			ans|=dp[r[i]][j.first][j.second];
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
/*
1
3 3 7
5 1 2 3 4 1
3 1 2 5
3 5 1 6
1 2
1 4
2 4
3 4
6 6
1 1
7 7
*/
