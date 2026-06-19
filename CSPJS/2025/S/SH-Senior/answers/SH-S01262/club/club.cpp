#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n,a1[N],a2[N],a3[N];
long long book[4];
long long maxs;
void dfs(int x,long long s){
	if (x==n+1){
		maxs=max(maxs,s);
		return;
	}
	if (book[1]<n/2){
		book[1]++;
		dfs(x+1,s+a1[x]);
		book[1]--;
	}
	if (book[2]<n/2){
		book[2]++;
		dfs(x+1,s+a2[x]);
		book[2]--;
	}
	if (book[3]<n/2){
		book[3]++;
		dfs(x+1,s+a3[x]);
		book[3]--;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(book,0,sizeof book);
		maxs=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		dfs(1,0);
		cout<<maxs<<"\n";
	}
	return 0;
}
