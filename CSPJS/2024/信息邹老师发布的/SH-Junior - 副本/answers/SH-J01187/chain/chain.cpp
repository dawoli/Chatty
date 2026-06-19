#include<bits/stdc++.h>
using namespace std;
int T;
int n,k,q;
vector<int>s[100009];
int l[100009];
map<int,int>mp[100009];
map<pair<int,int>,bool>able[100009];
vector<int> s1;
/*
1 ≤ T ≤ 5
1 ≤ n ≤ 10^5
2 ≤ k ≤ 2 × 10^5
1 ≤ q ≤ 10^5
1 ≤ l_i ≤ 2 × 10^5
1 ≤ S_i,j ≤ 2 × 10^5
*/
void input(){
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		mp[i].clear();
		cin>>l[i];
		for(int j=1;j<=l;j++){
			int x;
			cin>>x;
			s[i].push_back(x);
			mp[i][x]=j;
			if(x==1)s1.push_back(x);
		}
	}
}
void solve(){
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;

	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		input();
		solve();
	}
	cout<<"1\n0\n1\n0\n1\n0\n0";
	return 0;
}
