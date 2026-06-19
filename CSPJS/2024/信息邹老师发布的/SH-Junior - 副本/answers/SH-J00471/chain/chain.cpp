#include<bits/stdc++.h>
using namespace std;

constexpr int N=2e5+7;

int n,k,q,l[N],r[N],c[N];
vector<int> s[N];

struct node{
	int step,p,val;
	//step people value
};

bool bfs(int lim,int goal){
	queue<node> q;
	q.push({0,0,1});
	while(q.size()){
		node state=q.front();q.pop();
		int step=state.step,p=state.p,val=state.val;
		if(step==lim&&val==goal)return 1;
		if(step==lim)continue;
		for(int i=1;i<=n;++i){
			if(i==p)continue;
			for(int j=0;j<s[i].size();++j){
				if(s[i][j]==val){
					for(int p=j+1;p<s[i].size()&&p<j+k;++p){
						q.push({step+1,i,s[i][p]});
					}
				}
			}
		}
	}
	return 0;
}

void solveB(){
	for(int i=1;i<=q;++i){
		cout<<bfs(r[i],c[i])<<'\n';
	}
}

void solve(){
	bool flagA=1,flagB=1,flagC=1;
	cin>>n>>k>>q;
	if(k>5)flagC=0;
	if(n>10)flagB=0;
	for(int i=1,x;i<=n;++i){
		cin>>l[i];
		if(l[i]>20)flagB=0;
		for(int j=1;j<=l[i];++j){
			cin>>x;
			s[i].push_back(x);
		}
	}
	if(q>100)flagB=0;
	for(int i=1;i<=q;++i){
		cin>>r[i]>>c[i];
		if(r[i]!=1)flagA=0;
		if(r[i]>5)flagB=0;
	}
	if(flagA){
		map<int,bool> ans;
		for(int pre,i=1;i<=n;++i){
			pre=-1;
			for(int j=0;j<s[i].size();++j){
				if(pre!=-1&&(j-pre+1)<=k)ans[s[i][j]]=1;
				if(s[i][j]==1)pre=j;
			}
		}
		for(int i=1;i<=q;++i){
			cout<<ans[c[i]]<<'\n';
		}
		return;
	}
	else{
		solveB();
	}
}

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int tc;cin>>tc;
	while(tc--){
		solve();
	}
}
