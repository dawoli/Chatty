#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,k,q;
int l[N];
int b[N];
vector<int>a[N];
int r,c;
bool flag=false;
void dfs(int t,int last,int x){
	if(flag)return;
	if(t>r){
		if(x==c){
			flag=true;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==last)continue;
		for(int j=0;j<a[i].size();j++){
			if(flag)break;
			if(a[i][j]==x)
				for(int o=j+1;o<j+k&&o<a[i].size();o++){
					dfs(t+1,i,a[i][o]);
					if(a[i][o]==x)break;
				}
		}
	}
	return;
}
void solve(){
	int maxn=-2e9;
	memset(b,0,sizeof b);
	cin>>n>>k>>q;
	memset(a,0,sizeof a);
	for(int i=1;i<=n;i++){
		cin>>l[i];
		for(int j=1;j<=l[i];j++){
			int x;cin>>x;
			maxn=max(maxn,x);
			a[i].push_back(x);
			b[x]++;
		}
	}
	while(q--){
		cin>>r>>c;
		if(!b[c]){
			cout<<0<<endl;
			continue;
		}
		if(r==1){
			flag=false;
			for(int i=1;i<=n;i++){
				if(flag)break;
				for(int j=0;j<a[i].size();j++){
					if(flag)break;
					if(a[i][j]==1)
						for(int o=j+1;o<j+k&&o<a[i].size();o++)
							if(a[i][o]==c){
								flag=true;
								break;
							}
				}
			}
			if(flag)cout<<1<<endl;
			else cout<<0<<endl;
			continue;
		}
		//if(r<=5){
			flag=false;
			dfs(1,-1,1);
			if(flag)cout<<1<<endl;
			else cout<<0<<endl;
			continue;
		//}
	}
	return;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
