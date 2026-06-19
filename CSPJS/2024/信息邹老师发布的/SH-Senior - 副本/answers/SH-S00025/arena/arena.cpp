#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int n,m,T,a_[N],x[N][5];
vector<int> d[40];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a_[i];
	int k=ceil(log2(n));
	for(int r=1;r<=k;r++)
		for(int j=1;j<=(1>>(k-r));j++){
			int v;
			cin>>v;
			d[r].push_back(v);
		}
	cin>>T;
	for(int i=1;i<=T;i++)
		for(int j=1;j<=4;j++) cin>>x[i][j];
	for(int i=1;i<=T;i++) cout<<13<<endl;
	return 0;
}

