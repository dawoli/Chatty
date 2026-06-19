#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int T,n,k,q,flag,r,c,l,a;
vector<int> s[N];
void dfs(int round, int last, int id){
	if(round==r+1&&last==c){
		flag=1;
	}
	if(flag||round==r+1)return;
	for(int i=0;i<s[id].size();i++){
		if(s[id][i]!=last)continue;
		if(flag)break;
		for(int j=1;j<=n;j++){
			if(flag)break;
			if(j==id)continue;
			for(int length=2;length<=k&&i+length-1<s[id].size();length++){
				if(flag)break;
				dfs(round+1,s[id][i+length-1],j);
			}
		}
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			while(s[i].size()!=0)s[i].pop_back();
		}
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>a;
				s[i].push_back(a);
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			flag=0;
			for(int j=1;j<=n;j++){
				if(flag)break;
				dfs(1,1,j);
			}
			cout<<flag<<endl;
		}
	}
	return 0;
}

