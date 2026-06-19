#include<bits/stdc++.h>
using namespace std;
void fr(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
}
map<pair<int,int>,int> s;
int l[200005];
int dp[10005][10005];
int n,r,c,k;
bool dfs(int last,int p,int step){
	if(dp[last][p]!=-1)return dp[last][p]<r-step;
	if(step==r+1&&last!=c){
		return 0;
	}
	if(step==r+1&&last==c){
		return 1;
	}
	
	bool ans=0;
	//cout<<1;
	for(int i=0;i<n;i++){
		if(i==p)continue;
		for(int len=2;len<=k;len++){
			for(int ll=0;ll<l[i]-len+1;ll++){
				if(s[make_pair(i,ll)]!=last)continue;
				int r1=ll+len-1;
				ans=(ans||dfs(s[make_pair(i,r1)],i,step+1));
			}
		}
	}
	if(ans)dp[last][p]=step;
	return ans;
}
int main(){
	fr();
	int t;
	cin>>t;
	while(t--){
		int q;
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			int ll;
			cin>>ll;
			l[i]=ll;
			//cout<<l[i]<<endl;
			for(int j=0;j<ll;j++){
				int t;
				cin>>t;
				s[make_pair(i,j)]=t;
				dp[i][j]=-1;
			}
		}
		for(int i=0;i<q;i++){
			cin>>r>>c;
			//t++;
			cout<<dfs(1,-1,1)<<endl;
		}
	}
	return 0;
}
