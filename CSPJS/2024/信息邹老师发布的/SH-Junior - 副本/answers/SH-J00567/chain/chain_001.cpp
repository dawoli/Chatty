#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int t,n,k,q;
vector<int> g[N];
bool uio[N];
vector<int> qidian[N];
int hnj[N];

bool subtask(int end,int ear,int now,int step){
	if(step==0){
		return end==now;
	}
	for(auto i:qidian[now]){
		if(i==ear) continue;
		for(int j=0;j<g[i].size();j++){
			if(g[i][j]==now)
			for(int opkl=1;opkl<k;opkl++){
				if(j+opkl>=g[i].size()) break;
				bool re=subtask(end,i,g[i][j+opkl],step-1);
				if(re) return 1;
			}
		}
	}
	return 0;
}

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		memset(uio,0,sizeof(uio));
		for(int i=1;i<=n;i++){
			g[i].clear();
			int l;cin>>l;
			for(int j=1;j<=l;j++){
				int len;
				cin>>len;uio[len]=1;
				if(j!=l&&hnj[len]!=i){
					hnj[len]=i;
					qidian[len].push_back(i);
				}
				g[i].push_back(len);
			}
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			if(!uio[c]) cout<<"0"<<"\n";
			else cout<<subtask(c,0,1,r)<<"\n";
		}
	}
	return 0;
}
