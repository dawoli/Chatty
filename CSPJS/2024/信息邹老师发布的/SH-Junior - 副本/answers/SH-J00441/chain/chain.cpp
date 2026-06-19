#include<bits/stdc++.h>
using namespace std;

int T,n,k,q;

vector<int> wd[200099];
bool dp[109][200099];//dp ij表示在第i回合是可能以j结尾 
int lc[200099]={},nc[200099]={};

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)wd[i]={};

		for(int i=1;i<=n;i++){
			int l;
			cin>>l;
			while(l--){
				int u;
				cin>>u;
				wd[i].push_back(u);
			}
		}
		for(int i=0;i<=103;i++)
		for(int j=0;j<=k+2;j++)dp[i][j]=0;
		dp[0][1]=1;
		for(int i=1;i<=101;i++){//回合
			memset(nc,0,sizeof(nc));
			for(int j=1;j<=n;j++){//小朋友
				for(int l=0;l<wd[j].size();l++)
				for(int r=l;r<wd[j].size();r++){
					int wl=wd[j][l],wr=wd[j][r];
					if(lc[wl]==j)continue;
					if(dp[i-1][wl]==1){
//						cerr<<"dp数组  (round"<<i<<"   child"<<j<<")"<<l<<"~"<<r<<"：  "<<;
						dp[i][wr]=1;
						if(nc[wr]==0){nc[wr]=j;}
						else nc[wr]=-1;
					}
				}
				for(int i=0;i<=200095;i++){lc[i]=nc[i];}
				//cerr<<"nc数组  (round"<<i<<"   child"<<j<<")\n";
				for(int i=1;i<=6;i++){lc[i]=nc[i];/*cerr<<nc[i]<<" ";*/}
				//cerr<<"\n";
			}
			
		}
		//for(int i=1;i<=7;i++){for(int j=1;j<=6;j++){cerr<<dp[i][j]<<" ";}cerr<<"\n";}
		while(q--){
			int v1,v2;
			cin>>v1>>v2;
			cout<<dp[v1][v2]<<"\n";
		}
	}
}
