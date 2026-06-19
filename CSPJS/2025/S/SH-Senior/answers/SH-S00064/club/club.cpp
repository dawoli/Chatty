#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

struct s{
	int idx,sc;
}sat[N][4];

bool cmp(s a,s b){
	return a.sc>b.sc;
}

int ans;

void dfs

void solve(){
	bool flag=true;
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=3;++j){
			cin>>sat[i][j].sc;
			sat[i][j].idx=j;
		}
		sort(sat[i]+1,sat[i]+4,cmp);
		if(sat[i][2]!=0||sat[i][3]!=0){
			flag=false;
		}
	}
	if(flag){
		
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
